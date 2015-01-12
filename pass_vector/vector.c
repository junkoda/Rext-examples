// Passing a vector from R to C

#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

SEXP ivector(SEXP v)
{
  const int n= length(v);
  int const * const a= INTEGER(v);
  
  for(int i=0; i<n; i++)
    printf("%d\n", a[i]);

  return R_NilValue;
}

