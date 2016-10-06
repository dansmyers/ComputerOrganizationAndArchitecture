// Convert a string to an integer
// DSM, 2016

#include <stdio.h>


// This is a reimplementation of the standard function atoi
// Implementing atoi is a popular interview question


//*** Converts a string input to an integer value ***//
//
// Input: a null-terminated string s
//   for now, assume that s is a valid integer
//
// Returns: the integer represented by s
int myatoi(char *s) {
  int result = 0;
  int isNegative = 0;
  
  if(*s == '-') {
      isNegative = 1;
      s++;
  }
  
  while(*s != '\0') {
      result *= 10;
      result += *s - '0';
      s++;
  }

  if (isNegative) {
      result *= -1;
  }
  
  return result;
}


int main() {
    printf("%d\n", myatoi("101"));
    printf("%d\n", myatoi("-101"));
    printf("%d\n", myatoi("1234567890"));
    printf("%d\n", myatoi("-1234567890"));
    
    return 0;
}