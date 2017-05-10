#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int lengthOfLongestSubstring(string s);


int main()
{
	string str;
	cout << "Enter String" << endl;
	cin >> str;

	cout << lengthOfLongestSubstring(str) << endl;

	system("PAUSE");
	return 0;
}

int lengthOfLongestSubstring(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}