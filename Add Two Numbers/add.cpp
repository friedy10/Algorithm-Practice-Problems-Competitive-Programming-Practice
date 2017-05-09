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