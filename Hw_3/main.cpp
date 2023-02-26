#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
�D�{��
*/
int main() {
	double factorial(int);    //�����B��
	double myTan(double, int);    //tan(x)����ѭp��
	double myExpTan(double, int);    //e^x*tan(x)����ѭp��
	int choose, n;
	double x;
	cout <<"1. tan(x)\t2. e^x*tan(x)\n"<<"��ܨ��(1 or 2):";
	cin >>choose;    //��ܥ\��
	cout <<"x=";
	cin >>x;    //��Jx
	cout <<"�i�}����N=";
	cin >>n;    //��Jn
	cout <<"--------------------"<<endl;
	double * compute = new double[n]();    //�ŧi�}�C
	double * error = new double[n]();
	double * meanError = new double[n]();
	double exact, totalError=0;
	ofstream outfile("Hw_3_answer.txt");    //�ŧi��X�ɮ��ܼ�
	switch(choose){
		case 1:
			cout <<"tan(x)\nx="<<x<<"\tN="<<n<<endl;
			outfile <<"tan(x)\nx="<<x<<"\tN="<<n<<endl;
			exact = tan(x);    //�ѪR��
			for(int i=0;i<n;i++){    //�x�s���G
				compute[i] = myTan(x,i+1);    //�����
			}
			break;
		case 2:
			cout <<"e^x*tan(x)\nx="<<x<<"\tN="<<n<<endl;
			outfile <<"e^x*tan(x)\nx="<<x<<"\tN="<<n<<endl;
			exact = exp(x)*tan(x);    //�ѪR��
			for(int i=0;i<n;i++){    //�x�s���G
				compute[i] = myExpTan(x,i+1);    //�����
			}
			break;
		default:
			cout<<"��J���~"<<endl;    //�P�_�ҥ~
			break;
	}
	for(int i=0;i<n;i++){
		error[i] = exact-compute[i];    //�~�t
		totalError += pow(error[i],2);    //�~�t����֥[
		meanError[i] = sqrt(totalError/(i+1));    //�����~�t
	}
	cout <<"\nN\t"<<"�����\t\t"<<"�ѪR��\t\t"<<"�~�t\t\t"<<"�����~�t"<<endl;
	outfile <<"\nN\t"<<"�����\t\t"<<"�ѪR��\t\t"<<"�~�t\t\t\t"<<"�����~�t"<<endl;
	for(int i=0;i<n;i++){
		cout <<i+1<<"\t"<<compute[i]<<"\t\t"<<exact<<"\t\t"<<error[i]<<"\t\t"<<meanError[i]<<endl;    //��ܵ��G
		outfile <<i+1<<"\t"<<compute[i]<<"\t\t"<<exact<<"\t\t"<<error[i]<<"\t\t"<<meanError[i]<<endl;    //��X���G
	}
	outfile.close();    //�����ɮ�
	system("pause");    //�����N���~��
	return 0;
}
/*
�Ψӭp�ⶥ����function
��J : n��
��X : n!
*/
double factorial(int n){
	if(n==0){
		return 1;
	}
	return n*factorial(n-1);
}
/*
�Ψӭp��tan(x)���Ǯi�}��function
��J : x�ȡB���N����n
��X : tan(x)�������
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
�Ψӭp��e^x*tan(x)���Ǯi�}��function
��J : x�ȡB���N����n
��X : e^x*tan(x)�������
*/
double myExpTan(double x, int n){
	double exp=0, tan;
	for(int i=0;i<n;i++){
		exp += pow(x,i)/factorial(i);
	}
	tan = myTan(x,n);
	return exp*tan;
}


