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
	fstream inp;					//base file
	
	inp.open("data.txt", ios::in);	//open the file that includes the strings to check
	
	getline(inp, w);				//get the first word in the file
	
	while (!inp.eof())				//loop through the words in the text file
	{
		
		getline(inp, w);			//get the next word
	}
	//close the file stream
	inp.close();
	//terminate the program
	system("pause");
	return 0;
}