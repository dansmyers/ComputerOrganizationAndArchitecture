# Memory and Addresses

## What is a Variable?

Every variable in a program corresponds to **location in memory** where the value associated with that variable is stored.

For example, when you declare

```
int x;
```

in a program, that declaration is associated with a region of memory large enough to hold one `int`; the name `x`is associated with this memory region.

```
    ---------------
    |              |
    |              |
    |--------------|  
x:  |  value of x  |  <--| enough space for
    |              |  <--| one int (probably 4 bytes)
    |--------------|  
    |              |
    |              |
    ----------------
```

Therefore, there are two ways to refer to the value of variable `x`.

  - by **name**, using `x`
  - by **address**, by specifying the location in memory where `x`'s value is stored
  
This is kind of like junk mail that comes to your house. You sometimes get mail addressed to you specifically, by name. Other times, you get mail addressed to "The Current Occupant" (or some similar phrase) living at your street address.

## The Canonical Address Space

Recall that a C program's view of memory is, conceptually, a **big array of bytes**. This address space (AS) is divided into three logical regions, each used for storing different types of data. The number of bytes in the AS depends on the number of bits the system uses for a memory address, which determines how memory bytes are addressable.

```
A canonical 32-bit address space

-----------------------------  Byte index 0
|    Code and static data   |
|                           |
----------------------------- 
|           Heap            |
|  (dynamically-allocated)  |
|                           |
-----------------------------
|             |             |
|             |             | Heap grows and shrinks as data is dynamically allocated
|             v             | and freed by the program (new  and garbage collection in
|                           | Java, malloc and free in C).
|     Unallocated space     |         
|                           |
|             ^             | Stack grows and shrinks as the program calls and returns
|             |             | from functions.
|             |             |
-----------------------------
|           Stack           |
|                           |
|   (local variables and    |
|  function call history)   |
|                           |
-----------------------------  Byte index 2^32 - 1
```

¥ou may recall that this nice big array of bytes abstraction is really an illusion maintained by the OS and the hardware through the magic of **virtual memory**. In reality, all programs running on your computer at any moment are sharing a limited amount of real physical RAM. The VM system makes it possible for each program to have the *illusion* of its own large private address space.

## Variable Addresses

The `&` operator retrieves the address of a variable.

```
int x;
printf("Address of x = %p\n", &x);  // %p is the format specifier for a memory address
```

Running this program will print something similar to

```
Address of x = 0x7ffea4d876a4
```

The long hex string represents the **memory location** where `x`'s value is stored.

Suppose we have a global variable in a C program. Global variables are those declared outside of any function, and are accessible to all functions defined in the same source file.

```
int g;

int main() {
    printf("Address of global variable g = %p\n", &g);
    return 0;
}
```

This prints

```
Address of global variable g = 0x601044
```

How to explain the difference in the two addresses? If `x` is a local variable, allocated inside `main`, it should reside in the stack portion of the AS, at a high-valued memory address. `g`, as a global variable, is actually placed in the heap region, closer to the beginning of the address space.

## Using Memory Addresses with `scanf`

Here's another example of using memory addresses. `scanf` is a formatted input function. It's like the input analogue of printf, in that it reads input from the console according to a specified format string.

```
#include <stdio.h>

int main() {
    int value;

    // Basic example: read a single integer
    printf("Enter an integer: ");
    scanf("%d", &value);  // &value is the memory location of the variable value
    printf("You entered %d.\n", value);
    
    return 0;
}
```

The call to `scanf` takes two arguments.
  
  - A format string specifying the type of data to read. In this case, `"%d"` indicates reading a single integer.
  - A *memory location* where the value should be stored. In this case, this is the address associated with the variable `value`.
  
You can think of `scanf`'s second argument as specifying the *target or destination* for the read operation.

Take a look at the `scanf` handout for more examples.

## Next

Now that we've established that variables have addresses in memory, we'll introduce the concept of a *pointer*: a variable that stores the memory address of a variable.
 
