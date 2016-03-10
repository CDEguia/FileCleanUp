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
bool isNumber(char temp) {
	if (temp >= '0' && temp <= '9')
		return true;
	else
	{
		return false;
	}
}

bool isLetter(char temp) {
	if ((temp >= 'a' && temp <= 'z') && (temp >= 'A' && temp <= 'Z'))
		return true;
	else
	{
		return false;
	}
}

bool isSpecial(char temp, char spec[]) {
	for (int i = 0; i < 8; ++i) {			// Special symbol check
		if (spec[i] == temp) 
		{ 
			return true; 
		}
	}
	return false;
}

int main() {
	char reservedWords[4][10] = { "cout<<","for","int","while" };
	char special[8] = { '+' , '=' , '*' , '-' , ';' , '(' , ')' , ',' };
	string w;						//hold line
	fstream inp, outp;				//base file
	outp.open("newdata.txt", ios::out | ios::binary);
	inp.open("data.txt", ios::in);	//open the file that includes the strings to check

	getline(inp, w);				//get the first word in the file
	
	while (!inp.eof())				//loop through the lines in the text file
	{
		int i = 0;
		while (w[i] != '\n')		//loops through character in each line
		{
			if (w[i] == '/' && w[i + 1] == '/') break; //skips any commented code
			
			bool found = false;				// changes to TRUE once string is found
			
			if (isNumber(w[i])) {		// Integer check
				char temp = w[i];
				outp >> temp >> " ";
			}
			else {			// string is not an integer check for reserved... 
				if (isLetter(w[i])) {
					for (int n = 0; n < 4; n++) {
						if (w[i] == reservedWords[n][0]) {
							int counter = 0;
							bool check = true;
							for each (char temp in reservedWords[n])
							{
								if (w[i + counter] != temp)
									check = false;
								counter++;
							}
							if (check = true) {
								string temp = reservedWords[n];
								outp >> temp >> " ";
								i += counter;
								found = true; 
								break;
							}
						}
					}										
					if (found == false) { 
						int counter = 0;
						while (!isSpecial(w[i], special)) {
							outp >> w[i];
							i++;
						}
						outp >> " ";
						break;
					}
				}
				for (int i = 0; i < 8; ++i) {			// Special symbol check
					if (special[i] == w[i]) {
						if (w[i] == ';') {
							outp >> w[i] >> "\n";
						}
						else {
							outp >> w[i] >> " ";
						}
						break;
					}
				}
			}
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