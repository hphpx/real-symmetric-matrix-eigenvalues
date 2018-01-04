#ifndef SolveEigen_H
#define SolveEigen_H
#include"RSmatrix.h"

class SolveEigen: public RSmatrix
{
	public:
		SolveEigen(int a);
		void findmax();
		void offsumfirst();
		void calpara();
		void tonext();
		void solveall();
		void showeigen();
		void fill();
		void fillfromfile();
		void displaymatrix();
		double offsum,offmax,s,t,c,d,precision;
		int x,y;
};

#endif
