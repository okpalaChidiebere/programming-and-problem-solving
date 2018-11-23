/*******************************************************************************************************************
file name: cs assignment 2/main.cpp
programmer name: Okpala Chidiebere Collins
programmer student number: 200356606
date programmed: 12th october, 2014.
programming information:  This programmed is designed to solve the possible following calculation of any circle
in mathematics, which are:
-circumference: using the formula radius*2*PI
-diameter: using the formula 2*radius
-area: using the formula radius*radius*PI

NOTE in the course of the calculation that "PI" is a constant float value.
the programm reads the input from the user through a created file "circle.txt" and displays the output, which is the
result of the calculation to another file which is "result.txt"


********************************************************************************************************************/

#include<iostream>  //declearing opreators to be used
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int main()    //where the main programing starts
{
	fstream input; //declearing file to be read from
	fstream output;//declearing file to give output
	input.open("circle.txt");//opens the file to be read file
	output.open("result.txt");//opens the file we will print the result to


	if (!input)// boolean declaration to avoid unnecessary spelling of input
	{
		output << "Not able to open circle.txt.EXITING.....";
		return 1;
	}

	if (!output)//boolean declaration to avoid unnecessary spelling of output
	{
		output << "not able to open result.txt.EXITING.....";
		return 2;
	}
	char letter;// declearing variable letter where letter inputed by the user will be stored
	float radius;
	const float PI = 3.14159265;//constant in the calculation


	
	input >> letter;      //any of the letter inputed by the user from the input file("circle.txt)
	output << fixed << showpoint;    //for floating values to be displayed
	if (letter == 'C' || letter == 'c')//giving the program more option, incasxe a small letter is entered by the user&& statement becomes true if c is entered
	{
		output << "you are solving for circumference." << endl;//prompt the user on the calculation for the any of the alphabet used
		input >> radius;     //user types in radius
		if (radius >= 0)   //a boolean expression for the nature of the radius that must be inputed by the user
			output << "circumference is: " << setprecision(2) << 2 * PI*radius;//calculation proper with the amount of decimal place needed which is two
		else
			output << "you entered a negative number for radius. Not possible!! " << endl;//when a negative radius is inputed by the user, it gives an error
	}
	else if (letter == 'd' || letter == 'D')// a boolean expression if d is entered&& calculation for diameter proper
	{
		output << "you are solving for diameter. " << endl;//inform the user of the calculation about to be solved
		input >> radius;   //user types in radius
		if (radius >= 0)//a boolean expression for the nature of the radius that must be inputed by the user
			output << "diameter is: " << setprecision(2) << 2 * radius;//calculation proper with the amount of decimal place needed which is two
		else
			output << "you entered a negative number for radius. Not possible!! " << endl;//when a negative radius is inputed by the user, it gives an error
	}
	else if (letter == 'A' || letter == 'a') // a boolean expression if d is entered&& calculation for diameter proper
	{
		output << "you are solving for area." << endl; //inform the user of the calculation about to be solved
		input >> radius;  //user types in radius
		if (radius >= 0)     //a boolean expression for the nature of the radius that must be inputed by the user
			output << "Area is: " << setprecision(2) << radius*radius*PI;    //calculation proper with the amount of decimal place needed which is two
		else
			output << "you entered a negative number for radius. Not possible!! " << endl;//when a negative radius is inputed by the user, it gives an error
	}
	else
		output << "You entered an unidentified alphabet for the calculation!!! " << endl;//final error for if any of the alphabet is not entered

	return 0;
}
