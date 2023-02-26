#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	void print(double[4][4]);    //列印矩陣function
	void print(double[4]);    //列印矩陣function
	void forward(double[4][4], double[4], double[4]);    //Forward Substitution
	void back(double[4][4], double[4], double[4]);    //Back Substitution
	void lu(double[4][4], double[4][4], double[4][4]);    //LU Decomposition
	double forward1[4][4] = {{1,0,0,0},{2,1,0,0},{-1,3,1,0},{6,2,-1,1}};
	double forward2[4] = {1,-1,-4,-4};
	double forward3[4] = {};
	forward(forward1,forward2,forward3);
	cout <<"Forward Substitution:"<<endl;
	print(forward3);
	double back1[4][4] = {{2,3,1,2},{0,3,-0.5,1},{0,0,5,2},{0,0,0,4}};
	double back2[4] = {1,-3,6,2};
	double back3[4] = {};
	back(back1,back2,back3);
	cout <<"Back Substitution:"<<endl;
	print(back3);
	double lu1[4][4] = {{2,3,1,2},{4,9,1.5,5},{-2,6,2.5,3},{12,24,0,16}};
	double lu2[4][4] = {};
	double lu3[4][4] = {};
	lu(lu1,lu2,lu3);
	cout <<"LU Decomposition:"<<endl;
	cout <<"A:"<<endl;
	print(lu1);
	cout <<"L:"<<endl;
	print(lu2);
	cout <<"U:"<<endl;
	print(lu3);
	
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
forward substitution求解 y
*/
void forward(double a[4][4], double b[4], double ans[4]){
	ans[0] = b[0]/a[0][0];
	for(int i=1;i<4;i++){
		for(int j=0;j<=i-1;j++){
			ans[i] += a[i][j]*ans[j];
		}
		ans[i] = (b[i]-ans[i])/a[i][i];
	}
}
/*
back substitution求解 x
*/
void back(double a[4][4], double b[4], double ans[4]){
	ans[3] = b[3]/a[3][3];
	for(int i=2;i>=0;i--){
		for(int j=i;j<4;j++){
			ans[i] += a[i][j]*ans[j];
		}
		ans[i] = (b[i]-ans[i])/a[i][i];
	}
}
/*
LU Decomposition求解 L U
*/
void lu(double a[4][4], double l[4][4], double u[4][4]){
	for(int k=0;k<4;k++){
		u[0][k] = a[0][k];
	}
	for(int j=0;j<4;j++){
		l[j][0] = a[j][0]/u[0][0];
		l[j][j] = 1;
	}
	for(int j=1;j<4;j++){
		for(int k=j;k<4;k++){
			for(int s=0;s<j;s++){
				u[j][k] += l[j][s]*u[s][k];
			}
			u[j][k] = a[j][k]-u[j][k];
		}
		if(j<3){
			for(int k=j+1;k<4;k++){
				for(int s=0;s<j;s++){
					l[k][j] += l[k][s]*u[s][j];
				}
				l[k][j] = (a[k][j]-l[k][j])/u[j][j];
			}
		}
	}
}
/*
輸出陣列至螢幕
*/
void print(double array[4][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}
/*
輸出陣列至螢幕
*/
void print(double array[4]){
	for(int i=0;i<4;i++){
		cout<<"x"<<i+1<<": "<<array[i]<<endl;
	}
	cout<<endl;
}

