#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	double factorial(int);    //階乘運算
	double myTan(double, int);    //tan(x)近似解計算
	double myExpTan(double, int);    //e^x*tan(x)近似解計算
	int choose, n;
	double x;
	cout <<"1. tan(x)\t2. e^x*tan(x)\n"<<"選擇函數(1 or 2):";
	cin >>choose;    //選擇功能
	cout <<"x=";
	cin >>x;    //輸入x
	cout <<"展開項次N=";
	cin >>n;    //輸入n
	cout <<"--------------------"<<endl;
	double * compute = new double[n]();    //宣告陣列
	double * error = new double[n]();
	double * meanError = new double[n]();
	double exact, totalError=0;
	ofstream outfile("Hw_3_answer.txt");    //宣告輸出檔案變數
	switch(choose){
		case 1:
			cout <<"tan(x)\nx="<<x<<"\tN="<<n<<endl;
			outfile <<"tan(x)\nx="<<x<<"\tN="<<n<<endl;
			exact = tan(x);    //解析解
			for(int i=0;i<n;i++){    //儲存結果
				compute[i] = myTan(x,i+1);    //近似解
			}
			break;
		case 2:
			cout <<"e^x*tan(x)\nx="<<x<<"\tN="<<n<<endl;
			outfile <<"e^x*tan(x)\nx="<<x<<"\tN="<<n<<endl;
			exact = exp(x)*tan(x);    //解析解
			for(int i=0;i<n;i++){    //儲存結果
				compute[i] = myExpTan(x,i+1);    //近似解
			}
			break;
		default:
			cout<<"輸入錯誤"<<endl;    //判斷例外
			break;
	}
	for(int i=0;i<n;i++){
		error[i] = exact-compute[i];    //誤差
		totalError += pow(error[i],2);    //誤差平方累加
		meanError[i] = sqrt(totalError/(i+1));    //平均誤差
	}
	cout <<"\nN\t"<<"近似解\t\t"<<"解析解\t\t"<<"誤差\t\t"<<"平均誤差"<<endl;
	outfile <<"\nN\t"<<"近似解\t\t"<<"解析解\t\t"<<"誤差\t\t\t"<<"平均誤差"<<endl;
	for(int i=0;i<n;i++){
		cout <<i+1<<"\t"<<compute[i]<<"\t\t"<<exact<<"\t\t"<<error[i]<<"\t\t"<<meanError[i]<<endl;    //顯示結果
		outfile <<i+1<<"\t"<<compute[i]<<"\t\t"<<exact<<"\t\t"<<error[i]<<"\t\t"<<meanError[i]<<endl;    //輸出結果
	}
	outfile.close();    //關閉檔案
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
用來計算階乘的function
輸入 : n值
輸出 : n!
*/
double factorial(int n){
	if(n==0){
		return 1;
	}
	return n*factorial(n-1);
}
/*
用來計算tan(x)泰勒展開的function
輸入 : x值、迭代次數n
輸出 : tan(x)的近似解
*/
double myTan(double x, int n){
	double sin=0, cos=0;
	for(int i=0;i<n;i++){
		sin += pow(-1,i)*pow(x,2*i+1)/factorial(2*i+1);
		cos += pow(-1,i)*pow(x,2*i)/factorial(2*i);
	}
	return sin/cos;
}
/*
用來計算e^x*tan(x)泰勒展開的function
輸入 : x值、迭代次數n
輸出 : e^x*tan(x)的近似解
*/
double myExpTan(double x, int n){
	double exp=0, tan;
	for(int i=0;i<n;i++){
		exp += pow(x,i)/factorial(i);
	}
	tan = myTan(x,n);
	return exp*tan;
}


