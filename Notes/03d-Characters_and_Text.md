# Characters and Text

## Overview

Read [this article](http://www.joelonsoftware.com/articles/Unicode.html) by Joel Spolsky for a concise overview of text encodings and the basics of Unicode. It covers all the important points we made in class, plus a few more interesting facts on the evolution of text representation.

## Duality

An important take-away from the overview article is the relationship (which I'm calling "duality") between a character and its associated numeric code. For example, the ASCII value of `'A'` is decimal 65, which is 41 in hex. 

```
char charA = 'A';
char intA = 65;
char hexA = 0x41;

// Print the character A three times
printf("%c    %c    %c\n", charA, intA, hexA);
```

In some cases, you need an awareness of a character's underlying numeric code. For example, character comparisons are based on the underlying ASCII codes. Therefore, `'Z'` (0x5A) comes before `'a'` (0x61) and `'['` (0x5B) comes before `'{'` (0x7D). This has implications when sorting strings: all capital letters come before all lowercase letters.

The code for `'A'` is decimal 65 (0x41) and `'a'` is 97 (0x61). Adding 32 converts an uppercase letter to its lowercase counterpart:

```
#define UPPPER_TO_LOWER_SHIFT 32

char upper = 'Z';
char lower = upper + UPPER_TO_LOWER_SHIFT;

printf("%c\n", lower);
```
