#include<stdio.h>
#include<math.h>
#include<time.h>
#include<omp.h>

double summation(int k){

  double a = 0.;
  a = pow(-1./3.,k)/(2.*k+1.); //1. to consider as double and not int
  printf("Iteration: %d, Summation: %.10lf \n",k,a);
  return a;
}

void main(){

  clock_t begin,end;
  int N = 14;
  double sum = 0.;
  int chunk = 5;
  begin = clock();
  double start = omp_get_wtime();
#pragma omp parallel for shared(N) reduction(+:sum) schedule(static,chunk)
  for (int k=0;k<N;k++){
    sum += summation(k);
    int ID = omp_get_thread_num();
    printf("Thread: %d , Iteration: %d \n",ID,k);
  }
  double pi = sqrt(12)*sum;
  end = clock();
  double time_omp = 1000.*(omp_get_wtime()-start);
  printf("Pi: %.10lf \n",pi);
  printf("Time omp: %f ms \n",time_omp);
  double time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time: %f ms \n",time);
    
}
