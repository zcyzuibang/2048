//���ߣ��ų���
//���ܣ�ʵ��2048С��Ϸ
//ʱ�䣺2018.3.34

#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
//#define arr_size 16
using namespace std;
int score=0;
int a[4][4]={0};

void ran_new(){
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
void out_2048(int a[][4]){
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

int b[4][4]={0};

//������a����������b 
void arr_copy(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			b[i][j]=a[i][j];
		}
	}
}

//�ж�ab�Ƿ���ȣ����˵��������Ч 
int arr_judge(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(b[i][j]!=a[i][j])	return 0;
		}
	}
	return 1;
} 

//w���Ʋ��� 
void www(){
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
			/*if(a[0][i]==a[1][i]){
				a[0][i]+=a[1][i];
				a[1][i]=a[2][i];
				a[2][i]=0;
				if(a[0][i]==a[1][i]){
					a[0][i]+=a[1][i];
					a[1][i]=0;
				}
			}*/
		}
		else if(a[1][i]==a[2][i]){
			a[1][i]+=a[2][i];
			score+=a[1][i]*2;
			a[2][i]=a[3][i];
			a[3][i]=0;
			/*if(a[0][i]==a[1][i]){
				a[0][i]+=a[1][i];
				a[1][i]=0;
			}
			else if(a[1][i]==a[2][i]){
				a[1][i]+=a[2][i];
				a[2][i]=0;
			}*/
		}
		else if(a[2][i]==a[3][i]){
			a[2][i]+=a[3][i];
			score+=a[2][i]*2;
			a[3][i]=0;
			/*if(a[1][i]==a[2][i]){
				a[1][i]+=a[2][i];
				a[2][i]=0;
			}
			if(a[0][i]==a[1][i]){
				a[0][i]+=a[1][i];
				a[1][i]=0;
			}*/
		}	
	}
	if(!arr_judge())	ran_new();	
}

//s���Ʋ��� 
void sss(){
	arr_copy();
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(a[3][i]==0){
				a[3][i]=a[2][i];
				a[2][i]=a[1][i];
				a[1][i]=a[0][i];
				a[0][i]=0;
			}
			else if(a[2][i]==0){
				a[2][i]=a[1][i];
				a[1][i]=a[0][i];
				a[0][i]=0;
			}
			else if(a[1][i]==0){
				a[1][i]=a[0][i];
				a[0][i]=0;
			}
			else break;
		}
		if(a[3][i]==a[2][i]) {
			a[3][i]+=a[2][i];
			score+=a[3][i];
			if(a[1][i]==a[0][i]&&a[1][i]!=0){
				a[2][i]=a[1][i]+a[0][i];
				score+=a[2][i];
				a[1][i]=0;
				a[0][i]=0;
			}	
			else{
				a[2][i]=a[1][i];
				a[1][i]=a[0][i];
				a[0][i]=0;
			}
		}
		else if(a[2][i]==a[1][i]){
			a[2][i]+=a[1][i];
			score+=a[2][i];
			a[1][i]=a[0][i];
			a[0][i]=0;
		}
		else if(a[1][i]==a[0][i]){
			a[1][i]+=a[0][i];
			score+=a[1][i];
			a[0][i]=0;
		}
	}
	if(!arr_judge())	ran_new();
}

//a���Ʋ��� 
void aaa(){
	arr_copy();
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(a[i][0]==0){
				a[i][0]=a[i][1];
				a[i][1]=a[i][2];
				a[i][2]=a[i][3];
				a[i][3]=0;
			}
			else if(a[i][1]==0){
				a[i][1]=a[i][2];
				a[i][2]=a[i][3];
				a[i][3]=0;
			}
			else if(a[i][2]==0){
				a[i][2]=a[i][3];
				a[i][3]=0;
			}
			else break;
		}
		if(a[i][0]==a[i][1]) {
			a[i][0]+=a[i][1];
			score+=a[i][0];
			if(a[i][2]==a[i][3]&&a[i][2]!=0){
				a[i][1]=a[i][2]+a[i][3];
				score+=a[i][1];
				a[i][2]=0;
				a[i][3]=0;
			}	
			else{
				a[i][1]=a[i][2];
				a[i][2]=a[i][3];
				a[i][3]=0;
			}
		}
		else if(a[i][1]==a[i][2]){
			a[i][1]+=a[i][2];
			score+=a[i][1];
			a[i][2]=a[i][3];
			a[i][3]=0;
		}
		else if(a[i][2]==a[i][3]){
			a[i][2]+=a[i][3];
			score+=a[i][2];
			a[i][3]=0;
		}
	}
	if(!arr_judge())	ran_new();	
}

//d���Ʋ��� 
void ddd(){
	arr_copy();
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(a[i][3]==0){
				a[i][3]=a[i][2];
				a[i][2]=a[i][1];
				a[i][1]=a[i][0];
				a[i][0]=0;
			}
			else if(a[i][2]==0){
				a[i][2]=a[i][1];
				a[i][1]=a[i][0];
				a[i][0]=0;
			}
			else if(a[i][1]==0){
				a[i][1]=a[i][0];
				a[i][0]=0;
			}
			else break;
		}
		if(a[i][3]==a[i][2]) {
			a[i][3]+=a[i][2];
			score+=a[i][3];
			if(a[i][1]==a[i][0]&&a[i][1]!=0){
				a[i][2]=a[i][1]+a[i][0];
				score+=a[i][2];
				a[i][1]=0;
				a[i][0]=0;
			}	
			else{
				a[i][2]=a[i][1];
				a[i][1]=a[i][0];
				a[i][0]=0;
			}
		}
		else if(a[i][2]==a[i][1]){
			a[i][2]+=a[i][1];
			score+=a[i][2];
			a[i][1]=a[i][0];
			a[i][0]=0;
		}
		else if(a[i][1]==a[i][0]){
			a[i][1]+=a[i][0];
			score+=a[i][1];
			a[i][0]=0;
		}
	}
	if(!arr_judge())	ran_new();	
}

//������������ַ���ѡ���Ӧ�Ĳ��� 
void choose(){
	char c;
	cin >>c;
	switch (c){
	case 'w':www();break;
	case 's':sss();break;
	case 'a':aaa();break;
	case 'd':ddd();break;
	}
}

int main(){
	system("color f0");
	int i;
	char c;
	ran_new();
	srand((int)time(0));
	do{	
		out_2048(a);
		choose();	
	}while(1);
	return 0;
	system("pasue");
}
