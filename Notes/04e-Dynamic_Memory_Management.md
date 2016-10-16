# Dynamic Memory Management

## Memory Allocation

Sometimes you need to allocate memory to a dynamic object. For example,

  - Returning an array from a function (see the example below)
  - Creating new nodes in a linked list, tree, or other data structure
  
`malloc` allows you to request a specified amount of **heap memory** from the system.

```
// Allocate space for 1024 ints
int *p = malloc(1024 * sizeof(int));
```

The input argument to `malloc` is the number of bytes you'd like to allocate. The return value is a pointer to the beginning of the allocated region.

Technically, the return type of `malloc` is `void *`, a **generic pointer**. This is automatically promoted to the more specific type on the left-hand size, so a cast isn't required.

`malloc` and its related functions are declared in `<stdlib.h>`.


## Example: Returning an Array

Here's one common use of  `malloc`'ed memory: allocating space for data structures that need to persist beyond the function scope where they're created.

Suppose you want to write a function that initializes a random array. You might try something like this.

```
int * initRandArray(int n) {
    int a[n];
    
    int i;
    for (i = 0; i < n; i++) {
        // Fill a[i] with a random value
    }
    
    return a;
}
```

This function has a serious problem: `a` is a **local variable** and it will be **deallocated** when the function exits. Therefore, the memory associated with `a` will not be maintained by the system: it might be reused again for something else. Relying on a pointer to a local variable is **unreliable** and the compiler will tell you so.

A better solution is to use `malloc` to create a dynamically-allocated array on the heap. This array will persist until it's either freed or the program ends.

```
int *a = malloc(n * sizeof(int));
```

## If You Love Some Memory, Set It Free

Unlike Java, C does not have a garbage collector. There is no way to automatically reclaim allocated memory once it's no longer needed. Instead C programmers must use the `free` call to return the memory back to the system.

```
char *s = malloc(1024 * sizeof(char));

// Do some work with s

// Goodnight, sweet prince.
free(s);
```

There are two major bugs associated with `free`.

  1. Continually allocating memory without ever freeing it results in a **memory leak**. Eventually, the system will run out of avaialable heap memory and your program will crash. This is typically not a problem in small programs, but can be an issue for long running systems that might, say, repeatedly add and remove from data structures.
  
  2. Freeing the same pointer twice results in a **double free**. This confuses the memory allocator and can cause all kinds of unpredictable bugs.
  
## Next

We'll do more with memory allocation when we talke about `struct`s and implementing data structures in C. The next major topic for these notes is working with arrays of pointers.
