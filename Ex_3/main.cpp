#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
主程式
*/
int main() {
	ifstream infile("2Darray.txt");    //宣告讀取檔案變數
	if(!infile){    //檢查是否成功讀取檔案
		cout<<"無法開啟檔案..."<<endl;
		return 0;
	}else{
		cout<<"讀取完成...\n"<<endl;
	}
	int row, column;    //row為列數，column為行數
	infile >>row>>column;    //讀取列數、行數
	int ** a = new int * [row];    //a陣列存放A矩陣
	int ** b = new int * [row];    //b陣列存放B矩陣
	int ** c = new int * [row];    //c陣列存放A+B
	int ** d = new int * [row];    //d陣列存放A-B
	int ** e = new int * [row];    //e陣列存放A*B
	for(int i=0;i<row;i++){
		a[i] = new int[column]();   //初始化為0
		b[i] = new int[column]();   //初始化為0
		c[i] = new int[column]();   //初始化為0
		d[i] = new int[column]();   //初始化為0
		e[i] = new int[column]();   //初始化為0
	}
	for(int i=0;i<row*2;i++){    //將A、B矩陣分別放入a、b陣列
		for(int j=0;j<column;j++){
			if(i<row){
				infile >> a[i][j];
			}else{
				infile >> b[i-row][j];
			}
		}
	}
	infile.close();    //關閉檔案
	void print(int **, int, int);    //列印功能function
	void ** add(int **, int **, int **, int, int);    //計算A+B功能function
	void ** subtract(int **, int **, int **, int, int);    //計算A-B功能function
	void ** multiply(int **, int **, int **, int, int);    //計算A*B功能function
	cout <<"A矩陣:"<<endl;    //計算及輸出至螢幕
	print(a,row,column);
	cout <<"B矩陣:"<<endl;
	print(b,row,column);
	cout <<"A+B:"<<endl;
	add(a,b,c,row,column);
	print(c,row,column);
	cout <<"A-B:"<<endl;
	subtract(a,b,d,row,column);
	print(d,row,column);
	cout <<"A*B:"<<endl;
	multiply(a,b,e,row,column);
	print(e,row,column);
	ofstream outfile("Ex_3_answer.txt");    //宣告輸出檔案變數
	outfile <<"A矩陣:"<<endl;    //輸出至檔案
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			outfile<<a[i][j]<<"\t";
		}
		outfile<<endl;
	}
	outfile<<endl;
	outfile <<"B矩陣:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			outfile<<b[i][j]<<"\t";
		}
		outfile<<endl;
	}
	outfile<<endl;
	outfile <<"A+B:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			outfile<<c[i][j]<<"\t";
		}
		outfile<<endl;
	}
	outfile<<endl;
	outfile <<"A-B:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			outfile<<d[i][j]<<"\t";
		}
		outfile<<endl;
	}
	outfile<<endl;
	outfile <<"A*B:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			outfile<<e[i][j]<<"\t";
		}
		outfile<<endl;
	}
	outfile<<endl;
	outfile.close();    //關閉檔案
	for(int i=0;i<row;i++){    //釋放記憶體
		delete [] a[i];
		delete [] b[i];
		delete [] c[i];
		delete [] d[i];
		delete [] e[i];
	}
	delete [] a;
	delete [] b;
	delete [] c;
	delete [] d;
	delete [] e;
	system("pause");    //按任意鍵繼續
	return 0;
}
/*
計算A+B
*/
void ** add(int ** a, int ** b, int ** c, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
/*
計算A-B
*/
void ** subtract(int ** a, int ** b, int ** d, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			d[i][j] = a[i][j] - b[i][j];
		}
	}
}
/*
計算A*B
*/
void ** multiply(int ** a, int ** b, int ** e, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			for(int k=0;k<row;k++){
				e[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
/*
輸出陣列至螢幕
*/
void print(int ** array, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

