# Assembly Language Programming

This lab will let you practice writing assembly language programs on the Raspberry Pi, including

  - Compiling and running assembly programs with `gcc`
  - Arithmetic
  - Using variables

## Setup and Login

Repeat the basic setup process from the last lab:

  1. Connect your Pi to your laptop using an ethernet cable.
  
  2. Open the terminal application (for Mac users) or PuTTY (for Windows users).
  
  3. Connect the power supply to the Pi and wait about a minute
  
  4. Log in to `pi@raspberrypi.local`. For Mac users, the terminal command is
  
  ```
  prompt$ ssh pi@raspberrypi.local
  ```
  
  The default password is `raspberry`.
   
Once you're logged in to the Pi, verify that your wi-fi is working:

```
prompt$ ping 8.8.8.8
```

Remember that you can use `CTRL + c` to terminate the `ping` program.


## Writing and Compiling a Program

First, make a directory to hold your assembly code and `cd` into it:

```
prompt$ mkdir Assembly
prompt$ cd Assembly
```

Create a new file called `first_program.s`; all of our assembly programs will have the `.s` extension. Open it with `nano`.

```
prompt$ touch first_program.s
prompt$ nano first_program.s
```

The following program loads and then returns 100:

```
// Load and return a value

// Words beginning with . are assembler directives
// This line declares the label main as the program's entry point
.global main

main:
    // This command goes at the beginning of every function
    push {ip, lr}

    // Move 100 into register r0
    mov r0, #100

    // Return
    pop {ip, pc}
```    

Recall that, by convention, the value in `r0` when the `pop` command executes is always treated as the return value.

Save the file by pressing `CTRL + o` and then `ENTER`, then press `CTRL + x` to exit the `nano` editor.

Compile the program with `gcc`:

```
prompt$ gcc -o first_program first_program.s
```

Run the program. To check the return value, use `echo $?`, which prints the value returned by the last program that executed.

```
prompt$ ./first_program
prompt$ echo $?
100
```

In the shell, `$` signifies an **environment variable** that carries some information about the shell environment. `$?` is a special
environment variable that is automatically updated with the return value every time a program exits. Note that you only get the 
return value from the **last program**, so if you run any other command between `./first_program` and `echo $?`, you'll see a different
value (probably 0).

## Arithmetic

### Addressing Modes
Here is the first key to ARM programming: everything happens with registers.

  - Values are loaded into registers.
  - Arithmetic and logical operations always take their arguments from registers and put their results back into a register.
  
In ARM, there is no way to perform a calculation **without first loading the data into registers**.

A way of loading data is called an **addressing mode**. So far, we've seen one mode, **immediate addressing**, where the data is specified as part of the command.

```
mov r0, 100  // Load the value 100 into r0
```

There are other addressing modes that correspond to different ways of loading data, each of which is useful in a different context. We'll see another one at the end of this lab when we introduce variables.

### Add Three Numbers

Create a new file and 

```
// Add three numbers
// Illustrates immediate addressing, multiple registers, and arithmetic instructions

.global main

main:
    push {ip, lr}

    // Calculate a sum of three values
    // Use four registers

    mov r0, #1  // r0 <- 1
    mov r1, #2  // r1 <- 2
    mov r2, #3  // r2 <- 3

    add r4, r0, r1  // r4 <- r0 + r1
    add r4, r4, r2  // r4 <- r4 + r2

    // Move return value to r0
    mov r0, r4  // r0 <- r4

    // Return
    pop {ip, pc}
```

Compile and run the program, then use `echo $?` to verify that you get the correct sum.

A few points to make about this program:
  
  - It uses the `mov` instruction in two ways: to move a value into a register (immediate addressing) and to move a value from one register to another. Note that, in the latter case, `mov` **copies** the data; it doesn't swap the values and the source register remains unaffected by the instruction.
  
  - The way in which the registers are used is arbitrary and up to the programmer's discretion. There are many ways to implement the same calculation with different register allocations. This is part of the fun of assembly language programming!
  
  - All arithmetic instructions use the same basic format:
  
    ```
    command  destination, source1, source2
    ```
    
### Practice

