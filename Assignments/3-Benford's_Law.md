# How to Commit Better White Collar Crimes

<img src="https://imgs.xkcd.com/comics/insurance_2x.png" width="60%" />

## Due Wednesday, 10/27

## You can work with a partner to complete this assignment

## Overview

This project will give you a chance to continue working with strings, input, and built-in functions in C. We're going to complete two short projects based around **Benford's Law**, a nifty result that governs the distribution of digits in many quantitative data sets.

- First, validating the Law against real-world Census data. This project will require reading values from a file.
- Second, writing a program that can generate randomized integers that obey Benford's Law. This project will allow you to practice working with command line inputs and random numbers.

If you choose, you can work with a partner to complete this assignment.

- You should each make your own individual submissions on repl.it. That is, you can write your code together, but have each person enter it in their own workspace and submit, so I have a record of everyone completing the project.
- Put your name and your partner's name in your files.

Submit your work using the Assignment 3 workspace on repl.it. As with the other projects, include a `Makefile` to build your code from source.

## The Most Important Tip

The key to this project is **developing incrementally**. These programs are not *that* hard or long, but there is a lot to understand and integrate. Focus on building up your solution one step at a time, testing as you go. You never want to move more than one step ahead without verifying that what you've written is working correctly. Don't be afraid to print values in order to see what your program is doing.

## Benford's Law

### Description

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/46/Rozklad_benforda.svg/1920px-Rozklad_benforda.svg.png" width="40%" />

Benford's Law is one of the all-time great "I can't believe this is a thing" results. It states that, in many real-world quantitative data sets, **1 is by  far the most common leading digit**. Specifically, slightly more than 30% of the numbers in the data set should start with a leading 1.  About 17% of data values should start with 2, and about 13% start with 3. Leading 9's occur less than 5% of the time.

