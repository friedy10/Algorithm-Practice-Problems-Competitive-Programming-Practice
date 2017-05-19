#include<iostream>
#include<vector>

using namespace std;
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);

int main() {

	vector<int> nums;
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(2);

	vector<int> findnums;
	findnums.push_back(1);
	findnums.push_back(3);
	findnums.push_back(4);
	findnums.push_back(2);

	vector<int> result = nextGreaterElement(findnums, nums);
	cout << result[0] << "," << result[1] << "," << result[2];
	system("PAUSE");
}

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	//Write Code to Solve this problem
	/*  Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
		Output: [-1,3,-1]
		Explanation:
			For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
			For number 1 in the first array, the next greater number for it in the second array is 3.
			For number 2 in the first array, there is no next greater number for it in the second array, so output -1.*/

	//Simple Solution O(n^2) time complexity
	vector<int> found;
	for (int i : nums) {
		cout << i << endl;
		for (int j : findNums) {
			int pos = std::find(findNums.begin(), findNums.end(), j) - findNums.begin();
			int pos2 = std::find(nums.begin(), nums.end(), j) - nums.begin();
			if ( (i == j) ){
				if ((pos + 1) <= (findNums.size() - 1)) {
					if (findNums[pos + 1] > nums[pos2]) {
						found.push_back(findNums[pos + 1]);
					}
				}
			}
			else {
				if (pos == (findNums.size() - 1)) {
					found.push_back(-1);
				}
			}
		}
	}
	return found;
}