1. Write a program that loads 1 into `r0` and 100 into `r1`, then uses `r2` to swap their values. Use 

```
mov rX, rY
```
to copy the value of register `rY` into `rX`, where `Y` and `X` are the numbers of general-purpose registers.

2. Write a program that calculates `50 - 5` and returns the result. Use 

```
sub rX, rY, rZ
```

to perform the operation `rX <- rY - rZ`.

## Variables

Recall that variables are stored in **main memory** while the program executes. In ARM, a global variable is a label associated with some reserved space. To create a global variable, you need two things:

First, the keyword `.data`, which specifies the "data" section of the program. We'll also add a `.text` section to identify the code.

Second, a label name and the `.word` assembler directive, which reserves the required space.

Here is the complete example:

```
.data

x: .word 10
```

`.word` reserves 4 bytes of space, which is now associated with the label `x`. The number, if it's present, specifies the initial value
loaded into the reserved memory.

### Loading and Storing

ARM is a **load-store architecture**. This means that there is **no way** to directly interact with variables in memory. Rather, you must explicitly **load** data from memory into a register, operate on it, then explicitly **store** the data back to memory.

Loading and storing data directly from or to a memory location is called **direct addressing**. You now know two addressing modes:

  - immediate addression, for loading hard-coded values
  - direct addressing, for load and store operations on memory locations associated with variables

Loading and storing is a two-step process:

  1. Load the memory address associated with the variable.
  
  2. Load data from that address or store data to that address.
  
The first key command is

```
ldr r1, =x
```

The `=x` statement gets the memory address associated with a label. The command loads this address into `r1`. Note that `r1` is just an example register; you could use any of the general purpose registers, r0 to r12.

The second command completes the operation by loading the data from memory into a register:

```
ldr r0, [r1]
```

This instruction fetches the data at the memory address in `r1` (loaded by the previous instruction) into `r0`. Again, `r0` and `r1` are not special: any of the general purpose registers could have been used.

The store operation is similar:

```
str r2, [r1]  // Store value in r2 into the memory location held in r1
```
  
Here is a complete example. The program allocates a variable named `x`, stores a value into `x`, then loads the value of `x` back into `r0` as the return code. In C, this program would be

```
int x;  // Global variable

int main() {
    x = 21;
    return x;
}
```

Create a new file and **type** this program into it so you can study every detail. **Don't copy and paste it**.

```
// Using a variable

.global main

.data  // All variable declarations go after .data
x: .word 0

.text  // All code goes after .text

main:
    push {ip, lr}
    
    // r0 <- 21
    mov r0, #21
    
    // Load the address of x into r1
    // ldr is the load instruction
    // Use = to get the address of a label
    // Like &x in C
    ldr r1, =x
    
    // Address of x is now in r1
    // Use [r1] to store to this location
    str r0, [r1]  // x <- r0
    
    // Reload the updated value of x into r0
    // The address of x is still in r1
    ldr r0, [r1]
    
    // Program returns 21
    pop {ip, pc}
```
    
### Incrementing a Variable
Create a new file named `variables.s` and fill it with the following code. **Type the program**, so you can inspect every element of it. Don't copy and paste it. This program is equivalent to:

```
int x = 10;

int main() {
    x = x + 1;
    return x;
}
```

```
// Incrementing a variable in ARM

.global main

//*** Global vars and static data ***//
.data
x: .word 10  // x is initially 10

//*** Code ***//
.text

main:
    push {ip, lr}

    // r0 <- 1
    mov r0, #1

    // Use =x to get the address of x
    ldr r2, =x

    // Use [r2] to load x's value
    ldr r1, [r2]  // r1 <- x
    
    // Increment
    add r1, r0, r1 // r1 <- r0 + r1

    // Store the incremented value
    str r1, [r2]  // memory location stored in r2 <- value in r1

    // Reload x as the return value in r0
    // Address is still in r2
    ldr r0, [r2]
    
    // Return
    pop {ip, pc}
```

### Practice

Translate the following program into ARM:

```
int x = 10;
int y = 15;
int z;

int main() {
  z = x + y;
  return z;
}
```
