# Final Exam Review

## Description

This document contains questions for the final exam. I will pick ten to fifteen questions **exactly as they appear here** for the exam. Therefore, if you study these questions and know their answers, you'll be completely prepared for the exam.

The exam is **closed book, notes, and internet resources**.


## Questions

### Words for things

1. Define the term *Instruction Set Architecture*.

2. Write down the steps of the fetch-decode-execute cycle.

3. List the motivation and design principles associated with a *Reduced Instruction Set Computer*.

### Assembly Language Translation

Translate the following code fragments or programs into ARM assembly language. If a fragment is given, only convert the fragment; you don't need to write a complete program.

```
int sum = 0;
int i;
for (i = 0; i < a; i++) {
    sum += i;
}
return sum
```

```
// Assume a, b, c, and d are in registers

if (a < b) {
    if (a >= c) {
        d = a;
    } else if (b >= c){
        d = b
    }
} else if (b >= c) {
    d = c;
}  else {
    d = b;
}
```

```
// Translate the following complete program

double (int x) {
    return x + x;
}

int main() {
    double(5);
}
```

```
int i; // Assume i is initially in r0
int sum = 0; // Assume sum is initially in r1

for (i = 0; i < 100; i = i + 2) {
    sum += i;
    i++;
    if (sum > 100) {
        break;
    }
}

return sum; // Use pop {ip, pc}
```


```
int var = 1; // Global variable

int sum(int c, int d) {
    return c + d;
}

int main() {
    return sum(var, 3);
}
```

### Calling convention
Summarize the calling convention for ARM programs.

- How are arguments passed?
- Which registers is the callee allowed to freely modify?
- Which registers is the callee responsible for preserving?
- How are values returned?


### Stack smashing

Draw and summarize a diagram showing how an attacker can exploit a buffer declared on the stack to perform a stack-smashing attack and execute arbitrary code.

Describe at least two approaches to defending against stack smashing.


### Performance and Amdahl's Law

1. What is Moore's Law? How is the real Moore's Law different from
   the "Popular Moore's Law" stating that computers double in speed
   every two years?
   
2. Write down the Master CPU Performance Equation that relates instruction, cycles per instruction, and clock speed to execution time.

3. Estimate the execution time for a program that contains
   25000 instructions and the following mix of instructions
   and CPI measurements. The program is executing on a system with a 2 GHz clock.


```
instruction    fraction of workload    CPI
-----------    --------------------    ---
arithmetic     40%                     3
branch         25%                     4
load/store     35%                     8            
```
   
   
4. Derive Amdahl's Law.

5. Easy Amdahl's Law problem: branch instructions account for 25% 
of the instruction mix in a particular program' sworkload.  Estimate
the performance impact of speeding up branch instructions by a 
factor of 1.5.

6. Consider a parallel program with a fraction f that must be
executed serially on a single processor.  Use Amdahl's Law to
argue that the speedup to this program from parallelizing the 
remaining fraction 1 - f of the program can never exceed 1 / f.

7. What is the total speedup obtained by the following
   collection of improvements? Use the table in problem 3 for
   instruction frequencies.

```
arithmetic    3 times faster
branch        50% slower
load/store    10% faster
```

6. Suppose we're designing the new version of processor that currently has no cache. From simulation experiments, we have determined that a
representative workload has an overall L1 cache hit rate of 40% and that 50% of L1 cache misses would hit in the L2 cache. On this system, an L1 cache hit takes 1 ns to service, an L2 cache hit takes 10 ns to service, and a main memory access requires 100 ns. Use Amdahl's Law to calculate the expected overall speedup gained by adding the L1 and L2 caches to the system.

### Memory and disk

1. Draw a diagram of the memory hierarchy, starting with registers at
   the top and ending with network storage devices at the bottom.
   Include three levels of cache, main memory, and disk storage.
   Label each level with its approximate size and access time.
   
2. Consider a disk with the following characteristics. Estimate the time required to perform a 1 MB read on this disk.
- 8 ms average seek time
- 15000 RPM rotational speed
- 100 MB/s data transfer rate


3. REAL GOOGLE INTERVIEW QUESTION: estimate the time to read 1 GB
   from a disk. Hint: the key word is *estimate*.
   

### Cache calculations
Consider a system with three levels of cache and main memory. By analyzing representative workloads, we have quantified that
  
- 30% of memory accesses hit in the L1 cache
- 50% of L1 misses will hit in the L2 cache
- 50% of L2 misses will hit in the L3 cache
  
- An average memory access takes 100 ns
- An average L3 access takes 50 ns
- An average L2 access takes 10 ns
- An average L1 access takes 2 ns
  
1. What speedup factor is attained by including only the L1 cache, relative to a system with only main memory and no caching? Tip: 30% of accesses will hit in L1, which means that 70% will go to main memory. What is the average memory access time in this case?

2. What if we include L1 and L2 caches? Tip: calculate the total fraction of accesses that hit in L2. Anything that misses in L2 must go to main memory.

3. What is the average memory access time if we include all three levels?
   
4. Suppose we used the system of the previous problem, but installed a larger L1
   cache. The larger cache achieves a hit rate of 40%, but takes
   longer to process each hit. What is the maximum increase in L1
   access time we can tolerate and still achieve superior performance
   to the original system?
   
5. A more challenging variation: suppose the larger cache has a fixed
   hit time of 2 ns. What L1 hit rate must be achieved to yield a
   faster access time than the system of problem 4?

6. Suppose we're designing the new version of processor that currently has no cache. From simulation experiments, we have determined that a representative workload has an overall L1 cache hit rate of *x*% and that 75% of L1 cache misses would hit in the L2 cache. On this system, an L1 cache hit takes 1 ns to service, an L2 cache hit takes 10 ns to service, and a main memory access requires 100 ns. Find the minimum L1 cache hit rate *x* such that the expected time for a load is less than 30 ns. Tip: express fraction of accesses that go to L2 and main memory in terms of *x*.


### C `struct`s and memory management

1. What does it mean to say that Java has a garbage collector? Explain, in general terms, how the garbage collector works.

2. Define the terms *double free* and *memory leak*.

3. Write a `typdef` statement to define a `struct` named `Point3D` that represents a point in 3-D space with `x`, `y`, and `z` fields.

4. I wrote the following code fragment that seems okay, but my system refused to execute it and just curled up under a blanket and cried from half an hour. What did I do wrong? Assume that the correct defintion exists for `Point3D`.

```
Point3D *p;

p->x = 1.0;
p->y = 2.0;
p->z = 3.0;
```

5. Complete the following function to take two `Point3D` structs as input and return a new `Point3D` that contains the sum of the two points. That is, the returned point should contain the sum of the `x` values of the two input points, the sum of the `y` values, and so forth.

```
Point3D * point3DSum(Point3D *p1, Point3D *p2) {

  // Create a new point to return
  
  // Calculate and return sum of the two points
  
}
```

6. Explain how a C `struct` is and is not like a Java object. Your answer must include the term *encapsulation*.

