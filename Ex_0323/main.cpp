#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	double central(double, double, double);    //宣告function
	double forward(double, double, double, double);
	double backward(double, double, double, double);
	double value[17];
	double differential[17];
	double x = M_PI/8;    //x分割為pi/8
	for(int i=-8;i<=8;i++){
		value[i+8] = i*x*cos(i*x)*exp(-0.25*pow(i*x,2));    //計算函數值
	}
	for(int i=0;i<=16;i++){    //計算微分值
		if(i==0){
			differential[i] = forward(value[i],value[i+1],value[i+2],x);
		}else if(i==16){
			differential[i] = backward(value[i-2],value[i-1],value[i],x);
		}else{
			differential[i] = central(value[i-1],value[i+1],x);
		}
	}
	cout<<"N\t"<<"    x\t\t"<<"   f(x)\t\t"<<"  f'(x)"<<endl;    //輸出至螢幕
	for(int i=0;i<=16;i++){
		if(i==8){
			cout<<i+1<<"\t"<<(i-8)*x<<"  \t\t"<<value[i]<<"\t\t"<<differential[i]<<endl;
		}else{
			cout<<i+1<<"\t"<<(i-8)*x<<"  \t"<<value[i]<<"\t"<<differential[i]<<endl;
		}
	}
	
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
應用central Differencing計算微分值
*/
double central(double f1, double f3, double x){
	return (f3-f1)/(2*x);
}
/*
應用Forward Differencing計算微分值
*/
double forward(double f1, double f2, double f3, double x){
	return (-3*f1+4*f2-f3)/(2*x);
}
/*
應用backward Differencing計算微分值
*/
double backward(double f1, double f2, double f3, double x){
	return (f1-4*f2+3*f3)/(2*x);
}
