#include<iostream>
#include<fstream>
#include<string>

using namespace std;
string convert(string s, int rows);

int main() {
	int rows;
	string str;
	cout << "Enter String\n";
	cin >> str;

	cout << "Enter Number of Rows\n";
	cin >> rows;

	cout << convert(str, rows) << endl;
	system("PAUSE");
}

string convert(string s, int rows) {
	int currentrow = 0, step = 0;

	if (rows < 1) {
		return s;
	}

	//An array of strings
	string *str = new string[rows];

	for (int i = 0; i < s.length(); ++i) {
		str[currentrow].push_back(s[i]);

		//Row Control
		if (currentrow == 0) {
			//Let's step over to the next
			step = 1;
		}
		else if (currentrow == rows - 1) {
			//Go back to a previous row
			step = -1;
		}

		currentrow += step;
	}

	string junk;
	for (int i = 0; i < rows; ++i) {
		//add each string to the end of this junk
		junk.append(str[i]);
	}

	//Delete the variable from thjue computers memory
	delete[] str;
	return junk;
}