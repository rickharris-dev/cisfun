#include <stdio.h>

void print_buffer(char *b, int size){
  int c;
  c = 0;

  while(b) 
  printf("%s\n", b);
  printf("%d\n", size);
}
