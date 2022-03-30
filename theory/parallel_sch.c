#include<stdio.h>
#include<omp.h>
#include<time.h>

double calc_b(int i,double sv){
  double b;
  int j;

  b = sv;
  for (j=0;j<i;j++){
    b = b*2;
  }
  return b;
}

void main(){
  
  int N=10;
  float a[N];
  float start_value=2.,time;
  clock_t begin,end;
  omp_set_num_threads(3);
  begin = clock();
  double start = omp_get_wtime();
  a[0] = start_value;
  int i;
  //int chunk = 3;
  
#pragma omp parallel private(i) shared(a,N)
  {
    int ID = omp_get_thread_num();
#pragma omp for schedule(dynamic)
    //#pragma omp for schedule(static,chunk)    
    for (i=1;i<N;i++){
      a[i] = calc_b(i,a[0]);
      printf("Thread %d,  Value: a[%d]=%.1f \n",ID,i,a[i]);
    }
  }
  double time_2 = 1000.*(omp_get_wtime()-start); //ms
  printf("Time omp %f ms \n",time_2);  
  end = clock();
  time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time %f ms \n",time);
}
