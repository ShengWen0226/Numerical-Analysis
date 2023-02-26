#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
�D�{��
*/
int main() {
	ifstream infile("2Darray.txt");    //�ŧiŪ���ɮ��ܼ�
	if(!infile){    //�ˬd�O�_���\Ū���ɮ�
		cout<<"�L�k�}���ɮ�..."<<endl;
		return 0;
	}else{
		cout<<"Ū������...\n"<<endl;
	}
	int row, column;    //row���C�ơAcolumn�����
	infile >>row>>column;    //Ū���C�ơB���
	int ** a = new int * [row];    //a�}�C�s��A�x�}
	int ** b = new int * [row];    //b�}�C�s��B�x�}
	int ** c = new int * [row];    //c�}�C�s��A+B
	int ** d = new int * [row];    //d�}�C�s��A-B
	int ** e = new int * [row];    //e�}�C�s��A*B
	for(int i=0;i<row;i++){
		a[i] = new int[column]();   //��l�Ƭ�0
		b[i] = new int[column]();   //��l�Ƭ�0
		c[i] = new int[column]();   //��l�Ƭ�0
		d[i] = new int[column]();   //��l�Ƭ�0
		e[i] = new int[column]();   //��l�Ƭ�0
	}
	for(int i=0;i<row*2;i++){    //�NA�BB�x�}���O��Ja�Bb�}�C
		for(int j=0;j<column;j++){
			if(i<row){
				infile >> a[i][j];
			}else{
				infile >> b[i-row][j];
			}
		}
	}
	infile.close();    //�����ɮ�
	void print(int **, int, int);    //�C�L�\��function
	void ** add(int **, int **, int **, int, int);    //�p��A+B�\��function
	void ** subtract(int **, int **, int **, int, int);    //�p��A-B�\��function
	void ** multiply(int **, int **, int **, int, int);    //�p��A*B�\��function
	cout <<"A�x�}:"<<endl;    //�p��ο�X�ܿù�
	print(a,row,column);
	cout <<"B�x�}:"<<endl;
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
	ofstream outfile("Ex_3_answer.txt");    //�ŧi��X�ɮ��ܼ�
	outfile <<"A�x�}:"<<endl;    //��X���ɮ�
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			outfile<<a[i][j]<<"\t";
		}
		outfile<<endl;
	}
	outfile<<endl;
	outfile <<"B�x�}:"<<endl;
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
	outfile.close();    //�����ɮ�
	for(int i=0;i<row;i++){    //����O����
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
	system("pause");    //�����N���~��
	return 0;
}
/*
�p��A+B
*/
void ** add(int ** a, int ** b, int ** c, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
/*
�p��A-B
*/
void ** subtract(int ** a, int ** b, int ** d, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			d[i][j] = a[i][j] - b[i][j];
		}
	}
}
/*
�p��A*B
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
��X�}�C�ܿù�
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

