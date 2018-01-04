#include"RSmatrix.h"
#include<iostream>
#include<iomanip>
using namespace std;

RSmatrix::RSmatrix(int a)
{
	n=a;
}
void RSmatrix::setspace()
{   int i;
	p=new double*[n];
	for(i=0;i<n;i++)
	 p[i]=new double[n];
	 
}

void RSmatrix::fill()
{
  int i,j;
	for(i=0;i<n;i++)
	 for(j=i;j<n;j++)
	  {
	  	p[i][j]=i*j;
	  	if(i!=j) p[j][i]=p[i][j];
	  }
}

void RSmatrix::displaymatrix()
{   
  int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		 cout<<setw(10)<<p[i][j]<<" ";
		cout<<endl;
	}

}
