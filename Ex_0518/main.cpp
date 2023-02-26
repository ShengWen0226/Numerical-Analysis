#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	double fun(double);    //宣告function
	cout<<"二分法:"<<endl;
	double a=30, b=0, c=(b+a)/2;
	//cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<b-c<<"\t"<<fun(c)<<endl;
	while(true){
		if(fun(c)>0){
			b=c;
		}else{
			a=c;
		}
		c=(b+a)/2;
		//cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<b-c<<"\t"<<fun(c)<<endl;
		if(fabs(b-c)<pow(10,-4)){
			cout<<c<<endl;
			break;
		}
	}
	cout<<"牛頓法:"<<endl;
	double x=30, x2;
	x2=fun(x)/((fun(x+0.01)-fun(x-0.01))/0.02);
	while(true){
		x=x2-fun(x2)/((fun(x2+0.0001)-fun(x2-0.0001))/0.0002);
		//cout<<x<<"\t"<<x2<<"\t"<<27.9602-x2<<endl;
		if(fabs(27.9602-x2)<pow(10,-4)){
			cout<<x<<endl;
			break;
		}
		x2=x;
	}
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
計算函數值
*/
double fun(double x){
	return 0.1+fabs(x)*(pow(cos(0.1*fabs(x)),5)+pow(cos(0.05*fabs(x)),2))/(2*cosh(sqrt(fabs(x))));
}



