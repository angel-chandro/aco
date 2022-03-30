#include<stdio.h>
#include<omp.h>
#include<time.h>

void main(){
  
  int N=10;
  float a[N];
  float start_value=2.,time;
  clock_t begin,end;

  begin = clock();
  double start = omp_get_wtime();
  a[0] = start_value;

  int i,j;
  double b;
  
#pragma omp parallel private(i,j,b) shared(a,N)
  {
    int ID = omp_get_thread_num();
    #pragma omp for
    for (i=1;i<N;i++){
      b = a[0];
      for (j=0;j<i;j++){
	b = b*2;
      }
      a[i] = b;
      printf("Thread %d,  Value: a[%d]=%.1f \n",ID,i,a[i]);
    }
  }
  double time_2 = 1000.*(omp_get_wtime()-start); //ms
  printf("Time omp %f ms \n",time_2);  
  end = clock();
  time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time %f ms \n",time);
}
