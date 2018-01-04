#include"SolveEigen.h"
#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;


SolveEigen::SolveEigen(int a):RSmatrix(a)
{
	precision=1e-8;
}
void SolveEigen::findmax()
{
	int i,j;
	double max=-9e10;
	for(i=0;i<n;i++)
	 for(j=i+1;j<n;j++)
	  {
	   if(fabs(p[i][j])>max) { max=fabs(p[i][j]); x=i; y=j;}
      }
	offmax=p[x][y];

}


void SolveEigen::fillfromfile()
{
	ifstream input;
	double temp;
	int i,j;
	input.open("inputM.txt");
	input>>temp;
	if(temp!=n) {
	
		throw temp;
	}
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  {
	  	input>>temp;
	  	p[i][j]=temp;
	  }
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  {
	  
	  	if(p[i][j]!=p[j][i]) 
	  	 {
	  	 	throw i; 
	  	 }
	  }
	cout<<"input done\n";
}
void SolveEigen::offsumfirst()
{
	int i,j;
	double sum=0;
	for(i=0;i<n;i++)
	 for(j=i+1;j<n;j++)
	   sum+=(p[i][j]*p[i][j]);
	offsum=sum*2;
}

void SolveEigen::calpara()
{  
	s=0.5*(p[y][y]-p[x][x])/p[x][y];
	if(s==0) t=1;
	else if(s>0)  t=sqrt(s*s+1)-s;
	else t=-sqrt(s*s+1)-s;
	
	c=1/sqrt(1+t*t);
    d=t*c;

}

void SolveEigen::tonext()
{
	p[x][y]=0; p[y][x]=0;
	p[x][x]-=(t*offmax);
	p[y][y]+=(t*offmax);
	
	int i,j;
	double temp1,temp2;
	for(i=0;i<n;i++)
	 {
	 	if(i!=x && i!=y)
	 	 {  
	 	   
	 	 	temp1=c*p[x][i]-d*p[y][i];  
	 	 	temp2=d*p[x][i]+c*p[y][i]; 
	 	 	p[x][i]=temp1;p[i][x]=p[x][i];
	 	 	p[y][i]=temp2;p[i][y]=p[y][i];
	 	 	
	 	 }
	 }
	 offsum-=(2*offmax*offmax);
 // cout<<" $$ "<<offsum-(2*offmax*offmax)<<endl;
	
}

void SolveEigen::solveall()
{
	offsumfirst();
	int i=0,j;
	while(fabs(offsum)>precision)
	{  // cout<<"--------------"<<i<<"------------------ \n";
		findmax(); 
		calpara();
		tonext(); 
	//	displaymetrix();
	    i++;

	}
	
	cout<<"iteration times: "<<i<<endl;
	
}

void SolveEigen::showeigen()
{
	int i;
	cout<<"eigenvalues:\n";
	for(i=0;i<n;i++)
	 cout<<p[i][i]<<endl;
}

void SolveEigen::displaymatrix()
{   
  int i,j;
    cout.setf(ios::fixed);
    cout.width(9);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		 cout<<setw(10)<<p[i][j]<<" ";
		cout<<endl;
	}

}

