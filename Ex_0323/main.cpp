#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
�D�{��
*/
int main() {
	double central(double, double, double);    //�ŧifunction
	double forward(double, double, double, double);
	double backward(double, double, double, double);
	double value[17];
	double differential[17];
	double x = M_PI/8;    //x���ά�pi/8
	for(int i=-8;i<=8;i++){
		value[i+8] = i*x*cos(i*x)*exp(-0.25*pow(i*x,2));    //�p���ƭ�
	}
	for(int i=0;i<=16;i++){    //�p��L����
		if(i==0){
			differential[i] = forward(value[i],value[i+1],value[i+2],x);
		}else if(i==16){
			differential[i] = backward(value[i-2],value[i-1],value[i],x);
		}else{
			differential[i] = central(value[i-1],value[i+1],x);
		}
	}
	cout<<"N\t"<<"    x\t\t"<<"   f(x)\t\t"<<"  f'(x)"<<endl;    //��X�ܿù�
	for(int i=0;i<=16;i++){
		if(i==8){
			cout<<i+1<<"\t"<<(i-8)*x<<"  \t\t"<<value[i]<<"\t\t"<<differential[i]<<endl;
		}else{
			cout<<i+1<<"\t"<<(i-8)*x<<"  \t"<<value[i]<<"\t"<<differential[i]<<endl;
		}
	}
	
	system("pause");    //�����N���~��
	return 0;
}
/*
����central Differencing�p��L����
*/
double central(double f1, double f3, double x){
	return (f3-f1)/(2*x);
}
/*
����Forward Differencing�p��L����
*/
double forward(double f1, double f2, double f3, double x){
	return (-3*f1+4*f2-f3)/(2*x);
}
/*
����backward Differencing�p��L����
*/
double backward(double f1, double f2, double f3, double x){
	return (f1-4*f2+3*f3)/(2*x);
}
