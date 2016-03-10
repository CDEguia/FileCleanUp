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
<<<<<<< HEAD
bool isNumber(char temp) {
	if (temp >= '0' && temp <= '9')
		return true;
	else
	{
		return false;
	}
}

bool isLetter(char temp) {
	if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')) {

		return true;
	}
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
=======
>>>>>>> refs/remotes/origin/master

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
		while (w[i] != NULL)		//loops through character in each line
		{
<<<<<<< HEAD
			if (w[i] == '/' && w[i + 1] == '/') {
				break; //skips any commented code
			}
			else if (w[i] == ' ') {

			}
			else if (isNumber(w[i])) // Integer check
			{
				outp << w[i] << " ";
				cout << w[i] << " ";
			}
			else if (isLetter(w[i])) {
				bool found = false;
				for (int n = 0; n < 4; n++) {	//Reserved word check
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
							found = true;
							string temp = reservedWords[n];
							outp << temp << " ";
							cout << temp << " ";
							i += counter - 1;
						}
					}
				}
				if (found == false) {
					while (!isSpecial(w[i], special) && w[i] != ' ') {
						outp << w[i];
						cout << w[i];
						i++;
					}
					i--;
					outp << " ";
					cout << " ";
				}
			}
			else
			{
				//cout << "Special\n";
				for (int n = 0; n < 8; ++n) {			// Special symbol check
					if (special[n] == w[i]) {
						if (w[i] == ';') {
							outp << w[i] << endl;
							cout << w[i] << endl;
						}
						else {
							outp << w[i] << " ";
							cout << w[i] << " ";
						}
						break;
					}
				}
			}

=======
			if (w[i] == '/' && w[i + 1] == '/') break; //skips any commented code
>>>>>>> refs/remotes/origin/master

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