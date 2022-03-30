#include<stdio.h>
#include<time.h>

int main(){
  
  int N=10;
  float a[N];
  float start=2.,time;
  clock_t begin,end;

  begin = clock();
  a[0]=start;

  for (int i=1;i<N;i++){
    double b = a[0];
    for (int j=0;j<i;j++){
      b=b*2;
    }
    a[i] = b;
    printf("Value: a[%d]=%.1f \n",i,a[i]);
  }

  end = clock();
  time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time %f ms \n",time);
}
