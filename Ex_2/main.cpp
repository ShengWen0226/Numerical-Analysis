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
	int num;    //x讀入總數
	double finalError, error1, error2, exp1, exp2, realExp;
	//finalError=目標誤差，error1=第N項與第N+1項的差，error2=近似解與解析解的差，exp1=第N項近似解，exp2=第N+1項近似解，realExp=解析解
	double myExp(double, int);    //宣告function
	infile>>num;    //輸入x總數
	double * x = new double[num];    //宣告動態陣列
	for(int i=0;i<num;i++){    //將x存入陣列
		infile>>x[i];
	}
	infile>>finalError;    //存入誤差
	infile.close();    //關閉檔案
	ofstream outfile("Ex_2_answer.txt");    //宣告輸出檔案變數
	cout <<setw(5)<<"x"<<setw(9)<<"N"<<setw(12)<<"近似解"<<setw(18)<<"N與N+1項之差"<<setw(18)<<"近似與解析解差"<<endl;    //顯示類別
	outfile <<setw(9)<<"x"<<"\t\tN"<<"\t近似解"<<"\t\tN與N+1項之差"<<"\t近似與解析解差"<<endl;    //輸出類別
	for(int j=0;j<num;j++){    //依序讀取x
		realExp = exp(x[j]);    //解析解
		int k, n=1;
		while(true){
			exp1 = myExp(x[j],n);    //第N項
			exp2 = myExp(x[j],n+1);    //第N+1項
			error1 = exp2 - exp1;    //第N項與第N+1項的差
			error2 = realExp - exp1;    //近似解與解析解的差
			if(error1 < finalError){    //判斷誤差
				cout <<fixed<<setprecision(6)<<x[j]<<setw(6)<<n<<setw(14)<<exp1<<setw(14)<<error1<<setw(16)<<error2<<endl;    //顯示計算結果
				outfile <<fixed<<setprecision(6)<<x[j]<<"  \t"<<n<<"\t"<<exp1<<"  \t"<<error1<<"\t\t"<<error2<<endl;    //輸出計算結果
				break;
			}
			n++;
		}
	}
	outfile.close();    //關閉檔案
	delete x;    //釋放記憶體
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

