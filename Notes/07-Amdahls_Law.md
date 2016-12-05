# Amdahl's Law

Amdahl's Law (named after IBM computer designer Gene Amdahl) is a formula that
expresses the overall performance improvement obtained by modifying part of a
system. One of its main uses is quantifying the relative performance benefits
of different design options.

## Derivation

Let's define some terms:

```
T = run time a representative workload before an improvement
f = fraction of workload affected by the proposed improvement
s = speedup factor obtained by the proposed improvement
```

First, separate the total runtime `T` into two parts: the part affected by the
improvement and the part left unaffected.

```
T = fT + (1 - f)T
```

The affected part is sped-up by a factor of `s`, e.g., if `s` is 2, then the 
sped-up portion of the workload completes in half the time.

Let `T'` denote the runtime for the workload on the improved system:

```
T' = fT / s + (1 - f)T
```

The overall speedup obtained is

```
Overall speedup = T / T'
```

Substituting:

```
Overall speedup =         T
                  -----------------
                  fT / s + (1 - f)T
```

Factoring and cancelling `T` yields the final result:

```
Overall speedup =        1
                  ---------------
                  f / s + (1 - f)
```

This formula is Amdahl's Law.

It expresses the intuitive insight that the overall impact of an improvement
depends on both the magnitude of the improvement **and** the frequency with 
which it's used. Small improvements might be quite valuable if they apply
to a large fraction of the workload.


## Example

Suppose we're considering two potential performance improvements to a system,
but can only implement one:


    - making the DIV instruction, which accounts for 1% of a
      benchmark workload's instructions, 100 times faster?

    - making the load instruction, used in 35% of a
      benchmark workload's instructions, 2% faster?
      
Which choice yields superior overall speedup?

Applying Amdahl's Law to choice one gives the following result:

```
f = .01
s = 100

Overall speedup =           1           ~ 1.0099
                  ---------------------
                  .01 / 100 + (1 - .01)
```

For the second choice:

```
f = .35
s = 1.02

Overall speedup =           1            ~ 1.0069
                  ----------------------
                  .35 / 1.02 + (1 - .35)
```

Therefore, the first option yields a slightly greater increase in overall
performance, approximately 1%.