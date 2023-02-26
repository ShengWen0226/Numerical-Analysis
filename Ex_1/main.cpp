#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式 
*/ 
int main() {
	ifstream infile("x_value.txt");    //宣告讀取檔案變數
	if(!infile){    //檢查是否成功讀取檔案 
		cout<<"無法開啟檔案..."<<endl;
		return 0;
	}else{
		cout<<"讀取完成...\n"<<endl;
	}
	double x[3], n=4, exp1, exp2, error;    //n=展開項次，exp1=近似解，exp2=解析解，error=誤差
	double myExp(double,int);    //宣告function 
	infile>>x[0]>>x[1]>>x[2];    //將檔案中的值依序放入x陣列 
	infile.close();    //關閉檔案 
	ofstream outfile("Ex_1_answer.txt");    //宣告輸出檔案變數 
	cout <<"f(x)"<<"\tN"<<"\t近似解"<<"\t\t解析解"<<"\t\t誤差"<<endl;    //顯示類別 
	outfile <<"f(x)"<<"\tN"<<"\t近似解"<<"\t\t解析解"<<"\t\t誤差"<<endl;    //輸出類別 
	for(int i=0;i<3;i++){
		exp1 = myExp(x[i],n);    //呼叫myExp計算近似解 
		exp2 = exp(x[i]);    //計算解析解 
		error = (exp1-exp2)/exp2;    //計算誤差 
		cout <<"e^"<<x[i]<<"\t"<<n<<"\t"<<exp1<<"\t\t"<<exp2<<"\t\t"<<error<<endl;    //顯示計算結果 
		outfile <<"e^"<<x[i]<<"\t"<<n<<"\t"<<exp1<<"\t\t"<<exp2<<"\t\t"<<error<<endl;    //輸出計算結果 
	} 
	outfile.close();    //關閉檔案 
	system("pause");    //按任意鍵繼續 
	return 0;
}
/*
用來計算e^x泰勒展開的function
輸入 : x值、迭代次數n
輸出 : e^x的近似解 
*/ 
double myExp(double x, int n){
	double exp=0, k;
	for(int i=0;i<=n;i++){
		k = (i==0) ? 1 : k*i;    //k為階乘 
		exp += pow(x,i)/k;    //計算並累加 
	}
	return exp;
}
