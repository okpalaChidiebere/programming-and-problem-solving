/******************************************************************
file name: cs assignment1(one)
programmer name: okpala chidiebere collins
programmer student number: 200356606
date programmed: 26th september, 2014
programming information:
 this is to convert Tons to Pounds, Ounces, Grams, kilograms
 numberofTons -      the number of tons entered by the user
 Tons_to_Pound -     oneTons = 2000Pounds
 Tons_to_Ounce -     oneTon = 32000Ounces
 Tons_to_Gram -      oneTon = 907185Grams
 Tons_to_Kilograms - oneTon = 907.185Kilograms

*******************************************************************/

#include<iostream>
using namespace std;

int main()
{
	double numberofTons;
	const double numberofPounds = 2000;
	const double numberofOunces= 32000;
	const double numberofGrams= 907185;
	const double numberofKilograms= 907.185;
	cout << fixed ; 
	    //step 1: inform the user to write number of tons
	    cout << "please enter number of tons to be converted: ";
		//step 2: numberofTons to be entered by the user
		cin >> numberofTons;
		//step 3: compute numberofTons to be converted to pounds and display result
		cout << "number of tons in pounds:  " << numberofTons * numberofPounds << "(ibs)" << endl <<endl;
		//step 3: compute numberofTons to be converted to Ounces and display result
		cout << "number of tons in ounces:  " << numberofTons * numberofOunces << "(bz)" << endl << endl;
		//step 4: compute numberofTons to be converted to Grams and display result
		cout << "number of tons in grams:  " << numberofTons * numberofGrams << "(g)" << endl << endl;
		//step 5: compute numberofTons to be converted to Kilograms and display result
		cout << "number ot tons in kilograms:  " << numberofTons * numberofKilograms << "(kg)" << endl << endl;

		return 0;


}
