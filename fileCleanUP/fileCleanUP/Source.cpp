//---------------------------------------------------------------
//          Name		Candelario D. Eguia
//			Name        Jeremy Driesler
//          Course		CMPS-455
//          Project		No.4
//          Due date	Mar. 11, 2015
//          Professor	Ray Ahmadnia
//
// This program will:
//       Clean up and copy a text file
//------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
	char reservedWords[4][10] = { "cout<<","for","int","while" };
	char special[10][3] = { "+" , "=" , "*" , "-" , ";" , "(" , ")" , "<=", "//", "," };
	string w;						//hold line
	fstream inp, outp;				//base file
	
	inp.open("data.txt", ios::in);	//open the file that includes the strings to check

	getline(inp, w);				//get the first word in the file
	
	while (!inp.eof())				//loop through the lines in the text file
	{
		int i = 0;
		while (w[i] != '\n')		//loops through character in each line
		{
			if (w[i] == '/' && w[i + 1] == '/') break; //skips any commented code

			i++;
		}
		getline(inp, w);			//get the next line
	}
	//close the file stream
	inp.close();
	outp.close();
	//terminate the program
	system("pause");
	return 0;
}