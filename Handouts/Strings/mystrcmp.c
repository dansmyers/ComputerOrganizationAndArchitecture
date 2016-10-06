// Compare two strings
// DSM, 2016

#include <stdio.h>

// Reimplementation of strcmp from the standard library


//*** Compares two strings ***//
//
// Inputs: two null-terminated strings, s and t
//
// Returns:
//   a NEGATIVE value is s comes before t
//   a POSITIVE value if s comes after t
//   ZERO if they are equal
int mystrcmp(char *s, char *t) {
    
    int i;
    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }
    
    return s[i] - t[i];
}


//*** A fancier version of strcmp using pointer operations ***//
//
// Questions:
//   what is the effect of s++ and t++?
//   when does the loop terminate?
int myfancystrcmp(char *s, char *t) {
    for( ; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    
    return *s - *t;
}


int main () {
    printf("%d\n", mystrcmp("apple", "zebra"));
    printf("%d\n", mystrcmp("zebra", "apple"));
    printf("%d\n", mystrcmp("apple", "apple"));
    
    printf("%d\n", mystrcmp("Zebra", "apple"));
    printf("%d\n", mystrcmp("apple", "applique"));
    printf("%d\n", mystrcmp("apple", "apples"));

    return 0;
}