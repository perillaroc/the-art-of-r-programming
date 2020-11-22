#include <R.h>

void subdiag(
  double *m,
  int *n,
  int *k,
  double *result
){
  int nval = *n;
  int kval = *k;
  int stride = nval + 1;
  for(int i = 0, j = kval; i < nval - kval; ++i, j+=stride) {
    result[i] = m[i];
  }
}