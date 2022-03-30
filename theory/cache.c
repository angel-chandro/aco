#include<stdio.h>
#include<stdlib.h>
//populate the arraay with random numbers from 0 to 99 with rand()%100
#include<time.h>

void main(){
  int i=0,j=0;
  double time=0.;
  clock_t begin,end;
  double density_1[2][3]={{0.}};
  double density_2[2][3]={{0.}};

  //1st option writing (faster)
  begin = clock();
  for (i=0;i<2;i++){
    for (j=0;j<3;j++){
      density_1[i][j] = rand()%100;
      printf("a[%i][%i] = %f \n",i,j,density_1[i][j]);
    }
  }
  end = clock();
  time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time writing an array from zero [outer][inner] = %f ms \n",time);

  //2st option writing (slower)
  begin = clock();
  for (j=0;j<3;j++){
    for (i=0;i<2;i++){
      density_2[i][j] = rand()%100;
      printf("a[%i][%i] = %f \n",i,j,density_2[i][j]);
    }
  }
  end = clock();
  time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time writing an array from zero [inner][outer] = %f ms \n",time);

  //1st option reading (faster)
  begin = clock();
  for (i=0;i<2;i++){
    for (j=0;j<3;j++){
      printf("a[%i][%i] = %f \n",i,j,density_1[i][j]);
    }
  }
  end = clock();
  time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time reading same array [outer][inner] = %f ms \n",time);

  //2st option reading (slower)
  begin = clock();
  for (j=0;j<3;j++){
    for (i=0;i<2;i++){
      printf("a[%i][%i] = %f \n",i,j,density_1[i][j]);
    }
  }
  end = clock();
  time = 1000.*(end-begin)/CLOCKS_PER_SEC; //ms
  printf("Time reading same array [inner][outer] = %f ms \n",time);

}
