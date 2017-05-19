#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int singleNonDuplicate(vector<int>& nums);
int search(vector<int>& v, int low, int high);

int main() {

	vector<int> power;
	power.push_back(1);
	power.push_back(1);
	power.push_back(2);


	cout << singleNonDuplicate(power) << endl;
	system("PAUSE");
	return 0;
}

int singleNonDuplicate(vector<int>& nums) {
	return (search(nums, 0, nums.size() - 1));
}

int search(vector<int>& v, int low, int high) {
	if (low > high)
		return v[low];

	if (low == high)
	{
		return v[low];
	}

	// Find the middle point
	int mid = (low + high) / 2;

	// If mid is even and element next to mid is
	// same as mid, then output element lies on
	// right side, else on left side
	if (mid % 2 == 0)
	{
		if (v[mid] == v[mid + 1])
			search(v, mid + 2, high);
		else
			search(v, low, mid);
	}
	else  // If mid is odd do this junk
	{
		if (v[mid] == v[mid - 1])
			search(v, mid - 2, high);
		else
			search(v, low, mid - 1);
	}
}