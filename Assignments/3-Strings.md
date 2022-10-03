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

## Bitwise operators


## Command line inputs

