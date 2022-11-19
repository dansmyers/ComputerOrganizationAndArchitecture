# Assignment 5: General Assembly

<img src="https://upload.wikimedia.org/wikipedia/commons/0/05/UN_General_Assembly_hall.jpg" width="40%" />

*The United Nations General Assembly hall*

## Due Friday December 2 (the last day of classes)

## You can work with a partner to complete this project

## Description

Write ARM assembly language programs to answer the following questions. As before,
develop your answers in the CPUlator environment, then paste your solutions into
the workspace on repl.it.

All of the questions require writing functions and using the `bl` instruction.
**You must write functions that take inputs and return a single result**. Remember
the guidelines for calling ARM functions:

- Up to four arguments can be passed in `r0`-`r3`. The called subroutine is allowed
to modify these registers freely.
- Additional arguments are passed on the stack (look at the `addEight` example from 
class).
- If the called subroutine wants to modify `r4`-`r12` it must save them on the
stack and restore them before returning.

## Problems

### Babylonian Square Root

Implement the classic Babylonian square root algorithm. To find the square root
of a given number `n`, start with a guess `x`. On each iteration, update `x` using

```
x = (x + n / x) / 2
```

Intuitively, if `x` is smaller than the real square root, then `n / x` is larger
and the average should be closer to the true root. A similar argument applies if
`x` is larger than the true root.

```
int root(int n) {

  // Set starting value of x
  int x = 1;

  // Loop until x doesn't change
  do {
    int oldX = x;
    x = (x + n / x) / 2;
  } while (x != oldX);
}

int main() {
  return root(144);
}
```

Tips:

- You'll need to perform divisions. There is a `udiv` instruction to perform unsigned division, but the CPUlator
doesn't support it. Maybe you could write your own function that uses a loop to perform integer division?
- Recall that you can implment division by 2 in one instruction by bit-shifting to the right.
- What about that `do`- `while` loop? Think about how to modify the standard `while`
loop to check the condition at the end and then decide if you need to branch back 
to the top or not.


### Countdown

Implement the following ***recursive*** program and step through its execution.
Make sure that the recursive process executes correctly, moves through the values from
4 to 0, and then returns -1 as the final result.

Tip:

- Think about the placement of the return statements. You could use multiple
`pop` statements at different places in the code to implement different return
statements, or maintain one `pop` statement at the very end of the function and
implement the logic so that you always return the correct value when you reach it.

```
int countdown(int n) {
  if (n == 0) {
    return -1;
  } else {
    return countdown(n - 1);
  }
}

int main() {
  return countdown(4);
}
```


### Everyone needs a hobby

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/6b/Ziggarat_of_Ur_001.jpg/2880px-Ziggarat_of_Ur_001.jpg" width="40%" />

*The Ziggurat of Ur (ca. 2100 BC), one of the best ziggurats*

I enjoy building stone ziggurats in my back yard. To build a *n* level ziggurat,
I lay a square of *n* x *n* stones, then a square of *n - 1* x *n - 1* stones,
and so forth until I place a single stone on the top.

Write a **recursive** program to calculate the number of stones in the *n* level
ziggurat. The basic recurrence relation is

```
stones(n) = stones(n - 1) + (n * n)
stones(1) = 1
```

**You must use a recursive solution, not a loop**.


### Project Euler #5

2520 is the smallest number that is evenly divisible by each of the numbers from 1 to 10 without any remainder. What is the smallest number that is evenly 
divisible by all of the numbers from 1 to 20?

Tips:

- Just multiplying the values from 1 to 20 won't give you the correct answer. Write a loop that continually increases a value of `n` and then uses an inner loop
to check for divisibility by each value from 2 to 20.

- You can save yourself a little effort by only incrementing `n` in steps of 20. You can do even better by starting at 2520 and incrementing in steps of 2520.


- You'll need a way to test for divisibility. Maybe write a `mod` function that takes two inputs and returns the remainder?

```
int mod(int a, int b) {
  int rem = a;
  while ( rem > b) {
    rem -= b;
  }
  return rem;
}
```


