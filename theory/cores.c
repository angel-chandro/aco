#include<stdio.h>
#include<omp.h>

void main(){
  #pragma omp parallel
  // say we are running st in parallel
  {
    int ID = omp_get_thread_num();
    printf("hello(%d) \n",ID);
  }
}
