#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	void print(double **, int, int);    //列印矩陣function
	void ** multiply(double **, double **, double **, int, int, int);    //計算A*B function
	ifstream infile("2Darray.txt");    //宣告讀取檔案變數
	if(!infile){    //檢查是否成功讀取檔案
		cout <<"無法開啟檔案..."<<endl;
		return 0;
	}else{
		cout <<"讀取完成...\n"<<endl;
	}
	int num, aRow, aColumn, xRow, xColumn, yRow, yColumn;    //num為矩陣數量，row為列數，column為行數
 	for(int n=1;n<=3;n++){
		cout <<"第"<<n<<"題:"<<endl;
		infile >>num>>aRow>>aColumn;    //讀取A列數、行數
		double ** a = new double * [aRow];    //宣告a陣列
		for(int i=0;i<aRow;i++){
			a[i] = new double[aColumn]();   //初始化為0
		}
		for(int i=0;i<aRow;i++){    //將A矩陣放入a陣列
			for(int j=0;j<aColumn;j++){
				infile >> a[i][j];
			}
		}
		infile >>xRow>>xColumn;
		double ** x = new double * [xRow];
		for(int i=0;i<xRow;i++){
			x[i] = new double[xColumn]();
		}
		for(int i=0;i<xRow;i++){
			for(int j=0;j<xColumn;j++){
				infile >> x[i][j];
			}
		}
		double ** ans = new double * [aRow];
		for(int i=0;i<aRow;i++){
			ans[i] = new double[xColumn]();
		}
		cout <<"[A]"<<endl;
		print(a,aRow,aColumn);
		cout <<"[X]"<<endl;
		print(x,xRow,xColumn);
		multiply(a,x,ans,aRow,xRow,xColumn);
		cout <<"[A]*[X]"<<endl;
  		print(ans,aRow,xColumn);
		if(n==3){
	  		infile >>yRow>>yColumn;
			double ** y = new double * [yRow];
			for(int i=0;i<yRow;i++){
				y[i] = new double[yColumn]();
			}
			for(int i=0;i<yRow;i++){
				for(int j=0;j<yColumn;j++){
					infile >> y[i][j];
				}
			}
			double ** ans2 = new double * [aRow];
			for(int i=0;i<aRow;i++){
				ans2[i] = new double[yColumn]();
			}
   			cout <<"[Y]"<<endl;
   			print(y,yRow,yColumn);
   			cout <<"[A]*[X]*[Y]"<<endl;
   			multiply(ans,y,ans2,aRow,yRow,yColumn);
   			print(ans2,aRow,yColumn);
  		}else{
  			cout <<"---------------------------"<<endl;
		}

		for(int i=0;i<aRow;i++){    //釋放記憶體
			delete [] a[i];
			delete [] ans[i];
		}
		for(int i=0;i<xRow;i++){
			delete [] x[i];
		}
		delete [] a;
		delete [] ans;
		delete [] x;
 	}
	infile.close();    //關閉檔案
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
計算A*B=C
*/
void ** multiply(double ** a, double ** b, double ** c, int row, int row2, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			for(int k=0;k<row2;k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
/*
輸出陣列至螢幕
*/
void print(double ** array, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}
