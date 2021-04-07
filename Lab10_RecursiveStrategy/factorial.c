// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
long long int factorial(int n){
    long long int acc = 1;
    int i = 0;
    for (i = n; i > 0; i--) {
        acc = acc * i;
    }
    return acc;
};

// TODO: Implement recursive solution here
long long int factorial_rec(int n){
    if (n==0 || n==1) {
        return 1;
    }
    return n * factorial_rec(n - 1);
}

int main(){

  // Both of these should print the same result!
  int calc = 21;
  printf("factorial(%d)     = %lld\n", calc, factorial(calc));
  printf("factorial_rec(%d) = %lld\n", calc, factorial_rec(calc));


  return 0;
}
