# Final Exam Review

## Description

This document contains questions for the final exam. I will pick ten to fifteen questions **exactly as they appear here** for the exam. Therefore, if you study these questions and know their answers, you'll be completely prepared for the exam.

The exam is **closed book, notes, and internet resources**.


## Questions

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


### Memory and disk

1. Draw a diagram of the memory hierarchy, starting with registers at
   the top and ending with network storage devices at the bottom.
   Include three levels of cache, main memory, and disk storage.
   Label each level with its approximate size and access time.
   
2. Consider a disk with the following characteristics:
- 8 ms average seek time
- 15000 RPM rotational speed
- 100 MB/s data transfer rate
Estimate the time required to perform a 1 MB read on this disk.

3. REAL GOOGLE INTERVIEW QUESTION: estimate the time to read 1 GB
   from a disk. Hint: the key word is *estimate*.  

### Cache calculations

1. Consider a system with three levels of cache and main memory. By
   analyzing representative workloads, we have quantified that
  
- 30% of memory accesses hit in the L1 cache
- 50% of L1 misses will hit in the L2 cache
- 50% of L2 misses will hit in the L3 cache
  
- An average memory access takes 100 ns
- An average L3 access takes 50 ns
- An average L2 access takes 10 ns
- An average L1 access takes 2 ns
  
What speedup factor is attained by including all three cache
levels in the system, relative to a system with only main memory
and no caching?

What if we removed the L3 cache?  What would be the effect on 
the system's performance?
   
2. Suppose we used the system of problem 4, but installed a larger L1
   cache. The larger cache achieves a hit rate of 40%, but takes
   longer to process each hit. What is the maximum increase in L1
   access time we can tolerate and still achieve superior performance
   to the system in problem 4?
   
3. A more challenging variation: suppose the larger cache has a fixed
   hit time of 2 ns. What L1 hit rate must be achieved to yield a
   faster access time than the system of problem 4?

4. Suppose we're designing the new version of processor that currently has no cache. From simulation experiments, we have determined that a representative workload has an overall L1 cache hit rate of x% and that75% of L1 cache misses would hit in the L2 cache. On this system, an L1 cache hit takes 1 ns to service, an L2 cache hit takes 10 ns to service, and a main memory access requires 100 ns. Find the minimum L1 cache hit rate x such that the expected time for a load is less than 30 ns.
