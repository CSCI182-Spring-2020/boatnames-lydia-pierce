// Lydia Pierce
// CSCI 182
// BoatNames1.cpp : Opens a file "BoatNames.txt", reads the data listed
// and inputs it into an array, then prints the data to the screen.
// v1.0 2/17/2020

#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX_BOAT_COUNT 30

using namespace std;

struct Boat {
	int nYearBuilt;
	string Name;
};


int main()
{


	// Start by reading in the files
	ifstream inFile;

	inFile.open("BoatNames.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}


	Boat Fleet[MAX_BOAT_COUNT];

	// Put all the boat names into an array, then print them to the screen
	char tempName[80];
	int nYear;
	int importCount = 0;

	// Read the input file for each player
	while (!inFile.eof() && importCount < MAX_BOAT_COUNT) {
		// Read in line
		inFile >> tempName >> nYear;


		// Write to Fleet's Structure here
		Fleet[importCount].Name = tempName;
		Fleet[importCount].nYearBuilt = nYear;

		importCount++;
	}
	// Close the input file
	inFile.close();


	// Now, print out each boat name by calling a
	// function to print each array item

	for (int printCounter = 0; printCounter < MAX_BOAT_COUNT; printCounter++)
	{
		cout << Fleet[printCounter].Name << " " << Fleet[printCounter].nYearBuilt << "\n";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
