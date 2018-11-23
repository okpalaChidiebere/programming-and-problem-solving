/*****************************************************************************************
Programmer name: Okpala Chidiebre Collins
student number: 200356606
date due: November 30th, 2014.
Program purpose: to determine the condition of four indididuals through their two genes
main algorithm: 
            - while is not the end of file, call a subfunction that gets all characters and assigns
			it to each of the arrays stops at the count of 444. i keep calling it assigning differnt arrays to it
			until the end of the file.
			-a subfunction now checks the arrays
			if the 19th index of the two arrays paird is 'T' the person is anaemic 
			else if the 19th index of one array is 'T' or the other'T' thre person 
			is a carrier
			else the person is normal
			- I compair the with the other three arrays
			-  i then call a bool subfunction that checks for related array.
*****************************************************************************************/
//declaring header files
#include<iostream>
#include<fstream>

using namespace std;

//function protoypes 
void Get_Genes(ifstream &, char[], int);
void Check_Genes(ofstream &, char[], char[], char);
bool Same_Gene(const char[], const char[], const int size);

// global variable
const int Per_Gene = 444;  //number of Dna per GENE to remain unchanged
int main()
{
	//creating files
	ifstream indata;
	ofstream outdata;

	
	//opening the files
	indata.open("DNA.txt");

	//error checking
	if (!indata)
	{
		cout << "unable to open \"DNA.txt\".exiting..." << endl;
		return 1;
	}

	outdata.open("DNAanalysis.txt");

	//error checking
	if (!outdata)
	{
		cout << "inable to open \"DNAanalysis.txt\". exiting..." << endl;
		return 2;
	}

	//declearing the arrays to store each gene
	char GENE1A[Per_Gene];
	char GENE2A[Per_Gene];
	char GENE1B[Per_Gene];
	char GENE2B[Per_Gene];
	char GENE1C[Per_Gene];
	char GENE2C[Per_Gene];
	char GENE1D[Per_Gene];
	char GENE2D[Per_Gene];
	
	
		//function call to gets all issues. stores all characters from index 0 to 3551
		Get_Genes(indata, GENE1A, Per_Gene); 
		Get_Genes(indata, GENE2A, Per_Gene);
		Get_Genes(indata, GENE1B, Per_Gene);
		Get_Genes(indata, GENE2B, Per_Gene);
		Get_Genes(indata, GENE1C, Per_Gene);
		Get_Genes(indata, GENE2C, Per_Gene);
		Get_Genes(indata, GENE1D, Per_Gene);
		Get_Genes(indata, GENE2D, Per_Gene);
	

	//funtion call to compare the person gene to know the condition
		Check_Genes(outdata, GENE1A, GENE2A, 'W');
		Check_Genes(outdata, GENE1B, GENE2B, 'X');
		Check_Genes(outdata, GENE1C, GENE2C, 'Y');
		Check_Genes(outdata, GENE1D, GENE2D, 'Z');

		//calling function  to check related genes
		if (Same_Gene(GENE1A, GENE1B, Per_Gene) || Same_Gene(GENE1A, GENE2B, Per_Gene) || Same_Gene(GENE2A, GENE1B, Per_Gene) || Same_Gene(GENE2A, GENE1B, Per_Gene))
		{
			outdata << "Person W is related to person X" << endl;
		}
		else if (Same_Gene(GENE1A, GENE1C, Per_Gene) || Same_Gene(GENE1A, GENE2C, Per_Gene) || Same_Gene(GENE2A, GENE1C, Per_Gene) || Same_Gene(GENE2A, GENE2C, Per_Gene))
		{
			outdata << "Person W is related to person Y" << endl;
		}
		else if (Same_Gene(GENE1A, GENE1D, Per_Gene) || Same_Gene(GENE1A, GENE2D, Per_Gene) || Same_Gene(GENE2A, GENE1D, Per_Gene) || Same_Gene(GENE2A, GENE2D, Per_Gene))
		{
			outdata << "Person W is related to person Z" << endl;
		}
		else  if (Same_Gene(GENE1B, GENE1C, Per_Gene) || Same_Gene(GENE1B, GENE2C, Per_Gene) || Same_Gene(GENE2B, GENE1C, Per_Gene) || Same_Gene(GENE2B, GENE2C, Per_Gene))
		{
			outdata << "person X is related to person Y" << endl;
		}
		else if (Same_Gene(GENE1B, GENE1D, Per_Gene) || Same_Gene(GENE1B, GENE2D, Per_Gene) || Same_Gene(GENE2B, GENE1D, Per_Gene) || Same_Gene(GENE2B, GENE2D, Per_Gene))
		{
			outdata << "Person X is related to person Z" << endl;
		}
		if (Same_Gene(GENE1C, GENE1D, Per_Gene) || Same_Gene(GENE1C, GENE2D, Per_Gene) || Same_Gene(GENE2C, GENE1D, Per_Gene) || Same_Gene(GENE2C, GENE2D, Per_Gene))
		{
		  outdata << "Person Y is related to person Z" << endl;
		}

	return 0;

}
//********************************************************************************************
void Get_Genes(ifstream& indata, char Dna_gene[], int per_gene)  //assigns all chars to each array called while not end of file
{
	for (int index = 0; index < per_gene; index++)
	{
		indata >> Dna_gene[index];
	}
}
// compares the genes 
void Check_Genes(ofstream& outdata, char gene1[], char gene2[], char person)
{
	int Tpos = 19;
	if ((gene1[Tpos] == 'T') && (gene2[Tpos] == 'T'))
	{
		outdata << "Person " << person << " is anaemic " << endl;
	}
	else if ((gene1[Tpos] == 'T') || (gene2[Tpos] == 'T'))
	{
		outdata << "Person " << person << " is a carrier " << endl;
	}
	else
	{
		outdata << "Person " << person << " is normal " << endl;
	}

}
bool Same_Gene(const char gene1[], const char gene2[], const int size)
{
		if (gene1[size] == gene2[size])
		{
			return true;
		}
		else
			return false;
}
