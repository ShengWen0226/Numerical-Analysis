#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	ifstream infile("hw5.dat");
	if(!infile){    //檢查是否成功讀取檔案
		cout<<"無法開啟檔案..."<<endl;
		return 0;
	}else{
		cout<<"讀取完成...\n"<<endl;
	}
	double data[2][220];
	for(int i=0;i<220;i++){    //存入座標
		infile>>data[0][i]>>data[1][i];
	}
	infile.close();    //關閉檔案
	void lu(double[7][7], double[7][7], double[7][7], int);
	void forward(double[7][7], double[7], double[7], int);
	void back(double[7][7], double[7], double[7], int);
	void print(double[7][7], int);
	void print(double[7], int);
	void function(double[7], int);
	void draw(double[7]);
	void error(double[2][220],double[7]);
	while(true){
		double x[7][7]={0};
		double y[7]={0};
		cout<<"輸入多項式冪次(1~6):";
		int num;
		cin>>num;
		num++;
		cout<<endl;
		for(int i=0;i<num;i++){    //X矩陣
			for(int j=0;j<num;j++){
				for(int k=0;k<220;k++){
					x[i][j]+=pow(data[0][k],i+j);
				}
			}
		}
		for(int i=0;i<num;i++){    //Y矩陣
			for(int k=0;k<220;k++){
				y[i]+=pow(data[0][k],i)*data[1][k];
			}
		}
		double l[7][7]={0};
		double u[7][7]={0};
		double b[7]={0};
		double a[7]={0};
		lu(x,l,u,num);    //X分解為LU
		forward(l,y,b,num);    //LY求出b
		back(u,b,a,num);    //Ub求出係數a
		/*
		cout<<"[x]="<<endl;
		print(x,num);
		cout<<"[y]="<<endl;
		print(y,num);
		cout<<"[L]="<<endl;
		print(l,num);
		cout<<"[U]="<<endl;
		print(u,num);
		cout<<"[b]="<<endl;
		print(b,num);
		cout<<"[a]="<<endl;
		*/
		print(a,num);
		function(a,num);
		int choose;
		while(true){
			cout<<"(0)列印曲線座標 (1)誤差計算 (2)重新選擇 (3)結束\n選擇:";
			cin>>choose;
			cout<<endl;
			if(choose==0){
				draw(a);
				continue;
			}else if(choose==1){
				error(data,a);
				continue;
			}else if(choose==2){
				break;
			}else if(choose==3){
				return 0;
			}
		}
		cout<<"\n-----------------------------------\n"<<endl;
	}
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
LU Decomposition
*/
void lu(double x[7][7], double l[7][7], double u[7][7], int num){
	for(int k=0;k<num;k++){
		u[0][k] = x[0][k];
	}
	for(int j=0;j<num;j++){
		l[j][0] = x[j][0]/u[0][0];
		l[j][j] = 1;
	}
	for(int j=1;j<num;j++){
		for(int k=j;k<num;k++){
			for(int s=0;s<j;s++){
				u[j][k] += l[j][s]*u[s][k];
			}
			u[j][k] = x[j][k]-u[j][k];
		}
		if(j<num-1){
			for(int k=j+1;k<num;k++){
				for(int s=0;s<j;s++){
					l[k][j] += l[k][s]*u[s][j];
				}
				l[k][j] = (x[k][j]-l[k][j])/u[j][j];
			}
		}
	}
}
/*
forward substitution
*/
void forward(double l[7][7], double y[7], double b[7], int num){
	b[0] = y[0]/l[0][0];
	for(int i=1;i<num;i++){
		for(int j=0;j<=i-1;j++){
			b[i] += l[i][j]*b[j];
		}
		b[i] = (y[i]-b[i])/l[i][i];
	}
}
/*
back substitution
*/
void back(double u[7][7], double b[7], double a[7], int num){
	a[num-1] = b[num-1]/u[num-1][num-1];
	for(int i=num-2;i>=0;i--){
		for(int j=i;j<num;j++){
			a[i] += u[i][j]*a[j];
		}
		a[i] = (b[i]-a[i])/u[i][i];
	}
}
/*
print
*/
void print(double array[7][7], int num){
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}
void print(double array[7], int num){
	for(int i=0;i<num;i++){
		cout<<"a"<<i<<"="<<array[i]<<endl;
	}
	cout<<endl;
}
void function(double array[7], int num){
	cout<<"f(x)="<<array[0];
	for(int i=1;i<num;i++){
		if(array[i]>0){
			cout<<"+";
		}
		cout<<array[i]<<"*x^"<<i;
	}
	cout<<"\n"<<endl;
}
void draw(double a[7]){
	double y=0;
	for(double i=0;i<=5.6;i+=0.1){
		for(int j=0;j<7;j++){
			y+=a[j]*pow(i,j);
		}
		cout<<i<<"\t"<<y<<endl;
		y=0;
	}
	cout<<endl;
}
/*
error
*/
void error(double data[2][220], double a[7]){
	double y=0, error=0, sum=0;
	for(int i=0;i<220;i++){
		for(int j=0;j<7;j++){
			y+=a[j]*pow(data[0][i],j);
		}
		error=(fabs(y-data[1][i])>error)?fabs(y-data[1][i]):error;
		sum+=fabs(y-data[1][i]);
		y=0;
	}
	cout<<"最大誤差="<<error<<endl;
	cout<<"平均誤差="<<sum/220<<endl;
	cout<<endl;
}
