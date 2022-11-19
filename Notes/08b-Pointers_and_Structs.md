# Pointers and Structs

## Review
First, remember how to define a `struct` and wrap it in a `typedef` for easy use:

```
typedef struct student_struct {
   char* name;
   int grad_year;
   double gpa;
} student;
```

We can then declare variables of type `student` and use them:

```
   student student1;

   strcpy(student1.name, "Ima Student");
   student1.grad_year = 2020; 
   student1.gpa = 3.45;
```

## Right Arrow Notation
However, this usage of a `typedef`ed `struct` isn't common.  Instead we usually want a pointer to a `struct`.  We can then use that pointer in many situations.  For example, we can pass the pointer to a function which can then dereference that pointer and modify the struct's data in some way.  Consider the following function:

```
void modify_gpa(student* s) {
  int new_gpa = //calculations here;
  *s.gpa = new_gpa;    //CAREFUL!  Is this really what we want?
}
```

But wait!  We need to be careful about our order of operations.  We need to do two things: dereference the pointer (`*s`) and access the member data `gpa` with dot notation.  There's a big difference between `(*s).gpa` and `*(s.gpa)`.  Walk yourself through each of these expressions and think carefully about what they mean!

It's obvious that we want `(*s).gpa`.  But it turns out that the member operation (the dot) has a high priority.  So if we just write `*s.gpa` without any parentheses (as we did in the function above), we won't get the desired behavior.  Instead, we will probably get a seg fault and our program will crash.  Because we often want to use these two operators -- dereference and member access/dot notation -- together, there is a shortcut operator which does both in the correct order: the right arrow notation, `->`.  So usage in our function would look like:

```
void modify_gpa(student* s) {
  int new_gpa = //calculations here;
  s->gpa = new_gpa;   //much cleaner!
}
```

Notice how our right arrow has taken the place of two operators.  Right arrow notation can only be used on pointers to `structs`.

## Memory Management
But how do we get a pointer to a struct?  First, we need to take a slight digression into memory management.  First, review the diagram of the *Canonical Address Space* located in our (https://github.com/vsummet/cms230notes/blob/master/c-programming/c-chap04-memory.md)[Memory Structure] note.  Go ahead, I'll wait.  Keep that diagram in your mind.

Next, we need to observe another crucial difference between Java and C: Java manages memory for you.  When you use the `new` operator in Java, several things happen:

1. Java allocates space in the heap (remember the diagram!) for the data you need.
2. The `new` is followed by a call to the constructor to initialize the object you just created.
3. Java returns a **reference variable** (that is, a variable which stores a reference/address) to the object in memory.

When you are done using the object (for example, it goes out of scope), Java handles de-allocating the memory and returning it to the heap for later re-use.  This process is called **garbage collection**.  This model of memory management was a selling point of Java when it was introduced since **the programmer must manage memory allocation and de-allocation in C (and C++).**

Again: **the programmer must manage memory allocation and de-allocation in C (and C++).**  That means the programmer must get the address of a specific number of bytes of memory (from the heap) when they need to allocate a variable and the programmer must de-allocate ("free up") the memory when they are done using it (before it goes out of scope).

In order to do this, we need to learn about two functions for memory management in C: `malloc` and `free`.  These memory management functions are found in `<stdlib.h>`.

### `malloc`: Memory Allocation
`malloc` takes a single argument: the number of bytes of memory to allocate from the heap and returns a pointer to the first byte of that memory. Technically, the return type of `malloc` is `void *`, a generic pointer. This is automatically promoted to the more specific type on the left-hand side, so a cast isn't required.  Rather than supply a hard-coded number of bytes to `malloc`, it's easier to use our old friend, `sizeof` which will do the calculation for us.  Consider the following code:

```
student* s = malloc(sizeof(student));
```
Notice that `s` is a pointer to a student.  The argument that we pass to `malloc` is the integer value returned from `sizeof`.  

However, be aware that `malloc` **does not** initialize the member variables of the student `struct` for us!  Trying to use member variables before we have initalized them will lead to strange behavior.  We will then need to follow the call to `malloc` with code to initialize the member variables:

```
strcopy(s->name, "Ima Student");
s->grad_year = 2020;
s->gpa = 3.45;
```

Now, the memory has been allocated and the values have been initialized.  We can use the variable `s` (and its associated memory) as long as we need to.

### `free`: Memory De-allocation
Unlike Java, C does not have a garbage collector. There is no way to automatically reclaim allocated memory once it's no longer needed. Instead C programmers must use a call to the `free` function to return the memory back to the system.  The `free` function takes a pointer as an argument.  The memory referred to by the pointer will then be returned to the heap for later re-use.

```
student* s = malloc(sizeof(student));

// Do some work with s

// Goodnight, sweet prince.
free(s);
```

There are three major bugs associated with `free`.

* Continually allocating memory without ever freeing it results in a **memory leak**. Eventually, the system will run out of avaialable heap memory and your program will crash. This is typically not a problem in small programs, but can be an issue for long running systems 
that might, say, repeatedly add and remove from data structures.
* Trying to use a pointer after calling free on it:
```
free(s);
printf("Year: %d\n", s->grad_year); 
```
This often leads to a segmentation fault (program crash) or other unexplained behavior
* Freeing the same pointer twice results in a **double free**. This confuses the memory allocator and can cause all kinds of unpredictable bugs.


## Up Next
Consider the following usage: we want to make an array of students to represent a class roster.  What would this look like using our student `struct` and what we've learned about memory management?  We would need to consider an array of pointers, and that's what we'll talk about next.
