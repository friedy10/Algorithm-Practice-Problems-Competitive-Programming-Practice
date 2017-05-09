#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target);
int main()
{
    vector<int> myjunk;
    myjunk.push_back(1);
    myjunk.push_back(2);
    myjunk.push_back(3);
    myjunk.push_back(4);

    int target = 3;

    vector<int> power = twoSum(myjunk,target);
    cout << power[0] << endl;
    cout << power[1] << endl;
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
   map<int, int> mymap;
   vector<int> collect;
   for(int i = 0; i < nums.size(); i++){
        int needed = target - nums[i];

        if(mymap.find(needed) != mymap.end()){
            int index1 = mymap[needed];
            int index2 = i;
            collect.push_back(index1);
            collect.push_back(index2);
            return collect;
        }else{
            mymap[nums[i]] = i;
        }

   }
   return collect;
}
