//���ߣ��ų���
//���ܣ�ʵ��2048С��Ϸ
//ʱ�䣺2018.3.34

#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
//#define random() (rand()%1000)
//#define arr_size 16
using namespace std;

class array{
	public:
		static int a[4][4];
		static int b[4][4];
		static int score;
		static void ran_new();
		static void out_2048();
		static void arr_copy();
		static int arr_judge();
		static void change_array();
		static void www();
		static void aaa();
		static void sss();
		static void ddd();
}; 

int array::a[4][4]={0};//��Ա�����������ڲ���ʼ�� 
int array::b[4][4]={0};
int array::score=0;

//�����������λ���������һ��2��һ��4������2�ĸ���5/6������4�ĸ���Ϊ1/6 
void array::ran_new(){
	int i=rand()%16;
	int j=rand()%6;
	int x=i/4,y=i%4;
	if(a[x][y]==0){
		if(j==0) a[x][y]=4;
		else a[x][y]=2;
	}
	else ran_new();
}

//�����4*4���� �Լ��÷� 
void array::out_2048(){
	system("cls");
	cout << "�����뵥����ĸ��������w==�ϣ�s==�£�a==��d==��" << endl;
	cout << "��ǰ�÷�: " ;
	cout << score << endl;
	cout << endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout << setw(8) << a[i][j];
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

//������a����������b 
void array::arr_copy(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			b[i][j]=a[i][j];
		}
	}
}

//�ж�ab�Ƿ���ȣ����˵��������Ч 
int array::arr_judge(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(b[i][j]!=a[i][j])	return 0;
		}
	}
	return 1;
} 

//w���Ʋ��� 
void array::www(){
	arr_copy();
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(a[0][i]==0){
				a[0][i]=a[1][i];
				a[1][i]=a[2][i];
				a[2][i]=a[3][i];
				a[3][i]=0;
			}
			else if(a[1][i]==0){
				a[1][i]=a[2][i];
				a[2][i]=a[3][i];
				a[3][i]=0;
			}
			else if(a[2][i]==0){
				a[2][i]=a[3][i];
				a[3][i]=0;
			}
			else break;
		}
		if(a[0][i]==a[1][i]) {
			a[0][i]+=a[1][i];
			score+=a[1][i]*2;
			if(a[2][i]==a[3][i]&&a[2][i]!=0){
				a[1][i]=a[2][i]+a[3][i];
				score+=a[1][i];
				a[2][i]=0;
				a[3][i]=0;
			}	
			else{
				a[1][i]=a[2][i];
				a[2][i]=a[3][i];
				a[3][i]=0;
			}
		}
		else if(a[1][i]==a[2][i]){
			a[1][i]+=a[2][i];
			score+=a[1][i]*2;
			a[2][i]=a[3][i];
			a[3][i]=0;
		}
		else if(a[2][i]==a[3][i]){
			a[2][i]+=a[3][i];
			score+=a[2][i]*2;
			a[3][i]=0;
		}	
	}
	if(!arr_judge())	ran_new();	
}

void array::change_array(){//˳ʱ����ת90�� 
	int i,j;
	arr_copy();
	for(j=0;j<4;j++){
		for(i=0;i<4;i++){
			a[j][3-i]=b[i][j];
		}
	} 
} 
 
void array::aaa(){
	change_array();
	www();
	change_array();
	change_array();
	change_array();
}
 
void array::sss(){
	change_array();
	change_array();
	www();
	change_array();
	change_array();
}

void array::ddd(){
	change_array();
	change_array();
	change_array();
	www();
	change_array();
}

//������������ַ���ѡ���Ӧ�Ĳ��� 
void choose(){
	char c;
	cin >>c;
	switch (c){
	case 'w':array::www();break;
	case 's':array::sss();break;
	case 'a':array::aaa();break;
	case 'd':array::ddd();break;
	}
}

int main(){
	system("color f0");
	int i;
	char c;
	array::ran_new();
	srand((int)time(0));
	do{	
		array::out_2048();
		choose();	
	}while(1);
	return 0;
	system("pasue");
}
