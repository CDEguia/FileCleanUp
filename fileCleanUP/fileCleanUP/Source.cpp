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
	if (temp >= '0' && temp <= '9') {
		return true;
	}
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

int isReserved(string fullset, int &start, char set[][10]) {
	for (int n = 0; n < 4; n++) {	//Reserved word check
		if (fullset[start] == set[n][0]) {
			int counter = 0;
			bool check = true;
			for each (char temp in set[n])
			{
				if (fullset[start + counter] != temp) {
					check = false;
					break;
				}
				counter++;
			}
			if (check == true) { start += counter - 1; return n; }
			return -1;
		}
	}
	return -1;
}

int main() {
	char reservedWords[4][10] = { "cout<<","for","int","while" };
	char special[8] = { '+' , '=' , '*' , '-' , ';' , '(' , ')' , ',' };
	string w;						//hold line
	fstream inp, outp;				//base file
	
	inp.open("data.txt", ios::in);	//open the file that includes the strings to check
	outp.open("newdata.txt", ios::out);
	getline(inp, w);				//get the first line in the file

	while (!inp.eof())				//loop through the lines in the text file
	{
		int i = 0;
		while (w[i] != NULL)		//loops through character in each line
		{
			if (w[i] == '/' && w[i + 1] == '/') {
				break; //skips any commented code & gets next line
			}
			else if (w[i] == ' ') {
				//does nothing but get next char
			}
			else if (isNumber(w[i])) // Integer check
			{						//single digits only
				outp << w[i] << " ";
				cout << w[i] << " ";
			}
			else if (isLetter(w[i])) {
				int word = isReserved(w, i, reservedWords);
				if (word != -1) {
					outp << reservedWords[word] << " ";
					cout << reservedWords[word] << " ";
				}
				else {
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
				if (w[i] == ';') {
					outp << w[i] << endl;
					cout << w[i] << endl;
				}
				else {
					outp << w[i] << " ";
					cout << w[i] << " ";
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