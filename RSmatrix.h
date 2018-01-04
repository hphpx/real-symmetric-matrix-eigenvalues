#ifndef RSmatrix_H
#define RSmatrix_H

class RSmatrix
{

	public:
		RSmatrix(int);
	
		void setspace();
		void fill();
		void eigenvalue();
		void displaymatrix();
		double **p;
		int n;
};

#endif
