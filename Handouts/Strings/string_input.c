// Getting string input
// DSM, 2016

#include <stdio.h>

// Two ways to read strings from the console:
//   1. Value-based: read individual strings, delimited by whitespace (scanf)
//   2. Line-based: read a whole line at a time (fgets)

int main() {
    
    // Create a buffer to hold input
    char buf[16];
    
    // Use scanf with %s designator
    printf("Enter a string: ");
    scanf("%s", buf);
    printf("You entered: %s", buf);
    
    // Problem: scanf stops on whitespace and doesn't read the terminating \n
    // Result: the newline is still hanging out in the input buffer, waiting
    // to be read by the next operation
    //
    // This is okay if you only use scanf, but causes problems if you mix
    // scanf with line-oriented input functions
    
    // Use gets to read a line
    // WARNING: THIS IS FOR DEMONSTRATION ONLY! DON'T ACUTALLY DO THIS!
    // WE'LL TALK ABOUT WHY IN CLASS!
    printf("Type a word: ");
    gets(buf);
    printf("You typed: %s\n", buf);
    
    // Issues:
    // 1. How large should the buffer be? No way to know in advance.
    // 2. What if user types more characters than buffer has space?
    
    // Recall: C does not check for out-of-bounds array accesses
    // scanf does not check that the input fits into the target array
    
    // Too much input can lead to a **buffer overrun**
    
    // Solution: fgets lets you specify the max number of characters to read
    // It truncates the string to the specified length, using one byte for
    // the terminating null byte
    printf("Type a word: ");
    fgets(buf, sizeof(buf), stdin);
    printf("You typed: %s", buf);  // fgets includes the terminating newline
    
    return 0;
}