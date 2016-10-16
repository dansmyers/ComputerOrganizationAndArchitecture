# Arrays of Pointers

## Multidimensional Arrays

Consider the following declaration for a 2-D array.

```
int a[3][3] = {{1, 2, 3},
               {4, 5, 6},
               {7, 8, 9}};
```

This declaration creates a true two-dimensional array in memory by allocating enough space to hold 9 `int` values, then storing the 9 vaues in row order. As with 1-D arrays, the name `a` labels the beginning of this block of memory.

```
   -------
a: |  1  |
   ------- 
   |  2  |
   -------  
   |  3  |
   -------
   |  4  |
   -------
   |  5  |
   ------- 
   |  6  |
   -------  
   |  7  |
   -------
   |  8  |
   -------
   |  9  |
   -------
```

Accessing an element such as `a[1][2]` is equivalent to `*(a + 1 * 3 + 2)`.

## An Array of Pointers

Now consider the following declaration. What does it create?

```
int *m[3];
```

`m` is an array with three elements, but each element has type `int *`. In other words, `m` is **an array of pointers**.

Conceptually, each entry of `m` points to another location in memory, which can be thought of as the beginning of a 1-D array.

```
   -------          -----------------
m: |  ---|--------> |   |   |   |   |
   -------          -----------------
   |  ---|--------> |   |   |   |   |
   -------          -----------------
   |  ---|--------> |   |   |   |   |
   -------          -----------------
```

Note that the declaration of `m` creates the 3-element array, but **it does not assign any references to the individual pointer elements**.  `malloc` can be used to allocate memory to the 1-D subarrays.

```
m[0] = malloc(3 * sizeof(int));
m[0] = malloc(4 * sizeof(int));
m[0] = malloc(5 * sizeof(int))
```

It's possible, as in this example, to create a "ragged array," where the 1-D subarrays all have different lengths. This is not common with integer arrays, but is very useful when working with string arrays. More on that below.

## Double Pointers

A pointer is a variable that stores the memory location of a variable, so it's possible to create a **pointer to a pointer**.  A double pointer uses two stars to indicate that it's at two levels of indirection from the underlying data.

```
int **dblPtr = m;
```

Here, `m` is an array of `int *`, so the name `m` functions like a pointer to the first element of the array, which has type `int *`.

`dblPtr` can access elements of the underlying 1-D subarrays using square bracket notation.

```
dblPtr[1][2] is equivalent to m[1][2]
```

## Arrays of Strings

Consider the following declaration for an array containing the names of all the months.

```
char *months[] = {"January", "February", "March", "April", "May", "June",
                   "July", "August", "September", "October", "November",
                   "December"};
```

`months` is an array where element has type `char *`. In other words, it is an **array of strings**.

In this case, the ability to create multidimensional arrays with different row lenghths is useful, because it allows each month name to be stored in its own array. There's no need to pad short names like `"May"` to match the length of longer names like `September`.

Because of the symmetry between arrays and pointers, it's also possible to use a double pointer type to refer to a string array.

```
char **ptrToStrArray = months;
```

Now, the indvidual strings may be accessed using square brack notation.

```
ptrToStrArray[0]
```

Notice that this example only uses a single index to select the string. Using a pair of brackets, as in the `int` example of the previous section, would select an individual letter within a string.

## Command Line Arguments


