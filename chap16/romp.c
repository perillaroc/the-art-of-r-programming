#include <omp.h>
#include <R.h>

int tot;

int procpairs(int i, int *m, int n) {
  int j, k, sum = 0;
  for(int j = i + 1; j < n; j++) {
    for(int k = 0; k < n; k++) {
      sum += m[n*k + i] * m[n*k + j];
    }
  }
  return sum;
}

void mutlinks(int *m, int *n, double *mlmean) {
  int nval = *n;
  tot = 0;
  #pragma omp parallel
  {
    int mysum = 0;
    int me = omp_get_thread_num();
    int nth = omp_get_num_threads();
    for(int i=me; i < nval; i += nth) {
      mysum += procpairs(i, m, nval);
    }
    #pragma omp atomic
    tot += mysum;
  }
  int divisor = nval * (nval - 1)/2;
  *mlmean = ((float) tot) / divisor;
}
