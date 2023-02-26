#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
�D�{�� 
*/ 
int main() {
	ifstream infile("x_value.txt");    //�ŧiŪ���ɮ��ܼ�
	if(!infile){    //�ˬd�O�_���\Ū���ɮ� 
		cout<<"�L�k�}���ɮ�..."<<endl;
		return 0;
	}else{
		cout<<"Ū������...\n"<<endl;
	}
	double x[3], n=4, exp1, exp2, error;    //n=�i�}�����Aexp1=����ѡAexp2=�ѪR�ѡAerror=�~�t
	double myExp(double,int);    //�ŧifunction 
	infile>>x[0]>>x[1]>>x[2];    //�N�ɮפ����Ȩ̧ǩ�Jx�}�C 
	infile.close();    //�����ɮ� 
	ofstream outfile("Ex_1_answer.txt");    //�ŧi��X�ɮ��ܼ� 
	cout <<"f(x)"<<"\tN"<<"\t�����"<<"\t\t�ѪR��"<<"\t\t�~�t"<<endl;    //������O 
	outfile <<"f(x)"<<"\tN"<<"\t�����"<<"\t\t�ѪR��"<<"\t\t�~�t"<<endl;    //��X���O 
	for(int i=0;i<3;i++){
		exp1 = myExp(x[i],n);    //�I�smyExp�p������ 
		exp2 = exp(x[i]);    //�p��ѪR�� 
		error = (exp1-exp2)/exp2;    //�p��~�t 
		cout <<"e^"<<x[i]<<"\t"<<n<<"\t"<<exp1<<"\t\t"<<exp2<<"\t\t"<<error<<endl;    //��ܭp�⵲�G 
		outfile <<"e^"<<x[i]<<"\t"<<n<<"\t"<<exp1<<"\t\t"<<exp2<<"\t\t"<<error<<endl;    //��X�p�⵲�G 
	} 
	outfile.close();    //�����ɮ� 
	system("pause");    //�����N���~�� 
	return 0;
}
/*
�Ψӭp��e^x���Ǯi�}��function
��J : x�ȡB���N����n
��X : e^x������� 
*/ 
double myExp(double x, int n){
	double exp=0, k;
	for(int i=0;i<=n;i++){
		k = (i==0) ? 1 : k*i;    //k������ 
		exp += pow(x,i)/k;    //�p��ò֥[ 
	}
	return exp;
}
