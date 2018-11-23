/********************************************************************************
programmer name: Okpala Chidiebere Collins
programmer number: 200356606
programmer Date: 7th November, 2014.
main algorithm:
- its rolls the two dies by calling the getRoll function
-  it calculates the sum by calling the calsum function
- it compares the sum to the first, second and third statement to process.
- if the sum is 7 or 11, the person wins
- if the sum is 2,3, or 12, the person losses
- if the sum is 4, 5, 6, 8, 9, or 10, the prints out the point and rolls the dies
again, calculates it.
then
  -if the initial sum is equal to the second sum the person wins
  - if it is not equal the person losses
**************************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
//declaring subfunctions(prototypes)
void GetRoll(int&);
void CalcSum(int, int, int&);
void Print(int, int, int);

using namespace std;
//declaring variables
int Roll=0;
int Die1;
int Die2;
int Sum;

int main()
{
	//invoking functions
	GetRoll(Roll); //rolls the two dies
	CalcSum(Die1, Die2, Sum); //calculate the sum
	Print(Die1, Die2, Sum);  //prints the output

	return 0;
}
//******************************************************************************************
//a sub-function for rolling of the dies
void GetRoll(int& count) 
{
	while (count < 1)  //count controll loop to roll both dies once
	{
		srand(time(0));
		Die1 = rand() % 6 + 1;
		Die2 = rand() % 6 + 1;
		count++;
	}
	count = 0;  //initializes it to zero after the looping for it not to retain the loopcount when invoked again
}
// a sub-function for getting the sum of the dies
void CalcSum(int die1, int die2, int& sum)
{
	sum = die1 + die2;
}
// a sub - function to print what was gotten.both the dies values and the sum.
void Print(int die1, int die2, int sum)
{
	cout << "You rolled " << die1 << " + " << die2 << " = " << sum << endl;
	if (sum == 2 || sum == 3 || sum == 12)
	{
		cout << "You lose" << endl;
		return;
	}
	 if (sum == 7 || sum == 11)
	{
		cout << "You win" << endl;
		return;
	}
	 if (sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10)
	 {
		 cout << "point is " << sum << endl;
		 GetRoll(Roll); //invoking subfunction to roll another dies
		 CalcSum(Die1, Die2, Sum);  //gets the sum
		 cout << "You rolled " << Die1 << " + " << Die2 << " = " << Sum << endl;
		 if (sum == Sum)
		 {
			 cout << "You win" << endl;
		 }
		 if (sum!=Sum)
		 {
			 cout << "You lose" << endl;
		 }
	 }
	 return;
}
