#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
�D�{��
*/
int main() {
	void print(double **, int, int);    //�C�L�x�}function
	void ** multiply(double **, double **, double **, int, int, int);    //�p��A*B function
	ifstream infile("2Darray.txt");    //�ŧiŪ���ɮ��ܼ�
	if(!infile){    //�ˬd�O�_���\Ū���ɮ�
		cout <<"�L�k�}���ɮ�..."<<endl;
		return 0;
	}else{
		cout <<"Ū������...\n"<<endl;
	}
	int num, aRow, aColumn, xRow, xColumn, yRow, yColumn;    //num���x�}�ƶq�Arow���C�ơAcolumn�����
 	for(int n=1;n<=3;n++){
		cout <<"��"<<n<<"�D:"<<endl;
		infile >>num>>aRow>>aColumn;    //Ū��A�C�ơB���
		double ** a = new double * [aRow];    //�ŧia�}�C
		for(int i=0;i<aRow;i++){
			a[i] = new double[aColumn]();   //��l�Ƭ�0
		}
		for(int i=0;i<aRow;i++){    //�NA�x�}��Ja�}�C
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

		for(int i=0;i<aRow;i++){    //����O����
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
	infile.close();    //�����ɮ�
	system("pause");    //�����N���~��
	return 0;
}
/*
�p��A*B=C
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
��X�}�C�ܿù�
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