A full description of the Law and the associated probabilities is given in the [Wikipedia article](https://en.wikipedia.org/wiki/Benford%27s_law).

This is surprising, because you might expect the distribution of leading digits to be uniform; that is, about 11% of data values should start with a 1, another 11% with 2, and so forth, with 1's and 9's being equally common.

The law is named after physicist Frank Benford, who called it *The Law of Anomalous Numbers* in a 1938 paper. Benford's Law has applications to fraud detection and accounting. Criminals faking financial data are unlikely to make their numbers correspond with the true probabilities made by the law.

**Facilitating white collar crime is not one of the learning outcomes of this course**.

Suppose that the data you're considering consists of counts of items of interest, such as votes, sales figures, defective items, etc. If you've counted 100 items, you would need to double that figure to increase to the next leading digit, a proportional increase of 100%. To move from a count of 200 to 300, you still need to count 100 more items, but that's only a 50% proportional increase. If you've counted 900 items, you only need to increase the count by about 11\%, to get to 1000. This is an intuitive explanation for Benford's Law: the proportional increase required to raise a number to the next leading digit is largest when the leading digit is small. Benford's Law doesn't apply to every data set. It tends to be most applicable when the data values are not naturally restricted to a range and span multiple orders of magnitude.

You're going to write a program to validate Benford's Law against a real-world data set. We're going to work with a set of county-level population estimates produced by the U.S. Census Bureau. This project will let you practice

- Opening and reading from a file in C
- Working with comma-separated value (CSV) files
- Using the `strtok` function and more string manipuations

### Get the data

The 2020-2021 county-level population estimates are availble on the Census Bureau's web site:

https://www.census.gov/data/tables/time-series/demo/popest/2020s-counties-total.html

Download the file named `co-est2022-alldata.csv` near the bottom of the page and then upload it to your Assignment 3 repl.it workspace. If you open the file, you'll see a series of lines link the following:

```
SUMLEV,REGION,DIVISION,STATE,COUNTY,STNAME,CTYNAME,ESTIMATESBASE2020,POPESTIMATE2020,POPESTIMATE2021, POPESTIMATE2022
040,3,6,01,000,Alabama,Alabama,5024356,5031362,5049846,5074296
050,3,6,01,001,Alabama,Autauga County,58802,58902,59210,59759
050,3,6,01,003,Alabama,Baldwin County,231761,233219,239361,246435
050,3,6,01,005,Alabama,Barbour County,25224,24960,24539,24706
050,3,6,01,007,Alabama,Bibb County,22300,22183,22370,22005
```

The first line lists the names of each field. The data is organized alphabetically by state, then by county within each state. The first line of data is the population for the entire state of Alabama, followed by the estimate for Autauga county, and so forth. The first entries on each line are some numerical encodings used by the census bureau to identify each county (notice that the entire state has a `COUNTY` code of `000`). Individual fields are separated by commas with no spaces. If you've worked with Excel, you may have used CSV files to encode spreadsheet data in text format: each line corresponds to one row in the spreadsheet and each comma-separated value to a column within the row.

### Reading the file

The following program opens the file and prints its lines. Use it as your starting point for the rest of the project.

```
/**
 * Validating Benford's Law for Census data
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Open the file
  FILE *f = fopen("co-est2021-alldata.csv", "r");

  // Check the return code
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // Declare character buffer
  char buf[1024];

  int firstLine = 1;
  
  // Loop over the remaining lines that have data
  while (fgets(buf, sizeof(buf), f) != NULL) {

    // Skip the first line that contains the field names
    if (firstLine) {
      firstLine = 0;
      continue;
    }

    // Print the line
    printf("%s", buf);
  }
  
}
```

The first line uses `fopen` to open the file in reading mode.

```
FILE *f = fopen("co-est2021-alldata.csv", "r");
```

`fopen` returns a pointer of type `FILE *` that serves as a reference to the open file. The next lines check the value of `f` to make sure the open succeeded and exit if it failed.

The next lines use `fgets` to read from the file. The main loop repeatedly calls `fgets` to put the next line of text into the character buffer, `buf`.

```
while (fgets(buf, sizeof(buf), f) != NULL) {
```

`fgets` returns `NULL` when it reaches the end of the file or if an error occurs, so this loop runs until every line has been read. The first line contains the field names, which are not data, so the loop includes a small statement to skip processing the first line.


### `strtok`

`strtok` is the string tokenizing function. It's similar to Java's `Scanner`, in that it can separate a string into individual tokens based on a delimiting pattern. In this case, we want to use `strtok` to break each line of data (which contains information on one U.S. county) into its comma-separated parts, then extract the relevant population value.

Here's the basic example. Put the following lines inside the `while` loop after the `printf` statement.

```
// Use strtok to get the first value
char *token;
token = strtok(buf, ",");
printf("%s\n", token);
```

`strtok` takes the string buffer and the delimiter pattern as inputs and returns a pointer of type `char *` that represents the first token in the line. At this point, run the program and verify that you can extract and print the first value on each line.

To continue retrieving more tokens from the same line, call `strtok` again with `NULL` as the first input:

```
// Get the second token -- strtok keep processing the same string if its 
// first input is NULL
token = strtok(NULL, ",");
printf("%s\n", token);
```

Add these lines after the code that reads and prints the first token, then verify that you can run the program and extract and print the first two values on each line.

### Data

You need to read the **eleventh value** on each line, which represents the 2022 population estimate. You could do this by calling `strtok` eleven consecutive times, but that's bogus. A better approach, which you will do, is to call `strtok` one time to get the first token (with `buf` as its input), then write a loop that runs ten more times to get up to the eleventh token.

Start by extracting and printing the eleventh value and make sure that you have the right number.

Once you've verified that your token extraction is correct, you need to extract the first digit. This is easy:

```
// Get the first digit
char firstDigit = *token;
```

You need to keep track of two things:

- The total number of lines that you process.
- The number of occurrences of each leading digit. Use an array called `int counts[10]` to record how many times each digit appears.

Tip: remember that the `firstDigit` value given above is a `char`. You'll need to map it to an `int` if you want to use it as an array index. The easiest way to do this is with character arithmetic:

```
int value = firstDigit - '0';
```

### Output

After you process the entire file, print out the fraction of occurrences for each leading digit. You should see that the estimates your program produces are very close to the values that would be predicted by Benford's Law. Your results should be close to the following:

```
Fraction of leading 0's = 0.0000
Fraction of leading 1's = 0.3037
Fraction of leading 2's = 0.1825
Fraction of leading 3's = 0.1227
Fraction of leading 4's = 0.0914
Fraction of leading 5's = 0.0786
Fraction of leading 6's = 0.0639
Fraction of leading 7's = 0.0554
Fraction of leading 8's = 0.0532
Fraction of leading 9's = 0.0485
```

## Command line inputs

Suppose (*just for the sake of argument*) that I've decided to, maybe, commit a <sub>tiny</sub> amount of fraud. I need to generate some plausible data that appears to follow the distribution of Benford's Law to make my fraud look legitimate.

Let's write a program that can geneate Benford-esque data values. This project will feature:

- Command line inputs
- Processing input arguments using `getopt`
- Working with random values in C

### Arguments

Recall that the two input values to `main`, `argc` and `argv`, are used to process command line arguments.

- `argc` records the **number** of arguments.
- `argv` is an array of strings (type `char *[]`), each of which records one argument supplied on the command line.

The simplest thing you can do with command line argument is print them out:

```
for (int i = 0; i < argc; i++) {
  printf("%s\n", argv[i]);
}
```

If you haven't done so yet, write a up a short program that uses that loop. If you run your program with several inputs, you should see the program echo them back out. For example, if your program is named `args`, you could generate the following output.

```
./args one two three four
./args
one
two
three
four
```

By convention, `argv[0]` is always the name of the program.

### Options

What you ultimately care about, though, is using arguments to control the execution of the program. There is a built-in function called `getopt` that can be used to perform basic command line options processing. It is, however, a bit inscrutable. Here's a starting example:

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // Process arguments with getopt

  int nSet = 0;
  int dSet = 0;
  int vSet = 0;

  // Process arguments with getopt
  int c;
  while ((c = getopt(argc, argv, "ndv")) != -1) {
    switch (c) {
      case 'n':
        nSet = 1;
        break;
      case 'd':
        dSet = 1;
        break;
      case 'v':
        vSet = 1;
        break;
    } 
  }

  printf("n = %d    d = %d    v = %d\n", nSet, dSet, vSet);
}
```

`getopt` takes three arguments. The first two are `argc` and `argv`. The third is a string that specifies the command line flags that `getopt` should process. The basic `getopt` flag is a dash followed by a character. For example, the string "n" tells `getopt` to look for a command line flag `-n`.

If a program takes multiple command line flags, they can all be combined into one string. In this case, the string "ndv" would tell `getopt` to look for flags `-n`, `-d`, and `-v`. The flags can be supplied in any order.

The body of the loop uses a `switch` statement. Review how that works if you need to. Remember that each `case` statement needs to end with a `break` for the `switch` to execute correctly.

Code up this program, then run it with different combinations of the `n`, `d`, and `v` flags at the command line:

```
./args -n

