#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	double trapezoidal(double[], double);    //宣告function
	double simpson(double[], double);
	double value[17];
	double dx = M_PI/16;    //x分割為pi/8
	cout<<"x\t\t"<<"f(x)"<<endl;
	for(int i=0;i<=16;i++){
		value[i] = i*dx*cos(i*dx)*exp(-0.25*pow(i*dx,2));    //計算函數值
		cout<<i*dx<<"  \t"<<value[i]<<endl;
	}
	cout<<"Trapezoidal Rule:"<<trapezoidal(value,dx)<<endl;
	cout<<"Simpson's Rule:"<<simpson(value,dx)<<endl;
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
應用Trapezoidal Rule計算積分值
*/
double trapezoidal(double fun[], double dx){
	double area=0;
	for(int i=0;i<=15;i++){    //計算積分值
		area += (fun[i]+fun[i+1])*dx/2;
	}
	return area;
}
/*
應用Simpson's Rule計算微分值
*/
double simpson(double fun[], double dx){
	double area=0;
	for(int i=0;i<=16;i++){    //計算積分值
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


