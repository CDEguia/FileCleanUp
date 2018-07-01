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
	for (int i = 0; i < 10; ++i) {			// Special symbol check
		if (spec[i] == temp)
		{
			return true;
		}
	}
	return false;
}

int isReserved(char test[], char set[][10]) {
	for (int n = 0; n < 4; n++) {	//Reserved word check
		if (test[0] == set[n][0]) {
			int counter = 0;
			bool check = true;
			for (char temp : set[n])
			{
				if (test[counter] != temp) {
					if (temp != '\0') {
						check = false;
						break;
					}
				}
				counter++;
			}
			if (check == true) { return n; }
			return -1;
		}
	}
	return -1;
}

int main() {
	char reservedWords[4][10] = { "cout<<","for","int","while" };
	char special[10] = { '+' , '=' , '*' , '-' , ';' , '(' , ')' , ',' , '{' , '}' };
	char w[200];

	fstream inp, outp;				//base file

	inp.open("data.txt", ios::in);	//open the file that includes the strings to check
	outp.open("newdata.txt", ios::out);

	inp.getline(w, 200);
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
			else if (w[i] == '"'){
                outp << w[i];
				cout << w[i];
				while(w[++i] != '"'){
                    outp << w[i];
                    cout << w[i];
				}
				outp << '"';
				cout << '"';
			}
			else if (isNumber(w[i])) // Integer check
			{
				outp << w[i];
				cout << w[i];
				while(isNumber(w[++i])){
                    outp << w[i];
                    cout << w[i];
				}
				--i;
				outp << " ";
				cout << " ";
			}
			else if (isLetter(w[i])) {
					char word[10];
					int n = 0;
					while (!isSpecial(w[i], special) && w[i] != ' ') {
						word[n] = w[i];
						i++; n++;
					}
					i--;
					word[n] = char(0);
					int check = isReserved(word, reservedWords);
					if (check != -1) {
						outp << reservedWords[check];
						cout << reservedWords[check];
					}
					else
					{
						cout << word;
						outp << word;
					}
					outp << " ";
					cout << " ";
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
		inp.getline(w, 200);
	}
	//close the file stream
	inp.close();
	outp.close();
	//windows pause the program
	//std::system("pause");
	return 0;
}
