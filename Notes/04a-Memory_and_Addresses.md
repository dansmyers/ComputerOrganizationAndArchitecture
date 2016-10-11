# Memory and Addresses

## What is a Variable?

Every variable in a program corresponds to **location in memory** where the value associated with that variable is stored.

For example, when you declare

```
int x;
```

in a program, that declaration is associated with a region of memory large enough to hold one `int`; the name `x`is associated with this memory region.

```
    ---------------
    |              |
    |              |
    |--------------|  
x:  |  value of x  |  <--| enough space for
    |              |  <--| one int (probably 4 bytes)
    |--------------|  
    |              |
    |              |
    ----------------
```

## The Canonical Address Space

## Examples

## Using Memory Addresses with `scanf`
