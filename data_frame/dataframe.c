// A R-extension written in C
// Create a data.frame and return it to R
//
// data.frame is a list with class="data.frame" and row.names.


#include <stdio.h>
#include <R.h>
#include <Rinternals.h>



SEXP return_data_frame(void)
{
  // Returns a data.frame(x,y,z) such that,
  // x <- c(0,0,0,0)
  // y <- c(0,0,0,0)
  // z <- c(0,0,0,0)
  
  const int ncol= 3;
  const int nrow= 4;
  SEXP list, col_names, row_names;
  PROTECT(list = allocVector(VECSXP, ncol));
  PROTECT(col_names = allocVector(STRSXP, ncol));
  PROTECT(row_names = allocVector(STRSXP, nrow));
  
  // column names
  SET_STRING_ELT(col_names, 0, mkChar("x"));
  SET_STRING_ELT(col_names, 1, mkChar("y"));
  SET_STRING_ELT(col_names, 2, mkChar("z"));
  setAttrib(list, R_NamesSymbol, col_names);

  // row names 1,2,3,4
  char rname[20];
  for(int i=0; i<nrow; i++) {
    sprintf(rname, "%d", i+1);
    SET_STRING_ELT(row_names, i, mkChar(rname));
  }
  setAttrib(list, R_RowNamesSymbol, row_names);
    
  // class=data.frame
  setAttrib(list, R_ClassSymbol, ScalarString(mkChar("data.frame")));
  

  // creates vectors (0,0,0,0)
  SEXP x,y,z;
  PROTECT(x = allocVector(REALSXP, nrow));
  PROTECT(y = allocVector(REALSXP, nrow));
  PROTECT(z = allocVector(REALSXP, nrow));

  double* rx= REAL(x);
  double* ry= REAL(y);
  double* rz= REAL(z);
  
  for(int i=0; i<nrow; i++) {
    rx[i]= 0.0;
    ry[i]= 0.0;
    rz[i]= 0.0;
  }

  // set the vectors in list$x <- x ...
  SET_VECTOR_ELT(list, 0, x);
  SET_VECTOR_ELT(list, 1, y);
  SET_VECTOR_ELT(list, 2, z);

  UNPROTECT(6);

  return list;
}

// Reference
//
// See R do_makelist() in R source 'builtin.c' how to create a list in C.
//
// > data.frame
// in R shows that data.frame has row.names and  a class data.frame.
//   attr(value, "row.names") <- row.names
//   attr(value, "class") <- "data.frame"
//

