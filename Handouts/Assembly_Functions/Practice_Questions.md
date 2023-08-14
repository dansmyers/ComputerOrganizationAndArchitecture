# Assembly Function Practice Questions

```
int addOne(int n) {
  return n + 1;
}

int main() {
  int z = 100;
  z = addOne(z);
  return z;
}
```


```
int isNegative(int n) {
  if (n > 0) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int x = -1;
  return isNegative(x);
}
```


```
int isNegative(int n) {
  if (n > 0) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int x = -1;
  
  // Think about calling isNegative, then using the result
  // it returns as part of the if statement
  if (isNegative(x)) {
    x = -x;
  }
  
  return x;
}
```


```
int multiply(int a, int b) {
  int prod = 0;
  
  while (b > 0) {
    prod += a;
    b--;
  }
  
  return prod;
}

int main() {
  return multiply(11, 5);
}
```