./args -n -d -v

./args -v -n

./args -d -n

./args
```

Verify that in each case, the values of `nSet`, `dSet`, and `vSet` match the flags that are supplied on the command line.

Flags can also take optional parameters. In `getopt`, adding a `:` after a letter specifies that flag takes an additional parameter. For example,
the string `n:` indicates a flag `-n` that takes a further parameter. Here's another program that takes one input with a parameter:

```
int main(int argc, char *argv[]) {

  int numValues = 0;
  int numDigits = 10;

  // Process arguments with getopt
  int c;
  while ((c = getopt(argc, argv, "n:")) != -1) {
    switch (c) {
      case 'n':
        numValues = atoi(optarg);
        break;
    } 
  }
}
```

Run the program like the following:

```
./args -n 10
```

You can verify (by adding a print statement) that the command above would set `numValues` to 10.

### Finish the generator

Your goal is to write a program that takes two command line inputs:

- `-n` specifiying the number of random values to output
- `-d` specifying the number of digits in each value

For each of random number, generate the first digit according to the distribution predicted by Benford's Law and the other digits uniformly at random. For example, if you run the program with the following inputs:

```
./benfordGenerator -n 100 -d 6
```

It should output 100 six-digit numbers. Here's a basic framework for doing so:

```
for (int n = 0; n < numValues; n++) {
  int result = benfordDigit();
  
  for (int d = 0; d < numDigits - 1; d++) {
    result = result * 10 + uniformDigit();
  }
  
  printf("%d\n", result

}
```

Here, `numValues` represents the parameter specified from the `-n` flag, `numDigits` is the parameter specified for the `-d` flag, and `benfordDigit()` and `uniformDigit()` are functions that return `int` values according to those distributions.

### Plan

- Start by implementing the program given above that reads the `-n` flag and sets `numValues`.
- Modify that program to also read a `-d` flag and set `numDigits`. Tip: make the `getopt` string `"n:d:"`.
- Verify that you can correctly get the parameters from the command line.
- Implement the basic number generation loop. To start, make `benfordDigit` and `uniformDigit` return fixed values. Verify that you can generate the correct number of values with the correct number of digits.
- Work on implementing the digit-generating functions.

To generate random `int` values, you need to use the `rand` function, which returns a value between 0 and the built-in system `RAND_MAX`. You can generate a random `double` value between 0 and 1 using the following:

```
double r = ((double) rand()) / RAND_MAX;
```

You can combine this with a conditional statement to choose the correct digit according to the Benford distribution:

```
if (r < .3010) {  // A little bit more than 30% of values are 1's
  return 1;
} else if (r < .4770) { // An additional 17.6% are 2's
  return 2;
}

// Add more cases for the other numbers
```

Review the Wikipedia article for the distribution values.

## Overall Tips

These problems are *that* hard, but they require you to integrate a lot of information. **Develop incrementally**! Make small changes, test each one, and then add the next feature. **Don't try to build the entire program and then test it**! There are too many things that can go wrong.

When you get compiler errors, always start with the top-most one, fix it, and then recompile. Read the output messages carefully.

As always: **Start early**! Don't wait until the last minute!
