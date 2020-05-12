#include <iostream>
#include <Eigen/Dense>
#include <stdio.h>
using namespace Eigen;
using namespace std;
using Eigen::MatrixXd;

int main()
{
  int n; int i;
  MatrixXd xn(1,3);
  MatrixXd hn(1,3);
  MatrixXd yn(1,5);
  cout << "Write 3 factors for x[n] : "<< endl;
  cin >> xn(0,0);
  cin >> xn(0,1);
  cin >> xn(0,2);
  cout << "x[n] = " << xn << endl;
  cout << "Write 3 factors for h[n] : "<< endl;
  cin >> hn(0,0);
  cin >> hn(0,1);
  cin >> hn(0,2);
  cout << "h[n] = " << hn << endl;
  yn(0,0)=xn(0,0)*hn(0,0);
  yn(0,1)=xn(0,1)*hn(0,0)+xn(0,0)*hn(0,1);
  yn(0,2)=xn(0,2)*hn(0,0)+xn(0,1)*hn(0,1)+xn(0,0)*hn(0,2);
  yn(0,3)=xn(0,2)*hn(0,1)+xn(0,1)*hn(0,2);
  yn(0,4)=xn(0,2)*hn(0,2);
  cout << "y[n]=x[n]*h[n]=  " << yn << endl;
}
