# Strings


## Definition and Declaration

**A C string is a null-terminated character array**.

The following declarations are equivalent.

```
char tokyo[] = "Tokyo";
char kyoto[] = {'K', 'y', 'o', 't', 'o', '\0'};
```

The `'\0'` character is a typical representation for the null byte `0x00`. The null byte marks the end of the string. The system automatically appends a terminating `\0` to strings declared with quotes.

Notice, also, that the size of the array doesn't have to be declared if the compiler can infer it from the initial assignment.

Individual letters of the string can be accessed like any other array element.

```
tokyo[0] is 'T'
*tokyo is also 'T'

tokyo[1] is 'o'
*(tokyo + 1) is also 'o'
```

## Pointers to Characters

Because of the symmetry between pointers and arrays, it's common to use a `char *` to refer to a string.

```
char *s = tokyo;
printf("%s", *s);  // prints 'T'
```

It's possible to declare a pointer to a static (unmodifiable) string using

```
char *msg  = "Hello, World!";
```

## Example String Functions

We looked at several examples in class that are in the Handouts directory.

Here's one example, which copies a string from the location `src` to the location `dest`. It illustrates a common string pattern: looping over the characters of a string until encountering the null terminator. The program is based on one in Kernighan and Ritchie's book *The C Programming Language* (K & R).

```
//*** Copies a string to another location ***//
//
// Reimplementation of strcpy from <string.h>
//
// Inputs: two null-terminated strings, dest and source
//   assumes that dest is large enough to hold all of source
//   could this lead to problems?
//
// Returns: Nothing, changes are made to the underlying string buffers
void mystrcpy(char *dest, char *src) {
    int i = 0;
    while ((dest[i] = source[i]) != '\0') {
        i++;
    }
}
```

## DANGER WILL ROBINSON

Consider the following fragment that makes use of `mystrcpy`.

```
char city[] = "Yokohama";
char buf[4];

mystrcpy(buf, city);
```

What happends when `mystrcpy` attempts to copy `"Yokohama"`, which is 9 bytes long (including the null terminating byte) into `buf`, which is only four bytes long?

The first iteration of the loop copies `'Y`' into the first position of `buf`.

```
         buf
  -----------------
  |               |
  v               v
  -----------------
  | Y |   |   |   |
  -----------------
```

The second, third, and fourth iterations copy the next three letters into the remaining three locations of `buf`.

```
         buf
  -----------------
  |               |
  v               v
  -----------------
  | Y | o | k | o |
  -----------------
```

What happens next? Well, `mystrcpy` has still not reached the terminating null byte of `"Yokohama"`, so it must continue to copy characters.

**C does not perform bounds-checking on array accesses** so these additional writes will go **beyond the allcoated space** for `buf` and overwrite any values stored in those memory locations.

```
         buf
  -----------------
  |               |
  v               v
  --------------------------------------
  | Y | o | k | o | h | a | m | a | \0 |
  --------------------------------------
                  ^                    ^
                  |                    |
                  ----------------------
                        overwritten!
```

This type of bug is called a **buffer overflow**. It is **one of the most serious kinds of bugs** that can affect your programs.

The consequences of a buffer overflow can range from nonexistent to catastrophic. In the best case, the overwritten memory was unused and the program continues to execute as if nothing unusual happened. In an intermediate case, you might overwrite the value of some variable, or attempt to write to an unallocoated region, causing a segmentation fault.

In the worst case, malicious hackers can exploit buffer overflows to launch a **stack-smashing attack** on a system, which can result in tricking the system into executing **arbitary code**.

A safe way to copy strings is with the `snprintf` function. There is an example in the Handouts directory.

## String Input

An old-style function for retrieving string input is `gets`.

```
char buf[8];

printf("Type something: ");
gets(buf);
printf("You typed: %s\n", buf);
```

If you wrap this fragment in `main` and compile it, you'll get a message 

```
warning: the `gets' function is dangerous and should not be used.
```

Hmmm. Well, I like to live dangerously. Let's burn this candle!

```
Type something: ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
You typed: ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
*** stack smashing detected ***: ./string_input terminated
Aborted
```

`gets` doesn't check that its target buffer is large enough to hold all of its input! Therefore, it's vulnerable to buffer overruns, just like the `strcpy` example above. `gets` is kind of worse, though, because it's allowing a user to **directly input** anything they want into a buffer, with no checking or sanitization.

If you know only two things about security, they might as well be these two:

  1. Don't roll your own crypto
  2. Don't process user input without sanitizing, validiating, or checking it first
  
In this case, the system has actually added a defensive check against stack-smashing, which catches the buffer overflow and terminates the program just to be safe.

A safer input function is `fgets`, which allows you to specify the length of the input buffer.

```
fgets(buf, sizeof(buf), stdin);
```

Check the Handouts for examples of how to use `sizeof` with arrays.

## Next

