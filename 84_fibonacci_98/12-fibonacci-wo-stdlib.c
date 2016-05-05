#include <unistd.h>

int print_char(char c) {
  /* Prints the character */
  return (write(1, &c, 1));
}

void print_number(int n, int d, int s){
  /* Prints the number segment provided */
  char c;
  int i;

  if (n == 0 && s == 0){
    return;
  }

  i = n / d;
  if (s == 0 && i == 0){
    print_number(n % d, d / 10, s);
    return;
  }
  if (s == 0)
    s = 1;
  c = '0' + (n / d);
  print_char(c);
  if (d == 1)
    return;
  print_number(n % d, d / 10, s);
}

void print_segments(int ttt, int tt, int t, int d) {
  /* Prints the number depending on number of segments*/
  if (ttt){
    print_number(ttt, d, 0);
    print_number(tt, d, 1);
    print_number(t, d, 1);
  } else if (tt) {
    print_number(tt, d, 0);
    print_number(t, d, 1);
  } else {
    print_number(t, d, 0);
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
  d = d / 10;
  print_segments(ttt, tt, t, d);

  if (i != 97){
    print_char(',');
    print_char(' ');
  }
  fibonacci_recursion(b, bb, bbb, t, tt, ttt, ++i);
}

int main(void){
  /* Prints the first two numbers and initializes recursion */
  int a;
  int b;

  a = 1;
  b = 2;
  print_number(a, 1, 0);
  print_char(',');
  print_char(' ');
  print_number(b, 1, 0);
  print_char(',');
  print_char(' ');
  fibonacci_recursion(a, 0, 0, b, 0, 0, 2);
  print_char('\n');
  return 0;
}
