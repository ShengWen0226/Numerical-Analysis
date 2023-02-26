#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	void function(double*, double, int);    //宣告function
	double function(double);
	double trapezoidal(double*, double, int);
	double simpson(double*, double, int);
	double gauss(int, int);
	cout<<"(1)trapezoidal  (2)simpson  (3)all\n選擇計算方法:";
	int choose;
	cin>>choose;
	cout<<"輸入N值(0為預設:8,16,32,...,1024)\nN=";
	int n=0;
	cin>>n;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	double exact=-0.02114169751102201,error1,error2;
	if(n==0){
		switch(choose){
		case 1:
			cout<<"N\t"<<"Exact\t\t"<<"Trapezoidal\t"<<"error"<<endl;
			break;
		case 2:
			cout<<"N\t"<<"Exact\t\t"<<"Simpson\t\t"<<"error"<<endl;
			break;
		case 3:
			cout<<"N\t"<<"Exact\t\t"<<"Trapezoidal\t"<<"error1\t\t"<<"Simpson\t\t"<<"error2"<<endl;
			break;
		default:
			cout<<"輸入錯誤"<<endl;    //判斷例外
			break;
		}
		for(int i=8;i<=1024;i*=2){
			double dx=M_PI/i;
			double * value = new double[i+1];
			function(value,dx,i);
			switch(choose){
			case 1:
				error1=trapezoidal(value,dx,i)-exact;
				cout<<i<<"\t"<<exact<<"\t"<<trapezoidal(value,dx,i)<<"\t"<<error1<<endl;
				break;
			case 2:
				error1=simpson(value,dx,i)-exact;
				cout<<i<<"\t"<<exact<<"\t"<<simpson(value,dx,i)<<"\t"<<error1<<endl;
				break;
			case 3:
				error1=trapezoidal(value,dx,i)-exact;
				error2=simpson(value,dx,i)-exact;
				cout<<i<<"\t"<<exact<<"\t"<<trapezoidal(value,dx,i)<<"\t"<<error1<<"\t"<<simpson(value,dx,i)<<"\t"<<error2<<endl;
				break;
			}
			delete[] value;
		}
	}else{
		double dx=M_PI/n;
		double * value = new double[n+1];
		function(value,dx,n);
		switch(choose){
		case 1:
			error1=trapezoidal(value,dx,n)-exact;
			cout<<"N\t"<<"Exact\t\t"<<"Trapezoidal\t"<<"error"<<endl;
			cout<<n<<"\t"<<exact<<"\t"<<trapezoidal(value,dx,n)<<"\t"<<error1<<endl;
			break;
		case 2:
			error1=simpson(value,dx,n)-exact;
			cout<<"N\t"<<"Exact\t\t"<<"Simpson\t\t"<<"error"<<endl;
			cout<<n<<"\t"<<exact<<"\t"<<simpson(value,dx,n)<<"\t"<<error1<<endl;
			break;
		case 3:
			error1=trapezoidal(value,dx,n)-exact;
			error2=simpson(value,dx,n)-exact;
			cout<<"N\t"<<"Exact\t\t"<<"Trapezoidal\t"<<"error1\t\t"<<"Simpson\t\t"<<"error2"<<endl;
			cout<<n<<"\t"<<exact<<"\t"<<trapezoidal(value,dx,n)<<"\t"<<error1<<"\t"<<simpson(value,dx,n)<<"\t"<<error2<<endl;
			break;
		default:
			cout<<"輸入錯誤"<<endl;    //判斷例外
			break;
		}
		delete[] value;
	}
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"Gauss Quadratures\nN=1,2,4,...,128\nM=2,3"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"N\t"<<"Exact\t\t"<<"Gauss (M=2)\t"<<"error1\t\t"<<"Gauss (M=3)\t"<<"error2"<<endl;
	for(int i=1;i<=128;i*=2){
		error1=gauss(2,i)-exact;
		error2=gauss(3,i)-exact;
		cout<<i<<"\t"<<exact<<"\t"<<gauss(2,i)<<"\t"<<error1<<"\t"<<gauss(3,i)<<"\t"<<error2<<endl;
	}
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"Gauss Quadratures\nN=1\nM=2,3,4,5,6"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"M\t"<<"N\t"<<"Exact\t\t"<<"Gauss\t\t"<<"error"<<endl;
	for(int i=2;i<=6;i++){
		error1=gauss(i,1)-exact;
		cout<<i<<"\t"<<1<<"\t"<<exact<<"\t"<<gauss(i,1)<<"\t"<<error1<<endl;
	}
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
計算函數值
*/
void function(double* value, double dx, int n){
	for(int i=0;i<=n;i++){
		value[i] = i*dx*cos(i*dx)/exp(0.25*pow(i*dx,2));
	}
}
double function(double x){
	return x*cos(x)/exp(0.25*pow(x,2));
}
/*
應用Trapezoidal Rule計算積分值
*/
double trapezoidal(double* fun, double dx, int n){
	double area=0;
	for(int i=0;i<=n;i++){    //計算積分值
		area += (fun[i]+fun[i+1])*dx/2;
	}
	return area;
}
/*
應用Simpson's Rule計算積分值
*/
double simpson(double* fun, double dx, int n){
	double area=0;
	for(int i=0;i<=n;i++){    //計算積分值
		if(i==0 || i==n){
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
/*
應用Gauss Quadratures計算積分值
*/
double gauss(int m, int n){
	double x[5][6] = {{1/sqrt(3),-1/sqrt(3),0,0,0,0},
						{0,0.77459667,-0.77459667,0,0,0},
						{0.33998104,-0.33998104,0.86113631,-0.86113631,0,0},
						{0,0.53846931,-0.53846931,0.90617985,-0.90617985,0},
						{0.23861918,-0.23861918,0.66120939,-0.66120939,0.93246951,-0.93246951}};
	double w[5][6] = {{1,1,0,0,0,0},
						{0.88888889,0.55555555,0.55555555,0,0,0},
						{0.65214515,0.65214515,0.34785485,0.34785485,0,0},
						{0.56888889,0.47862867,0.47862867,0.23692689,0.23692689,0},
						{0.46791393,0.46791393,0.36076157,0.36076157,0.17132449,0.17132449}};
	double dx=M_PI/n, x1=0, x2=dx, integral=0, sum=0;
	for(int i=1;i<=n;i++){
		sum = 0;
		for(int i=0;i<m;i++){
			sum += w[m-2][i]*function((dx*x[m-2][i]+x1+x2)/2);
		}
		integral += dx*sum/2;
		x1=x2;
		x2+=dx;
	}
	return integral;
}

