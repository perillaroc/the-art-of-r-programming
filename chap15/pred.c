#include <R.h>

void pred_v4(int *x, int *n, int *k, double *errrate) {
  int nval = *n;
  int kval = *k;
  int nk = nval - kval;
  int sm = 0;
  int pred;
  
  double k2 = kval / 2.0;
  
  for (int i=0; i < kval; i++) {
    sm += x[i];
  }
  
  if (sm >= k2) {
    pred = 1;
  } else {
    pred = 0;
  }
  
  int errs = abs(pred - x[kval]);
  
  for (int i=1; i < nk; i++) {
    sm = sm + x[i+kval-1] - x[i-1];
    if (sm >= k2) {
      pred = 1;
    } else {
      pred = 0;
    }
    errs += abs(pred - x[i+kval]);
  }
  *errrate = (double) errs / nk;
}