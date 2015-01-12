// Pass string from R to C using .Call

#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

SEXP hello2(SEXP str)
{
  int n= length(str);
  printf("n= %d\n", n);


  for(int i=0; i<n; i++) {
    char const * const s= CHAR(STRING_ELT(str, i));
    printf("Hello %s\n", s);
  }

  return R_NilValue;
}

