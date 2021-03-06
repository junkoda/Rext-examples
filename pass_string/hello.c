// Pass string from R to C
// simply define a function with char** str

#include <stdio.h>

void hello(char** str)
{
  if(str)
    printf("Hello %s\n", *str);
}

// Vectorised version
void vhello(char** str, int* n)
{
  for(int i=0; i<*n; i++)
    printf("Hello %s\n", str[i]);
}
