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

**All information in a computer system, regardless of its source, type, or use, is ultimately represented as a sequence of bits**.

Numbers, text strings, program instructions, images, audio, video, web pages, spreadsheets, databases, and every other kind of
information used by any computer program must be encoded as a sequence of bits.

This truth has an important corollary: the meaning of any particular string of bits depends on the context in which it's read. For 
example, the 32-bit sequence

```
01100101011001100110011101101000
```

could represent a single signed `int`, or an unsigned `int`, or four `char` values, or two `short` values, or a machine language
instruction, or a `float`. The interpretation of the bit string depends upon the context in which it's used.

Suppose that you have a grouping of *N* bits. How many distinct combinations can that grouping represent? Each bit may take one of two 
values, 0 or 1, so there are two choices for each of the *N* positions.

  - a single bit can represent 2 values (0 and 1)
  - two bits can represent 4 values (00, 01, 10, and 11)
  - three bits can represent 8 values (000, 001, 010, 011, 100, 101, 110, 111)
  
In general, an *N* bit sequence can represent *2^N* distinct values.


### Bytes and Larger Units

Even if all information in a compuer is ultimately a sequence of bits, it's typically inconvenient to reason about and work with individual 0/1 values. All modern CPUs store and manipulate larger groupings.

The most important unit is the *byte*, which is defined to be 8 bits.


