# Characters and Text

## Overview

Read [this article](http://www.joelonsoftware.com/articles/Unicode.html) by Joel Spolsky for a concise overview of text encodings and the basics of Unicode. It covers all the important points we made in class, plus a few more interesting facts on the evolution of text representation.

## Duality

An important take-away from the overview article is the relationship (which I'm calling "duality") between a character and its associated numeric code. For example, the ASCII value of `'A'` is 65 or 41 in hex. Therefore, these values are equivalent:

```
char charA = 'A';
char intA = 65;
char hexA = 0x41;

// Each value prints the same thing
printf("%c    %c    %c\n", charA, intA, hexA);
```
