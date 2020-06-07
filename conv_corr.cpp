#include <iostream>
#include <Eigen/Dense>
#include <stdio.h>
#include <math.h>
using namespace Eigen;
using namespace std;
using Eigen::MatrixXd;

int main()
{
  int n; int i; int ff;
  cout << "Write the length of x[n] and h[n] : "<< endl;
    cin >> n;
    cin >> i;
  MatrixXd xn(1,n);
  MatrixXd hn(1,i);
  int y=n+i-1;
  double x1=ceil(y/2.0);
  double x=floor(y/2.0);
  MatrixXd yn(1,y);

  std::cout << "Write " << n << " factors for x[n] : "<< endl;
  for (int k=0;k<n;k++){
    std::cin >> xn(0,k);
  }
  std::cout << "Write " << i << " factors for h[n] : "<< endl;
  for (int j=0;j<i;j++){
    std::cin >> hn(0,j);
  }
  std::cout << "x[n]=  " << xn << endl;
  std::cout << "h[n]=  " << hn << endl;
  std::cout << "Select the type of operation" << endl << "1: convolution" << endl << "2: correlation  ";
  std::cin  >> ff;
  if (ff==1){
      for(int a=0;a<y;a++){
    if(a<static_cast<int>(x1)){
     for (int b=0;b<a+1;b++){
        yn(0,a) += xn(0,a-b)*hn(0,b);
     }
      }
    else{
      for (int c=a;c<y;c++){
        yn(0,a) += xn(0,a+n-1-c)*hn(0,c-y+i);
      }
    }
  }
    std::cout << "y[n]=x[n]*h[n]=  " << yn << endl;
  }
  else if (ff==2){
      MatrixXd hrn=hn.reverse();
        std::cout << hrn << endl;
      for(int a=0;a<y;a++){
    if(a<static_cast<int>(x1)){
     for (int b=0;b<a+1;b++){
        yn(0,a) += xn(0,a-b)*hrn(0,b);
     }
      }
    else{
      for (int c=a;c<y;c++){
        yn(0,a) += xn(0,a+n-1-c)*hrn(0,c-y+i);
      }
    }
  }
    std::cout << "Rxh[n]=x[n]**h[n]=  " << yn << endl;
  }
}