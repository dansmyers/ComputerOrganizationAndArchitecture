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
