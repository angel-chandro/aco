#include<stdio.h>

int main(){
  
  int N=10;
  float a[N];
  float start=2.;

  a[0]=start;

  for (int i=1;i<N;i++){
    a[i]=a[i-1]*2;
    printf("Value: a[%d]=%.1f \n",i,a[i]);
  }


}
