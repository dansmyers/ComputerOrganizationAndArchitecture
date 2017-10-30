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

  - Data is loaded into registers
  - Arithmetic and logical operations always take their arguments from registers and put their results back into a register
  
In ARM, there is no way to perform a calculation **without first** loading the data into registers.

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

## Variables
