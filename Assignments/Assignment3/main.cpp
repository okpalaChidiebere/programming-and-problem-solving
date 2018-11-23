/************************************************************************************************
programmer name: Okplala Chidiebere Collins
programmer ID: 200356606
prgrammer data: 1st November, 2014;
main algorithm: it reads the symbol, the alphabet and the number entered from
the user. then it crosschecks the symbol and and assigns it the original value for v; use 
the v to solve and get the n. then check the value for n using the if else statement to determine 
the shape of the n.
***********************************************************/

#include<iostream>
#include<fstream>
#include<string>

int numof_Bonelec(int b, int v);
using namespace std;


int main()
{
	ifstream infile;  //ifstream aaaaa;
	ofstream outdata;  //ofstream ofile;
	infile.open("molecules.txt"); //aaaaa.open("");
		if (!infile)
	{
			cout << "Error in opening molecules.txt. Exiting........ ";  //error checking the infile
			return 1;
	}
		outdata.open("geometricalshape.txt");  //ofile.open("");
		if (!outdata)
		{
			cout << "Error in opening molecules.txt. Exiting........";  //error checking the outdata
			return 2;
		}
		//declearing datatyes && variables needed
		
		int v;
		int e;
		int b;
		int n;
		int result;
		string symbol;
		string inchar;
		string shape;
		
		while (!infile.eof()) //keeping processing the the file till it reaches the end of file
		{
			infile >> symbol;
			infile >> inchar;
			infile >> b;
			//boolean expression checking the symbol and assigning it the v value
			if (symbol == "Be")
				v = 3;
			else if (symbol == "C" || symbol == "Si")
				v = 4;
			else if (symbol == "N" || symbol == "P" || symbol == "A")
				v = 5;
			else if (symbol == "O" || symbol == "S" || symbol == "Se")
				v = 6;
			else if (symbol == "F" || symbol == "Cl" || symbol == "Br" || symbol == "I")
				v = 7;
			else if (symbol == "Xe")
				v = 8;
			else
				outdata << "invalid choice of element!!" << endl;//output fo if the symbol entered is not in the boolean expression
			//numof_Bonelec(v, b);
			e = v - b;  //calculatio proper
			n = e / 2;
			
			result = n;
			if (b == 2) //compairing the b to the n to determine the correct shape
			{
				
				if (result == 0 || n == 3)
					shape = "linear";
				else if (n == 1 || n == 2)
					shape = "bent";
				else
					shape = "unknown";
			}
			else if (b == 3)
			{
				if (n == 0)
					shape = "trigonal planar";
				else if (n == 1)
					shape = "trigonal pyramidal";
				else if (n == 2)
					shape = "T-shaped";
				else
					shape = "unknown";
			}
			else if (b == 4)
			{
				if (n == 0)
					shape = "tetrahedral";
				else if (n == 1)
					shape = "seesaw";
				else if (n == 2)
					shape = "square-planar";
				else
					shape = "unknown";
			}
			else if (b == 5)
			{
				if (n == 0)
					shape = "trigonal bipyramid";
				else if (n == 1)
					shape = "square pyramid";
				else
					shape = "unknown";
			}
			else if (b == 6 && n == 0)
			
					shape = "octahedral"; 

			else
					shape = "unknown";
			

			outdata << "The geometrical shape of one " << symbol << " atom surrounded by " << b << " " << inchar << " atoms is " << shape << endl;
			outdata << endl;
		}
		return 0;
}

	//**********************************************************************************************************************;
int numof_Bonelec(int b,int v)
{
	int e,n=0;
	e = v - b;  //calculatio proper
	n = e / 2;
	return n;
}
