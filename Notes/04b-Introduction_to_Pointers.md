# Introduction to Pointers

## What is a Pointer?

A pointer is a variable that stores the memory address of a variable.

*A pointer is a variable that stores the memory address of a variable*.

**A pointer is a variable that stores the memory address of a variable**.

Pointers are a powerful and, in some cases, dangerous, feature of C. Many operations in C programs can only be carried out using pointers.

## Declaring and Assignint to Pointers

To create a pointer, use a `*` in the variable declaration, as follows:

```
int *p;
double *q;
char *s;
```

Pointers are **typed**: `p` is declared to be a pointer to `int` and it can't point to any other type.

The compiler actually ignores whitespace, so the following are also acceptable declarations:

```
int* p;
int * p;
```

I personally like the `int* p` form, because it treats `int*` as a "pointer to `int`" type, but `int *p` is the traditional and most common form.

Use the `&` operator to assign a memory address to a pointer.

```
int x = 101;
int *p = &x;  // p now points to x
```

If we were to draw a memory diagram showing this setup, we would have something like the following.

```
   ----------------
x: |  value of x  | <---
   |     (101)    |    |
   ----------------    | 
p: |    memory    |    |
   | address of x |----- 
   |              |
   ----------------
```

The arrow indicates that `p` "points to" the location in memory where `x`'s value begins.

The size of `p` is the number of bytes required to store a memory address: 8 bytes on a 64-bit system.

## Dereferencing a Pointer

The basic operation on pointers is `*`, which retrieves **the value pointed to by the pointer**. I usually think of this as the "that which is pointed to by" operation.

```
*p = that which is pointed to by p
```

This is also referred to as **dereferencing** the pointer.

In the example above,`p` has been set to point to `x`, so `*p` would retrive the value of `x`. You can use `*p` anywhere you would use `x`, including in expressions.

```
printf("*p = %d\n", *p);  // prints 101
int y = *p + 10;  // y becomes 111
```

You can also use `*p` on the left side of assignment. This form is equivalent to assigning to the underlying variable `x`.

```
*p = 202;  // Equivalent to x = 202
printf("x = %d\n", x);  // Prints 202
```

## Example: Swapping Two Variables

Here's a classic example of something that you can do with pointers that can't be done without them.

Suppose you want to write a fucntion that swaps the values of its two input variables. You might initially try something like this:

```
void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 1;
  int y = 2;
  
  swap(x, y);
  printf("x = %d    y = %d\n", x, y);
  
  return 0;
}
```

If you run this, however, you'll get

```
x = 1    y = 2
```

The values in `main` remain unchanged! What happened?

Well, to understand the issue, you need to know a little about argument passing in C. When you call a function like `swap`, **copies** of the input values are passed and assigned to the variables `a` and `b`. Therefore, swapping the values of `a` and `b` only exchanges the values of the **copies**. The original values of `x` and `y` in `main` remain unaffected.

When we pass arguments to functions by copying their values, we say that the system is using a **pass by value** approach.

The alternative is to **pass by reference**. Here's an example of `swap` that works the pointers to the true underlying memory locations where `x` and `y` are stored.

```
void swap (int *aPtr, int *bPtr) {
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

int main() {
  int x = 1;
  int y = 2;
  
  swap(&x, &y);
  printf("x = %d    y = %d\n", x, y);
  
  return 0;
}
```

This version of `swap` words, because the pointers allow us to directly access and manipulate the memory locations where the values of `x` and `y` are stored. Therefore, assigning to `*aPtr` in this example causes a change that's reflected in the value of `x` in `main`, not simply a change in a copy of `x`'s value.

## Segmentation Faults

Unfortunately, a lot of things can go wrong with pointers. Here's the first example.

```
int *p;
printf("That which is pointed to by p = %d\n", *p);
```

If you code those fragment into a program (or run the example in the Handouts directory), you'll get

```
Segmentation fault
```

What's the problem? The statement `int *p`, by itself, **declares** a pointer named `p`, **but does not assign it to point to anything**. In most cases, `p` will have a default value of `0`.

An uniitialized pointer is called a **null pointer**. Attempting to dereference a null pointer results in a segmentation fault and program termination because memory address 0 is always considered off-limits to user programs.

If you know that you need to declare a pointer but not assign it right away, you can give it a default value of `NULL` to make it clear that the pointer has no valid initial value and can't be dereferenced without first making a valid assignment.

```
int *p = NULL;
```

Unlike in Java, `NULL` is not a special value: it's just another name for 0.

## Next

It turns out that there is a close and interesting relationship between pointers and arrays. We'll talk about this symmetry and some of the things you can do with it.
