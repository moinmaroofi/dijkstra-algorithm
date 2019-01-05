// dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
using namespace std;
//**************************
struct edge{
	int wight;
	int v1;
	int v2;
};
//**************************
class preamc {
public:
	edge* pream(int , int**);
};
//**************************
preamc p;
//**************************
void main(int argc, _TCHAR* argv[])
{
	int n, m;
	int** w;
	cout<<"\n\t\t**********************************************\n\n  tedade ras ha ra vared kon	:	";
	cin>>n;
	cout<<"\n  tedade yal ha ra vared kon	:	";
	cin>>m;
	if(m>=n-1 && m<=n*(n-1)/2){
	w = new int* [n];
	for(int i=0; i<n; i++)
		w[i]=new int[n];
	for (int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i<j)
			{
				cout<<"\n  enter the edge weight between V"<<i+1<<" and V"<<j+1<<"	:	";
				cin >> w[i][j];
			}
			else if(i>j)
				w[i][j] = w[j][i];
			else
				w[i][j]=0;
	edge *F = new edge[n];
	F = p.pream(n, w );
	system("cls");
	cout<<"\n  **************************\n";
	for(int i=1; i<n; i++)
		cout<<"\n  connect V"<<F[i].v1<<" to V"<<F[i].v2<<" by "<<F[i].wight<<" far from V1 \n";
	}

	else
		cout<<"\n  it not correct";
	getch();
}
//++++++++++++++++++++++++++++++++++++++
edge* preamc::pream(int n, int** w)
{
	int i , Vnear, min;
	edge e;
	int *touch , *length;
	touch = new int [n];
	length = new int [n];
	edge *f;
	f = new edge [n];
	for(int i=1; i<n; i++)
	{
		touch[i] = 1;
		length[i] = w[0][i];
	}
	for(int j=1; j<n; j++)
	{
		min =100;
		for(i=1; i<n; i++)
			if(0 < length[i] && length[i]<min)
			{
				min = length[i];
				Vnear = i;
			}
		e.v1=touch[Vnear];
		e.v2=Vnear+1;
		e.wight=min;
		f[j] = e;
		for(i=1 ; i<n; i++)
			if(length[Vnear] + w[Vnear][i] < length[i])
			{
				touch[i] = Vnear+1;
				length[i]= w[i][Vnear] +length[Vnear];
			}
		length[Vnear] = -1;
	}
	return f;
}
//++++++++++++++++++++++++++++++++++++++


