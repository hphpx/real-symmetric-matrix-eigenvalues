#include"SolveEigen.cpp"
#include"RSmatrix.cpp" 

int main()
{
	SolveEigen sol(6);
	sol.setspace();
	
	
	try{
	      sol.fillfromfile();
	      sol.displaymatrix();
	      
	      sol.solveall();
	      sol.showeigen();
          return 0;
       }
    catch(double)
    {
    	cout<<"dimension error\n";
    }
    catch(int)
    {
    	cout<<"not a real symmetric matrix\n";
    }
}
