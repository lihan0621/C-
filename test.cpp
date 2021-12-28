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
int M=50;  //资源数量
int N=50;  //可供资源种类数量
void showdata()
{
	int i, j;
	cout<<"此时刻的资源分配情况为:"<<endl;
	cout<<endl;
	cout<<"         Max       Allocation     Need       Available "<<endl;
	cout<<"进程名   ";
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
int safe()//安全性算法
{
	int i, d, k=0, m, h, s, apply, Finish[100]={ 0 };
	int j;

	for(i=0; i<N; i++)
		Work[i]=Available[i];
	cout<<endl<<"  安全性检查  "<<endl;
	cout<<"             Work      Need     Allocation     Work+Allocation     Finish"<<endl;
	cout<<"进程名      ";
	for(h=0; h<4; h++) {
		for(s=0; s<N; s++)
			cout<<name[s]<<" ";
		cout<<"      ";
	}
	cout<<endl;
	for(i=0; i<M; i++) {//安全序列
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
			cout<<endl<<"系统进入不安全状态！此时系统不分配资源！"<<endl;//系统不安全
			return 0;
		}
	}
	cout<<endl<<"此时系统是安全的!"<<endl;//如果安全，输出成功
	cout<<"安全序列为:";
	for(i=0; i<M; i++) {//输出运行进程数组
		cout<<temp[i];
		if(i<M-1) cout<<"->";
	}
	cout<<endl;
	return 0;
}
void bank()//利用银行家算法对申请资源对进行判定
{
	char ch;
	int i=0, j=0;
	ch='y';
	int sum=0;
	cout<<endl<<"请输入要求分配的资源进程号(0-"<<M-1<<"):";
	cin>>i;//输入申请的资源号
	cout<<endl<<"请输入进程 "<<i<<" 申请的资源:"<<endl;
	for(j=0; j<N; j++)
	{
		cout<<name[j]<<":";
		cin>>Request[j];//输入需要申请的资源
	}
	for(j=0; j<N; j++) {
		if(Request[j]>Need[i][j])
		{
			cout<<endl<<"进程 "<<i<<"申请的资源大于它需要的资源";
			cout<<" 分配不合理，不予分配！"<<endl;
			ch='n';
			break;
		}
		else {
			if(Request[j]>Available[j])//判断申请是否大于当前资源，若大于则
			{                         //出错
				cout<<endl<<"进程"<<i<<"申请的资源大于系统现在可利用的资源";
				cout<<" 分配出错，不予分配!"<<endl;
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
		}//根据进程需求量变换资源
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
		showdata();//根据进程需求量显示变换后的资源
		safe();
	}
}
int main()//主函数
{
	int t=1, number, m, n, flag;
	char ming;
	cout<<"*****************----------*********************"<<endl;
	cout<<"*****************银行家算法********************"<<endl;
	cout<<"*****************----------*********************"<<endl;
	cout<<endl<<"输入系统可供资源种类的数量:";
	cin>>n;
	N=n;
	for(int i=0; i<n; i++)
	{
		cout<<"资源"<<i+1<<"的名称:";
		cin>>ming;
		name[i]=ming;
		cout<<"资源的数量:";
		cin>>number;
		Available[i]=number;
	}
	cout<<endl;
	cout<<"输入作业的数量:";
	cin>>m;
	M=m;
	cout<<endl<<"输入各进程的最大需求量("<<m<<"*"<<n<<"矩阵)[Max]:"<<endl;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>Max[i][j];
	flag=1;
	while(flag)
	{
		cout<<"输入各进程已经申请的资源量("<<m<<"*"<<n<<"矩阵)[Allocation]:"<<endl;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				cin>>Allocation[i][j];
				if(Allocation[i][j]>Max[i][j])
					flag=0;
				Need[i][j]=Max[i][j]-Allocation[i][j];
			}
		if(!flag)
			cout<<"申请的资源大于最大需求量，请重新输入!\n";
		else
			break;
	}
	showdata();//显示各种资源
	safe();//用银行家算法判定系统是否安全
	while(1) {
		if(t==1) {
			cout<<endl<<"利用银行家算法预分配资源   "<<endl;
			bank();
			t=0;
		}
		else break;
		cout<<endl<<" 是否继续银行家算法？(按 1 继续,按其它任意退出):";
		cin>>t;
		cout<<endl;
	}
	return 0;
}
