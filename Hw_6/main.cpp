#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;
/*
�D�{��
*/
int main() {
	ifstream infile("data22.dat");
	if(!infile){    //�ˬd�O�_���\Ū���ɮ�
		cout<<"�L�k�}���ɮ�..."<<endl;
		return 0;
	}else{
		cout<<"Ū������...\n"<<endl;
	}
	double data[2][15];
	for(int i=0;i<15;i++){    //�s�J�y��
		infile>>data[0][i]>>data[1][i];
	}
	infile.close();    //�����ɮ�
	double getLoc(double, double[2][15]);
	double getY(double, double[14][4], double[2][15]);
	double getYY(double, double[14][4], double[2][15]);
	double getYYY(double, double[14][4], double[2][15]);
	void lu(double[15][15], double[15][15], double[15][15]);
	void forward(double[15][15], double[15], double[15]);
	void back(double[15][15], double[15], double[15]);
	void print(double[101], double[101]);
	void print(double[14][4]);
	void print(double[15][15]);
	void print(double[15]);
	void Bisection(double[14][4], double[2][15]);
	void Bisection(double[14][4], double[2][15],double,double);
	void Newton(double[14][4], double[2][15]);
	void Newton(double[14][4], double[2][15],double);
	void Newton2(double[14][4], double[2][15]);
	void Newton2(double[14][4], double[2][15],double);
	double x[101]={0};
	double y[101]={0};
	double h[14];
	double d[14];
	double a[15][15]={0};
	double l[15][15]={0};
	double u[15][15]={0};
	double b[15]={0};
	double c[15]={0};
	double p[15]={0};
	double n[14][4];    //��{���Y��
	/**********************************�D�ѫY��**********************************/
	for(int i=0;i<14;i++){    //�p��h��
		h[i] = data[0][i+1]-data[0][i];
	}
	for(int i=0;i<14;i++){    //�p��D��
		d[i] = (data[1][i+1]-data[1][i])/h[i];
	}
	a[0][0] = 1;
	a[14][14] = 1;
	for(int i=1;i<14;i++){    //�p��a�x�}
		a[i][i] = 2*(h[i-1]+h[i]);
		a[i][i-1] = h[i-1];
		a[i][i+1] = h[i];
	}
	for(int i=0;i<15;i++){    //�p��b�x�}
		b[i] = (i==0||i==14)?0:6*(d[i]-d[i-1]);
	}
	lu(a,l,u);    //a���Ѭ�LU
	forward(l,b,c);    //Lb�D�Xc
	back(u,c,p);    //Uc�D�X�Y��p
	for(int i=0;i<14;i++){    //�p��Y��
		n[i][0] = (p[i+1]-p[i])/(6*h[i]);    //a
		n[i][1] = p[i]/2;    //b
		n[i][2] = ((data[1][i+1]-data[1][i])/h[i])-((2*h[i]*p[i]+h[i]*p[i+1])/6);    //c
		n[i][3] = data[1][i];    //d
	}
	//print(p);    //���v
	//print(n);    //�Y��
	for(int i=0;i<101;i++){    //���wx��
		x[i] = 6.0*i/100;
	}
	for(int i=0;i<101;i++){    //�p��y��
		y[i] = getY(x[i],n,data);
	}
	//print(x,y);    //�y���I
	/**********************************�D�ѷ���**********************************/
	//Bisection(n,data);    //�G���k
	//Newton(n,data);    //���y�k(�ήt���k)
	//Newton2(n,data);    //���y�k(�Τ�����u�D�ɼ�)

	int choose;
	double aa,bb,xx;
	cout<<"(1)�G���k (2)���y�k-�t���k (3)���y�k-������u\n���:";
	cin>>choose;
	if(choose==1){
		cout<<"��J��l�q��\n���Ѭ�(0,1),(3,2),(5,6)\na=";
		cin>>aa;
		cout<<"b=";
		cin>>bb;
		Bisection(n,data,aa,bb);
	}else if(choose==2){
		cout<<"��J��l�q��\nx=";
		cin>>xx;
		Newton(n,data,xx);
	}else{
		cout<<"��J��l�q��\nx=";
		cin>>xx;
		Newton2(n,data,xx);
	}

	system("pause");    //�����N���~��
	return 0;
}
/*
��Xx���ݰ϶���m
*/
double getLoc(double x, double data[2][15]){
	int loc;
	for(int i=1;i<15;i++){
		if(x<=data[0][i]){
			loc = i-1;
			break;
		}
	}
	return loc;
}
/*
�p��f(x)
*/
double getY(double x, double n[14][4], double data[2][15]){
	int loc = getLoc(x,data);
	double x0 = data[0][loc];
	return n[loc][0]*pow(x-x0,3)+n[loc][1]*pow(x-x0,2)+n[loc][2]*pow(x-x0,1)+n[loc][3];
}
/*
�p��f'(x)
*/
double getYY(double x, double n[14][4], double data[2][15]){
	int loc = getLoc(x,data);
	double x0 = data[0][loc];
	return 3*n[loc][0]*pow(x-x0,2)+2*n[loc][1]*pow(x-x0,1)+n[loc][2];
}
/*
�p��f"(x)
*/
double getYYY(double x, double n[14][4], double data[2][15]){
	int loc = getLoc(x,data);
	double x0 = data[0][loc];
	return 6*n[loc][0]*pow(x-x0,1)+2*n[loc][1];
}
/*
Bisection Method
*/
void Bisection(double n[14][4], double data[2][15]){
	cout<<"Bisection Method"<<endl;
	double a, b, c;
	int i;
	clock_t t1,t2;
	for(int j=0;j<6;j++){
		for(int k=0;k<2;k++){
			t1=clock();
			for(int m=1;m<=10000;m++){
				a=(k==0)?j:j+1;
				b=(k==0)?j+1:j;
				c=(b+a)/2;
				i=1;
				//cout<<a<<"\t"<<b<<endl;
				//cout<<i<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<b-c<<"\t"<<getYY(c,n,data)<<endl;
				while(true){
					if(getYY(c,n,data)>0){
						b=c;
					}else{
						a=c;
					}
					c=(b+a)/2;
					i++;
					//cout<<i<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<b-c<<"\t"<<getYY(c,n,data)<<endl;
					if(fabs(b-c)<pow(10,-6)){
						if(m==10000){
							t2=clock();
							if((fabs(c-j)>0.01)&&(fabs(c-j)<0.99)){
							if(getYYY(c,n,data)>0){
								cout<<"minimum="<<c;
							}else{
								cout<<"maximum="<<c;
							}
							cout<<"�Ab-c="<<b-c<<"�Af(c)="<<getY(c,n,data)<<"�A���⦸��:"<<i<<"�Atime="<<t2-t1<<endl;
							}
						}
						break;
					}
				}
			}
		}
	}
	cout<<endl;
}
void Bisection(double n[14][4], double data[2][15], double a, double b){
	double c=(b+a)/2;
	int i=1;
	while(true){
		if(getYY(c,n,data)>0){
			b=c;
		}else{
			a=c;
		}
		c=(b+a)/2;
		i++;
		if(fabs(b-c)<pow(10,-6)){
			if(getYYY(c,n,data)>0){
				cout<<"minimum="<<c;
			}else{
				cout<<"maximum="<<c;
			}
			cout<<"\nf(c)="<<getY(c,n,data)<<"\n���⦸��:"<<i<<endl;
		break;
		}
	}
	cout<<endl;
}
/*
Newton-Raphson method �t���k
*/
void Newton(double n[14][4], double data[2][15]){
	cout<<"Newton-Raphson method �t���k"<<endl;
	double x, x2;
	int i;
	clock_t t1,t2;
	for(int j=1;j<60;j++){
		t1=clock();
		for(int m=1;m<=10000;m++){
			x=(double)j/10;
			i=0;
			x2=getYY(x,n,data)/((getYY(x+0.01,n,data)-getYY(x-0.01,n,data))/0.02);
			while(true){
				if(x2<0||x2>6){
					break;
				}
				x=x2-getYY(x2,n,data)/((getYY(x2+0.01,n,data)-getYY(x2-0.01,n,data))/0.02);
				if(x<0||x>6){
					break;
				}
				i++;
				//cout<<i<<"\t"<<x<<"\t"<<x2<<"\t"<<x2-x<<endl;
				if(fabs(x2-x)<pow(10,-6)){
					if(m==10000){
						t2=clock();
						if(getYYY(x,n,data)>0){
							cout<<"minimum="<<x;
						}else{
							cout<<"maximum="<<x;
						}
						cout<<"�Af(c)="<<getY(x,n,data)<<"�A�_�l��:"<<(double)j/10<<"�A���⦸��:"<<i<<"�Atime="<<t2-t1<<endl;
					}
					//cout<<"\t"<<i<<"\t"<<(double)j/10<<"\t"<<x<<"\t"<<x-x2<<"\t"<<getY(x,n,data)<<endl;
					//cout<<"\t"<<i<<"\t"<<(double)j/10<<"\t"<<x<<"\t"<<getYY(x,n,data)<<endl;
					break;
				}
				x2=x;
			}
		}
	}
	cout<<endl;
}
void Newton(double n[14][4], double data[2][15], double x){
	double x2;
	int i=0;
	x2=getYY(x,n,data)/((getYY(x+0.01,n,data)-getYY(x-0.01,n,data))/0.02);
	while(true){
		if(x2<0||x2>6){
			break;
		}
		x=x2-getYY(x2,n,data)/((getYY(x2+0.01,n,data)-getYY(x2-0.01,n,data))/0.02);
		if(x<0||x>6){
			break;
		}
		i++;
		if(fabs(x2-x)<pow(10,-6)){
			if(getYYY(x,n,data)>0){
				cout<<"minimum="<<x;
			}else{
				cout<<"maximum="<<x;
			}
			cout<<"\nf(c)="<<getY(x,n,data)<<"\n���⦸��:"<<i<<endl;
			break;
		}
		x2=x;	
	}
	cout<<endl;
}
/*
Newton-Raphson method ������u�D�ɼ�
*/
void Newton2(double n[14][4], double data[2][15]){
	cout<<"Newton-Raphson method ������u�D�ɼ�"<<endl;
	double x, x2;
	int i;
	clock_t t1,t2;
	for(int j=1;j<60;j++){
		t1=clock();
		for(int m=1;m<=10000;m++){
			x=(double)j/10;
			i=0;
			x2=getYY(x,n,data)/getYYY(x,n,data);
			while(true){
				if(x2<0||x2>6){
					break;
				}
				x=x2-getYY(x2,n,data)/getYYY(x,n,data);
				if(x<0||x>6){
					break;
				}
				i++;
				//cout<<i<<"\t"<<x<<"\t"<<x2<<"\t"<<x2-x<<endl;
				if(fabs(x2-x)<pow(10,-6)){
					if(m==10000){
						t2=clock();
						if(getYYY(x,n,data)>0){
							cout<<"minimum="<<x;
						}else{
							cout<<"maximum="<<x;
						}
						cout<<"�Af(c)="<<getYY(x,n,data)<<"�A�_�l��:"<<(double)j/10<<"�A���⦸��:"<<i<<"�Atime="<<t2-t1<<endl;
					}
					//cout<<"\t"<<i<<"\t"<<(double)j/10<<"\t"<<x<<"\t"<<x-x2<<"\t"<<getY(x,n,data)<<endl;
					//cout<<"\t"<<i<<"\t"<<(double)j/10<<"\t"<<x<<"\t"<<getYY(x,n,data)<<endl;
					break;
				}
				x2=x;
			}
		}
	}
	cout<<endl;
}
void Newton2(double n[14][4], double data[2][15], double x){
	double x2;
	int i=0;
	x2=getYY(x,n,data)/getYYY(x,n,data);
	while(true){
		if(x2<0||x2>6){
			break;
		}
		x=x2-getYY(x2,n,data)/getYYY(x,n,data);
		if(x<0||x>6){
			break;
		}
		i++;
		if(fabs(x2-x)<pow(10,-6)){
			if(getYYY(x,n,data)>0){
				cout<<"minimum="<<x;
			}else{
				cout<<"maximum="<<x;
			}
			cout<<"\nf(c)="<<getY(x,n,data)<<"\n���⦸��:"<<i<<endl;
			break;
		}
		x2=x;
	}
	cout<<endl;
}
/*
LU Decomposition
*/
void lu(double a[15][15], double l[15][15], double u[15][15]){
	for(int k=0;k<15;k++){
		u[0][k] = a[0][k];
	}
	for(int j=0;j<15;j++){
		l[j][0] = a[j][0]/u[0][0];
		l[j][j] = 1;
	}
	for(int j=1;j<15;j++){
		for(int k=j;k<15;k++){
			for(int s=0;s<j;s++){
				u[j][k] += l[j][s]*u[s][k];
			}
			u[j][k] = a[j][k]-u[j][k];
		}
		if(j<14){
			for(int k=j+1;k<15;k++){
				for(int s=0;s<j;s++){
					l[k][j] += l[k][s]*u[s][j];
				}
				l[k][j] = (a[k][j]-l[k][j])/u[j][j];
			}
		}
	}
}
/*
forward substitution
*/
void forward(double l[15][15], double b[15], double c[15]){
	c[0] = b[0]/l[0][0];
	for(int i=1;i<15;i++){
		for(int j=0;j<=i-1;j++){
			c[i] += l[i][j]*c[j];
		}
		c[i] = (b[i]-c[i])/l[i][i];
	}
}
/*
back substitution
*/
void back(double u[15][15], double c[15], double p[15]){
	p[14] = c[14]/u[14][14];
	for(int i=13;i>=0;i--){
		for(int j=i;j<15;j++){
			p[i] += u[i][j]*p[j];
		}
		p[i] = (c[i]-p[i])/u[i][i];
	}
}
/*
print
*/
void print(double x[101], double y[101]){
	for(int i=0;i<101;i++){
		cout<<x[i]<<"\t"<<y[i]<<endl;
	}
	cout<<endl;
}
void print(double array[14][4]){
	for(int i=0;i<14;i++){
		for(int j=0;j<4;j++){
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}
void print(double array[15][15]){
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}
void print(double array[15]){
	for(int i=0;i<15;i++){
		cout<<array[i]<<endl;
	}
	cout<<endl;
}

