# include <stdlib.h>
# include <stdio.h>
# include <omp.h>

int main ( int argc, char *argv[] ){

  int n = 500000;
  int not_primes=1;
  int i,j;

  double  start_time = omp_get_wtime();

  #pragma omp parallel for private (j) reduction(+:not_primes) schedule(dynamic)
  for ( i = 3; i <= n; i = i + 2 ){
    for ( j = 3; j < i; j = j + 2 ){
      if ( i % j == 0 ){
        not_primes++;
        break;
      }
    }
  }

  double  total_time = omp_get_wtime() - start_time;

  printf("Primes: %d   Time: %f \n", n / 2 - not_primes + 2, total_time);

  return 0;
}

