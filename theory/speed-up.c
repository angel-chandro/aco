#include<stdio.h>
#include<math.h>
#include<time.h>
#define pow3(x)((x)*(x)*(x))

void main(){
  double x=2.,a,time;
  clock_t begin,end;

  begin = clock();
  a=x*x*x;
  end = clock();
  time=1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time x*x*x=%E ms \n",time);

  begin = clock();
  a=pow(x,3);
  end = clock();
  time=1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time x*x*x=%E ms \n",time);

  begin = clock();
  a=pow3(x);
  end = clock();
  time=1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time x*x*x=%E ms \n",time);

  
}
  
  
  
