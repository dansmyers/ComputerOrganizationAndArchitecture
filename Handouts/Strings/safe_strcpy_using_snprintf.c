// Copying a string safely using snprintf
// DSM, 2016

#include <stdio.h>

// Recall that strcpy could cause problems if the destination buffer is not
// large enough to hold the source string. In this case, strcpy will
// *overflow* the destination and overwrite the contents of memory beyond the
// allocated destination space.

// Therefore, strcpy SHOULD NOT BE USED.

// There are three main ways to deal with string copying
//
// 1. strncpy, which is slightly better, but still bad
// 2. strlcpy, which is great, but unfortunately non-standard
// 3. snprintf, which is standard and works

// strncpy is *like* a bounded-length version of strcpy
//
//     strncpy(char *dest, char *source, int maxBytesToCopy)
//
// Weirdly, and despite its name, strncpy was not actually created to work with
// strings, but rather fixed length directory fields in the original UNIX OS.
// Therefore, strncpy doesn't actually treat its inputs *as strings*. In
// particular, it doesn't guarantee that the results of the copy operation
// will be null-terminated.
//
// A non-null-terminated string is no string at all and is a *time bomb* just
// waiting to blow up in your code.

int main() {
    char source[] = "Hello, world!";
    char dest[14]; // Buffer large enough to hold source plus a null byte
    
    // snprintf works like printf, but puts the result in a string
    // The second argument specifies the max number of bytes to copy, including
    // the null terminator, which is automatically appended to the result
    snprintf(dest, sizeof(dest), "%s", source);
    
    printf("Result of copy = %s\n", dest);
    
    return 0;
}