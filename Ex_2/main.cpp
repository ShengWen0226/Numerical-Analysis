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
	int num;    //xŪ�J�`��
	double finalError, error1, error2, exp1, exp2, realExp;
	//finalError=�ؼл~�t�Aerror1=��N���P��N+1�����t�Aerror2=����ѻP�ѪR�Ѫ��t�Aexp1=��N������ѡAexp2=��N+1������ѡArealExp=�ѪR��
	double myExp(double, int);    //�ŧifunction
	infile>>num;    //��Jx�`��
	double * x = new double[num];    //�ŧi�ʺA�}�C
	for(int i=0;i<num;i++){    //�Nx�s�J�}�C
		infile>>x[i];
	}
	infile>>finalError;    //�s�J�~�t
	infile.close();    //�����ɮ�
	ofstream outfile("Ex_2_answer.txt");    //�ŧi��X�ɮ��ܼ�
	cout <<setw(5)<<"x"<<setw(9)<<"N"<<setw(12)<<"�����"<<setw(18)<<"N�PN+1�����t"<<setw(18)<<"����P�ѪR�Ѯt"<<endl;    //������O
	outfile <<setw(9)<<"x"<<"\t\tN"<<"\t�����"<<"\t\tN�PN+1�����t"<<"\t����P�ѪR�Ѯt"<<endl;    //��X���O
	for(int j=0;j<num;j++){    //�̧�Ū��x
		realExp = exp(x[j]);    //�ѪR��
		int k, n=1;
		while(true){
			exp1 = myExp(x[j],n);    //��N��
			exp2 = myExp(x[j],n+1);    //��N+1��
			error1 = exp2 - exp1;    //��N���P��N+1�����t
			error2 = realExp - exp1;    //����ѻP�ѪR�Ѫ��t
			if(error1 < finalError){    //�P�_�~�t
				cout <<fixed<<setprecision(6)<<x[j]<<setw(6)<<n<<setw(14)<<exp1<<setw(14)<<error1<<setw(16)<<error2<<endl;    //��ܭp�⵲�G
				outfile <<fixed<<setprecision(6)<<x[j]<<"  \t"<<n<<"\t"<<exp1<<"  \t"<<error1<<"\t\t"<<error2<<endl;    //��X�p�⵲�G
				break;
			}
			n++;
		}
	}
	outfile.close();    //�����ɮ�
	delete x;    //����O����
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

