# More Strings

## Due Wednesday, 10/12

## You can work with a partner to complete this assignment

## Overview

## Benford's Law

### How to do better white collar crimes

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/46/Rozklad_benforda.svg/1920px-Rozklad_benforda.svg.png" width="40%" />

Benford's Law is one of the all-time great "I can't believe this is a thing" results. It states that, in many real-world quantitative data sets, **1 is by  far the most common leading digit**. Specifically, slightly more than 30% of the numbers in the data set should start with a leading 1.  About 17% of data values should start with 2, and about 13% start with 3. Leading 9's occur less than 5% of the time.

This is surprising, because you might expect the distribution of leading digits to be uniform; that is, about 11% of data values should start with a 1, another 11% with 2, and so forth, with 1's and 9's being equally common.

The law is named after physicist Frank Benford, who called it *The Law of Anomalous Numbers* in a 1938 paper. Benford's Law has applications to fraud detection and accounting. Criminals faking financial data are unlikely to make their numbers correspond with the true probtabilities made by the law. *Facilitating white collar crime is not one of the learning outcomes of this course*.

Suppose that the data you're considering consists of counts of items of interest, such as votes, sales figures, defective items, etc. If you've counted 100 items, you would need to double that figure to increase to the next leading digit, a proportional increase of 100%. To move from a count of 200 to 300, you still need to count 100 more items, but that's only a 50% proportional increase. If you've counted 900 items, you only need to increase the count by about 11\%, to get to 1000. This is an intuitive explanation for Benford's Law: the proportional increase required to raise a number to the next leading digit is largest when the leading digit is small. Benford's Law doesn't apply to every data set. It tends to be most applicable when the data values are not naturally restricted to a range and span multiple orders of magnitude.

You're going to write a program to validate Benford's Law against a real-world data set. We're going to work with a set of county-level population estimates produced by the U.S. Census Bureau. This project will let you practice

- Opening and reading from a file in C
- Working with comma-separated value (CSV) files
- Using the `strtok` function and more string manipuations

### Get the data

The 2020-2021 county-level population estimates are availble on the Census Bureau's web site:

https://www.census.gov/data/tables/time-series/demo/popest/2020s-counties-total.html

Download the file named `co-est2021-alldata.csv` and then upload it to your Assignment 3 repl.it workspace. If you open the file, you'll see a series of lines link the following:

```
SUMLEV,REGION,DIVISION,STATE,COUNTY,STNAME,CTYNAME,ESTIMATESBASE2020,POPESTIMATE2020,POPESTIMATE2021
040,3,6,01,000,Alabama,Alabama,5024279,5024803,5039877
050,3,6,01,001,Alabama,Autauga County,58805,58877,59095
050,3,6,01,003,Alabama,Baldwin County,231767,233140,239294
050,3,6,01,005,Alabama,Barbour County,25223,25180,24964
050,3,6,01,007,Alabama,Bibb County,22293,22223,22477
```

The first line lists the names of each field. The data is organized alphabetically by state, then by county within each state. The first line of data is the population for the entire state of Alabama, followed by the estimate for Autauga county, and so forth. The first entries on each line include some numerical encodings used by the census bureau to identify each county (notice that the entire state has a `COUNTY` code of `000`). Individual fields are separated by commas with no spaces. If you've worked with Excel, you may have used CSV files to encode spreadsheet data in text format: each line corresponds to one row in the spreadsheet and each comma-separated value to a column within the row.

### Reading the file

The following program opens the file and prints its lines. Use it as your starting point for the rest of the project.

```
/**
 * Validating Benford's Law for Census data
 */

#include <stdio.h>
#include <stdlib.h>

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

You need to read the **tenth value** on each line, which represents the 2021 population estimate. You could do this by calling `strtok` ten consecutive times, but that's bogus. A better approach, which you will do, is to call `strtok` one time to get the first token (with `buf` as its input), then write a loop that runs nine more times to get up to the tenth token.

Start by extracting and printing the tenth value and make sure that you have the right number.

Once you've verified that your token extraction is correct, you need to extract the first digit. This is easy:

```
// Get the first digit
char firstDigit = *token;
```

You need to keep track of two things:

- The total number of lines that you process.
- The number of occurrences of each leading digit. Use an array called `int counts[10]` to record how many times each digit appears.

Tip: remember that the `firstDigit` value given above is a `char`. You'll need to map it to an `int` if you want to use it as an array index. Look at the `atoi` function.

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

## Bitwise operators


## Command line inputs

