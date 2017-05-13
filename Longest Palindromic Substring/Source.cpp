#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int expandAroundTheCenter(string s, int left, int right);
string longestPalindrome(string s);

int main() {

	string str;
	cout << "Enter string\n";
	cin >> str;

	cout << longestPalindrome(str) << endl;
	system("PAUSE");
	return 0;
}


string longestPalindrome(string s) {
	int start = 0, end = 0;

	for (int i = 0; i < s.length(); i++) {
		int len;
		int len1 = expandAroundTheCenter(s, i, i);
		int len2 = expandAroundTheCenter(s, i, i + 1);
		len = max(len1, len2);
		if (len > end - start) {
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	return s.substr(start, end -1 );
}

int expandAroundTheCenter(string s, int left, int right) {
	int L = left, R = right;

	// The Following expression checks if it is a palindrome
	while (L >= 0 && R < s.length() && s[L] == s[R]) {
		L--;
		R++;
	}
	return R - L - 1;
}