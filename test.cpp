#include<stdio.h>
#include<iostream>
using namespace std;
#include<string.h>
#define false 0
#define true 1
int Available[50]={ 0 };
int Max[50][50]={ 0 };
int Allocation[50][50]={ 0 };
int Need[50][50]={ 0 };
int Request[50]={ 0 };
int Work[50]={ 0 };
char name[100]={ 0 };
int temp[50]={ 0 };
int Finish[50]={ 0 };
int M=50;  //��Դ����
int N=50;  //�ɹ���Դ��������
void showdata()
{
	int i, j;
	cout<<"��ʱ�̵���Դ�������Ϊ:"<<endl;
	cout<<endl;
	cout<<"         Max       Allocation     Need       Available "<<endl;
	cout<<"������   ";
	for(j=0; j<4; j++)
	{
		for(i=0; i<N; i++)
			cout<<name[i]<<" ";
		cout<<"      ";
	}
	cout<<endl;
	for(i=0; i<M; i++)
	{
		cout<<"  "<<i<<"      ";
		for(j=0; j<N; j++)
			cout<<Max[i][j]<<" ";
		cout<<"      ";
		for(j=0; j<N; j++)
			cout<<Allocation[i][j]<<" ";
		cout<<"      ";
		for(j=0; j<N; j++)
			cout<<Need[i][j]<<" ";
		if(i==0) {
			cout<<"      ";
			for(j=0; j<N; j++)
				cout<<Available[j]<<" ";
		}
		cout<<endl;
	}
}
int safe()//��ȫ���㷨
{
	int i, d, k=0, m, h, s, apply, Finish[100]={ 0 };
	int j;

	for(i=0; i<N; i++)
		Work[i]=Available[i];
	cout<<endl<<"  ��ȫ�Լ��  "<<endl;
	cout<<"             Work      Need     Allocation     Work+Allocation     Finish"<<endl;
	cout<<"������      ";
	for(h=0; h<4; h++) {
		for(s=0; s<N; s++)
			cout<<name[s]<<" ";
		cout<<"      ";
	}
	cout<<endl;
	for(i=0; i<M; i++) {//��ȫ����
		apply=0;
		for(j=0; j<N; j++) {
			if(Finish[i]==false && Need[i][j]<=Work[j])
			{
				apply++;
				if(apply==N)
				{
					cout<<" "<<i<<"         ";
					for(d=0; d<N; d++)
						cout<<Work[d]<<" ";
					cout<<"      ";
					for(d=0; d<N; d++)
						cout<<Need[i][d]<<" ";
					cout<<"      ";
					for(d=0; d<N; d++)
						cout<<Allocation[i][d]<<" ";
					cout<<"      ";
					for(m=0; m<N; m++)
					{
						Work[m]=Work[m]+Allocation[i][m];
						cout<<Work[m]<<" ";
					}
					Finish[i]=true;
					temp[k]=i;
					cout<<"              ";
					cout<<"true"<<" ";
					cout<<endl;
					k++;
					i=-1;
				}
			}
		}
	}
	for(i=0; i<M; i++) {
		if(Finish[i]==false) {
			for(j=0; j<N; j++) {
				Available[j]=Available[j]+Request[j];
				Allocation[i][j]=Allocation[i][j]-Request[j];
				Need[i][j]=Need[i][j]+Request[j];
			}
			cout<<endl<<"ϵͳ���벻��ȫ״̬����ʱϵͳ��������Դ��"<<endl;//ϵͳ����ȫ
			return 0;
		}
	}
	cout<<endl<<"��ʱϵͳ�ǰ�ȫ��!"<<endl;//�����ȫ������ɹ�
	cout<<"��ȫ����Ϊ:";
	for(i=0; i<M; i++) {//������н�������
		cout<<temp[i];
		if(i<M-1) cout<<"->";
	}
	cout<<endl;
	return 0;
}
void bank()//�������м��㷨��������Դ�Խ����ж�
{
	char ch;
	int i=0, j=0;
	ch='y';
	int sum=0;
	cout<<endl<<"������Ҫ��������Դ���̺�(0-"<<M-1<<"):";
	cin>>i;//�����������Դ��
	cout<<endl<<"��������� "<<i<<" �������Դ:"<<endl;
	for(j=0; j<N; j++)
	{
		cout<<name[j]<<":";
		cin>>Request[j];//������Ҫ�������Դ
	}
	for(j=0; j<N; j++) {
		if(Request[j]>Need[i][j])
		{
			cout<<endl<<"���� "<<i<<"�������Դ��������Ҫ����Դ";
			cout<<" ���䲻����������䣡"<<endl;
			ch='n';
			break;
		}
		else {
			if(Request[j]>Available[j])//�ж������Ƿ���ڵ�ǰ��Դ����������
			{                         //����
				cout<<endl<<"����"<<i<<"�������Դ����ϵͳ���ڿ����õ���Դ";
				cout<<" ��������������!"<<endl;
				ch='n';
				break;
			}
		}
	}
	if(ch=='y') {
		int o;
		for(o=0; o<M; o++)
		{
			Available[o]=Available[o]-Request[o];
			Allocation[i][o]=Allocation[i][o]+Request[o];
			Need[i][o]=Need[i][o]-Request[o];
		}//���ݽ����������任��Դ
		for(int p=0; p<N; p++)
		{
			if(Need[i][p]==0)
			{
				sum++;
				if(sum==N)
				{
					for(int u=0; u<N; u++)
					{
						Available[u]+=Allocation[i][u];
						Allocation[i][u]-=Max[i][u];
					}
				}
			}
		}
		showdata();//���ݽ�����������ʾ�任�����Դ
		safe();
	}
}
int main()//������
{
	int t=1, number, m, n, flag;
	char ming;
	cout<<"*****************----------*********************"<<endl;
	cout<<"*****************���м��㷨********************"<<endl;
	cout<<"*****************----------*********************"<<endl;
	cout<<endl<<"����ϵͳ�ɹ���Դ���������:";
	cin>>n;
	N=n;
	for(int i=0; i<n; i++)
	{
		cout<<"��Դ"<<i+1<<"������:";
		cin>>ming;
		name[i]=ming;
		cout<<"��Դ������:";
		cin>>number;
		Available[i]=number;
	}
	cout<<endl;
	cout<<"������ҵ������:";
	cin>>m;
	M=m;
	cout<<endl<<"��������̵����������("<<m<<"*"<<n<<"����)[Max]:"<<endl;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>Max[i][j];
	flag=1;
	while(flag)
	{
		cout<<"����������Ѿ��������Դ��("<<m<<"*"<<n<<"����)[Allocation]:"<<endl;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				cin>>Allocation[i][j];
				if(Allocation[i][j]>Max[i][j])
					flag=0;
				Need[i][j]=Max[i][j]-Allocation[i][j];
			}
		if(!flag)
			cout<<"�������Դ�������������������������!\n";
		else
			break;
	}
	showdata();//��ʾ������Դ
	safe();//�����м��㷨�ж�ϵͳ�Ƿ�ȫ
	while(1) {
		if(t==1) {
			cout<<endl<<"�������м��㷨Ԥ������Դ   "<<endl;
			bank();
			t=0;
		}
		else break;
		cout<<endl<<" �Ƿ�������м��㷨��(�� 1 ����,�����������˳�):";
		cin>>t;
		cout<<endl;
	}
	return 0;
}
