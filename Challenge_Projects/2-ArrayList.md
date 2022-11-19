# Challenge Project 2: Implementing `ArrayList`

## Due Friday, December 2 (the last day of classes)

## You can work with a partner to complete this project

## Overview

This project asks you to complete a C implementation of an `ArrayList` data structure. It will let you practice:

- Working with `struct` and pointers to `struct` values
- Allocating memory with `malloc` and releasing it with `free`
- Re-implementing a standard Java data structure in C

All of the code you need is in `main.c` in the repl.it workspace. The `main` function contains a series of tests that will use the methods defined
in the source file. Complete each method so that you can pass the tests (you'll want to comment out the later tests until you can pass the earlier ones).

## Structs vs. Objects

A C `struct` is a group of related variables allocated together as a single unit. In that sense, it's *like* an object that groups related variables together
under one name, but C structs can't contain methods and they don't have any ability to enforce encapsulation (struct fields can't be `private`).

Start by reading Dr. Summet's notes on 

- [Basic `struct`s in C](https://github.com/dansmyers/ComputerOrganizationAndArchitecture/blob/master/Notes/08a-C_structs.md)
- [Using pointers to `struct`s and `malloc`](https://github.com/dansmyers/ComputerOrganizationAndArchitecture/blob/master/Notes/08a-C_structs.md)

Make sure you can answer the following questions before proceeding:

- What is a `typedef`?
- What is the meaning of the `->` operator when applied to a pointer to a `struct`. For example, `book->author`?
- What do `malloc` and `free` do?
- What does the Java garbage collector do for you?

## Implementing an `ArrayList`

Recall that `ArrayList` implements a list (that is, a resizable ordered sequence of values) using an array as the backing storage. All `ArrayList` methods
store data in a 1-D array, but hide the complexity of automatically resizing the array when adding or removing new values from the user.

In C, we're going to use a `struct` to represent the `ArrayList`. Here's the declaration:

```
typedef struct {
  int* array;
  int size;  // Number of inserted elements
  int capacity;  // Size of allocated array
} ArrayList;
```

`ArrayList` is now the alias for a `struct` with three fields. The most important is `array`, which is a pointer to the actual backing data array. The 
other two fields keep track of sizes: `size` is the number of elements that have been inserted into the array (which is initially 0) and `capacity` is
the size of `array`. Note that `size <= capacity` at all times in a correct `ArrayList`, because you can't add an item if there isn't space in the 
array to hold it.

All C data structure methods take a pointer to the data structure and operate on it. For example, `main.c` gives you an implementation of the `arrayListPrint`
method, which prints the contents of a list:

```
/**
 * Print the contents of an ArrayList
 */
void arrayListPrint(ArrayList *a) {
  printf("[");
  for (int i = 0; i < a->size; i++) {
    printf("%d", a->array[i]);
    if (i < a->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}
```

Take a look at this method and verify how it works. Pay attention to the way in which the list's fields are accessed using `->` notation.

Finally, let's take a look at the "constructor" function, which allocates space for a new `ArrayList` and returns a pointer to the allocated region:

```
/**
 * Construct a new ArrayList and return
 * a pointer to it
 */
ArrayList* arrayListInit() {
  
  // Allocate a struct for the new list
  ArrayList* newList = malloc(sizeof(ArrayList));

  // Check the return from malloc
  if (newList == NULL) {
    perror("arrayListInit");
  }

  // Initialize the struct's fields
  newList->array = malloc(INITIAL_CAPACITY * sizeof(int));
  newList->size = 0;
  newList->capacity = INITIAL_CAPACITY;

  // Return the pointer to the new list
  return newList;
}
```

The first line uses `malloc` to allocate one `ArrayList` `struct`'s worth of memory. Specifically, it's allocating enough memory for a pointer and
two `int` values, which is 16 bytes if pointers are 8 bytes and ints are 4 each.

The next lines check the return value from `malloc`. It's unlikely, but `malloc` could fail and return a null pointer.

Allocating memory for the backing array requires another call to `malloc`:

```
  newList->array = malloc(INITIAL_CAPACITY * sizeof(int));
```

Remember that `malloc` allocates **bytes**, so the input to the method is the **total number of bytes** required for the initial number of `int`s. The last 
lines set the starting values of `size` and `capacity`.

## Your Job

Complete the rest of the `ArrayList` methods in the project file so that you can pass the tests in `main`. The most important one is `arrayListAppend`, which adds a new value
to the end of the given list:

```

/**
 * Append a value to the end of the array list
 */
void arrayListAppend(ArrayList *a, int value) {
  
  // If the array is full, allocate a new array and
  // copy the elements over to it
  if (a->size == a->capacity) {
    // Allocate a new array that holds
    // 2 * a->capacity * sizeof(int) bytes
    
    // Copy the values from the old array to the new array

    // Free the old array

    // Set a->array to point to the new array
  
    }

  // Put the new value in the next position in a->array
  // Tip: if you're keeping track correctly, the next
  // free position is always a->array[a->size]

  // Increment a->size

}
```

Recall that appending to an ArrayList requires checking if the current backing array is full. If it is, allocate a new larger array, then copy the
values from the current array to the new array. Because we're doing this in C, you must also **free** the old array; otherwise, you'll create a **memory
leak** bug.

You'll also need to write methods to insert and remove elements. Create your tests at the end of `main` to test your code and verify that it works
correctly.

## Tips

- Make sure you understand the notes before starting.

- Work on one test at a time. Comment out the ones you don't need while you're working on the earlier tests.

- Review Java's `ArrayList` if it's helpful.
