#include <stdio.h>

void print_fibonacci(int t, int tt, int ttt, int i){
  /* Prints the number depending on number of segments*/
  if (ttt){
    printf("%d%09d%09d", ttt, tt, t);
  } else if (tt) {
    printf("%d%09d", tt, t);
  } else {
    printf("%d", t);
  }

  if (i != 97){
    printf(", ");
  }
}

void fibonacci_recursion(int a, int aa, int aaa, int b, int bb, int bbb, int i){
  /* Recurses to print the remaining 96 numbers in the first 98 */
  int t;
  int tt;
  int ttt;
  int d;

  d = 1000000000;

  if (i == 98)
    return;

  t = ((a + b) % d);
  tt = ((aa + bb) % d) + ((a + b) / d);
  ttt = aaa + bbb + ((aa + bb) / d);
  print_fibonacci(t, tt, ttt, i);
  fibonacci_recursion(b, bb, bbb, t, tt, ttt, ++i);
}

int main(void){
  /* Prints the first two numbers and initializes recursion */
  int a;
  int b;

  a = 1;
  b = 2;
  printf("%d, ", a);
  printf("%d, ", b);
  fibonacci_recursion(a, 0, 0, b, 0, 0, 2);
  printf("\n");
  return 0;
}
