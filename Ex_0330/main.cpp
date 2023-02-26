#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
�D�{��
*/
int main() {
	double trapezoidal(double[], double);    //�ŧifunction
	double simpson(double[], double);
	double value[17];
	double dx = M_PI/16;    //x���ά�pi/8
	cout<<"x\t\t"<<"f(x)"<<endl;
	for(int i=0;i<=16;i++){
		value[i] = i*dx*cos(i*dx)*exp(-0.25*pow(i*dx,2));    //�p���ƭ�
		cout<<i*dx<<"  \t"<<value[i]<<endl;
	}
	cout<<"Trapezoidal Rule:"<<trapezoidal(value,dx)<<endl;
	cout<<"Simpson's Rule:"<<simpson(value,dx)<<endl;
	system("pause");    //�����N���~��
	return 0;
}
/*
����Trapezoidal Rule�p��n����
*/
double trapezoidal(double fun[], double dx){
	double area=0;
	for(int i=0;i<=15;i++){    //�p��n����
		area += (fun[i]+fun[i+1])*dx/2;
	}
	return area;
}
/*
����Simpson's Rule�p��L����
*/
double simpson(double fun[], double dx){
	double area=0;
	for(int i=0;i<=16;i++){    //�p��n����
		if(i==0 || i==16){
   			area += fun[i];
		}else if(i%2==1){
			area += 4*fun[i];
		}else{
			area += 2*fun[i];
		}
	}
	area *= dx/3;
	return area;
}


