#include<stdio.h>
#include<math.h>
#include<time.h>

double summation(int k){

  double a = 0.;
  a = pow(-1./3.,k)/(2.*k+1.); //1.,3.,2. to consider as double and not int
  printf("Iteration: %d, Summation: %.10lf \n",k,a);
  return a;
}

void main(){

  clock_t begin,end;
  int N = 20;
  double b = 0.;

  begin = clock();
  for (int k=0;k<N;k++){
    b += summation(k);
  }
  double pi = sqrt(12)*b;
  end = clock();
  printf("Pi: %.10lf \n",pi);
  double time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time: %f ms \n",time);
    
}
