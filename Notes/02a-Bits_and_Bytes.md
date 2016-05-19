# Bits and Bytes

### Transistors

A computer is an *electronic programmable calculating machine*. At a base level, any operation a computer can perform is executed by
electrical signals passing through circuits that implement logical operations. These circuits are built from *transistors*.

You can think of a transistor as a switch.

``` 
         power
           |
           |
           |  collector
          /
  base   |
---------|
         |
          \
           v  emitter
           |
           |
        ground
```

When current is applied to the base terminal, the transistor switches "on" and allows current to flow from the collector to the 
emitter.

Multiple transistors may be combined together to create logic circuits that implement the basic operations AND, OR, and NOT. These 
basic can be further combined to design complex circuits that add, compare, switch, store, and perform all of the other tasks that are 
required for a computer to operate.

We won't actually study the design of digital logic circuits in the course because Dr. Carrington covers it in Applied Discrete 
Mathematics. For now, we'll just accept (using our powers of abstraction) that we have the capability to create the basic physical 
hardware of a computer.

### Bits

We can recognize two basic states in any digital logic circuit:
  
  1. the *presence* of a significant electrical voltage
  2. the *absence* of any significant electrical voltage

This recognition gives rise to the concept of a *binary digit* or ***bit***.

A single bit represents a basic unit of information having only two possible values, which we'll label as 0 (representing falseness or 
absence) and 1 (representing truth or presence).

The meaning of "significant electrical voltage" depends on the technology used to implement the system's logic gates. It's common for a
logical level of 0 to be represented by a voltage close to 0 and for a logical level of 1 to be represented by a voltage of +3.5 V.

### Everything is Bits






