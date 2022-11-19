# Data Structures in C - `struct`s

## A Review
In Java, you've worked extensively with objects.  In fact, everything in Java is an object.  You can't get away from them!  As a reminder, objects are containers which group data and behaviors into a single entity.  The data takes the form of variables while the behaviors take the form of methods.  Because the central concept of computation in Java is an object, we say that Java is an *object oriented programming* (OOP) language.

## Moving on
In contrast, C is a *procedural programming* language.  It is built around functions (or procedures).  The structure of a C program derives from a series of function calls.  It turns out, C has a mechanism for grouping **data** together into a single unit for easy reference.  But this grouping cannot contain methods, making it fundamentally different from the concept of objects in an OOP language such as Java or C++ (both successors of C).  In C, this grouping is called a `struct` (short for structure).  Let's write a `struct` to mimic a book which contains a title, author, and a number of pages:

```
struct book {
   char  title[50];
   char  author[50];
   int   pages;
};
```

## Details
Let's dive in an look at the pieces of the `struct`.  First we see the line:
```
struct book {
```
This defines the template for a `struct` and gives it a unique name, `book`.  Just like in Java classes, we use `{ ... }` to indicate what data is contained in a `struct book`.

The next 3 lines specify what type of data each `struct` will contain (eg what defines a book):
```
   char  title[50];
   char  author[50];
   int   pages;
```
In this case, we see that we've defined an array of 50 characters (a string) to hold the title, another array of 50 characters to hold the author, and an integer to represent the number of pages in the book. 

A really subtle point: notice there is a semicolon after the struct's closing `}`.  The definition of a `struct` is a single statement (even though we write it on multiple lines) and thus needs a semicolon at the end.  Don't leave this out!  It's an easy mistake to make.

## Using a `struct book`
Let's look at some code to use our newly defined struct:

```
#include <stdio.h>
#include <string.h>
 
struct book {
   char  title[50];
   char  author[50];
   int   pages;
};
 
int main( ) {
   struct book book1;        /* Declare book1 of type struct book */
 
   /* book 1 specification */
   strcpy(book1.title, "The Hobbit" );
   strcpy(book1.author, "J.R.R. Tolkien" ); 
   book1.pages = 285;
   
   /* print Book1 info */
   printf("Book 1 title: %s\n", book1.title);
   printf("Book 1 author: %s\n", book1.author);
   printf("Book 1 pages: %d\n", book1.pages);
   
   return EXIT_SUCCESS;
}
```

Let's notice a few things about this code:
1. We had to declare the variable as the type `struct book`, not just `book`.  This is because structs are an incomplete data type.  We not only have to tell the C compiler that the variable references a `struct`, but we also have to include which specific struct definition it references, in this case the `book` struct.
2. We have to use the **member operator**, `.`, to gain access to any member variables of the struct.  Thus: `book1.title`, `book1.author`, and `book1.pages`.   

## Arguments to Functions
We can also pass structs as arguments to functions.  For example:

```
#include <stdio.h>
#include <string.h>
 
struct book {
   char  title[50];
   char  author[50];
   int   pages;
};
 
void print_book(struct book b) {
   printf("Book title: %s\n", b.title);
   printf("Book author: %s\n", b.author);
   printf("Book pages: %d\n", b.pages);
}

int main( ) {
   /* Declare book1 and book2 of type struct book */
   struct book book1;        
   struct book book2;
 
   /* book 1 specification */
   strcpy(book1.title, "The Hobbit");
   strcpy(book1.author, "J.R.R. Tolkien"); 
   book1.pages = 285;
   
   /* book 2 specification */
   strcpy(book2.title, "Because of Winn Dixie");
   strcpy(book2.author, "Kate DiCamillo"); 
   book2.pages = 232;

   print_book(book1);
   print_book(book2);
  
   return EXIT_SUCCESS;
}
```

## An Important Caveat
Remember that C is a **pass-by-value** language.  This has implications when we pass a `struct` to a function.  Since C is pass-by-value, passing a `struct` to a function means that the entire struct -- and all its associated data members -- are copied to the parameter variable.  Thus, functions cannot modify `structs` which are passed to them; if you modify the function's `struct` you are only modifying the parameter variable which then goes out of scope at the end of the function.  Instead, you would need to pass a pointer to a `struct` which you could then de-reference and modify.  Note that in the function above, we do not modify the `struct`.  We are just accessing its data and displaying it via `printf`.  More on pointers to `struct`s and functions which modify `struct`s later. 


## Typedefs
We commonly use `typedef`s to make for more readable code.  `typedef` allows us to **def**ine a **type**.  We wrap our struct in a `typedef` statement like:

```
typedef struct book {
   char title[50];
   char author[50];
   int pages;
} my_book_type;
```

The only two changes from our previous struct definition is that we include the keyword `typedef` before we start our definition, and we add a identifier which is the name of our new datatype before the final semicolon -- in this example, `my_book_type`.

Then when we want to use our new datatype:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct book {
   char  title[50];
   char  author[50];
   int   pages;
} my_book_type;
 
int main( ) {
   my_book_type book1;        /* Declare book1 of type struct book */
 
   /* book 1 specification */
   strcpy(book1.title, "The Hobbit" );
   strcpy(book1.author, "J.R.R. Tolkien" ); 
   book1.pages = 285;
   ...
}
```

Notice that we now can declare variables using our new type name!  Cool!

## A Few Caveats
While this feels a lot like Java in many ways, there are some key differences.  For one, there is no way to include functions in structs.  You can only include data.

While we can use structs directly as we've demonstrated in this note, this isn't a terribly common usage.  It's far, far, FAR more common to use pointers to structs, and we'll learn how to do this in future notes.
