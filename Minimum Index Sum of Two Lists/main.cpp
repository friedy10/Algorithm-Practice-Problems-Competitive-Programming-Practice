#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;
string findRestaurant(vector<string>& list1, vector<string>& list2);

int main(){
	vector<string> v;
	vector<string> v2;
	v.push_back("McDonalds");
	v.push_back("KFC");
	v.push_back("Burger King");
	v.push_back("Canes");

	v2.push_back("McDonalds");
	v2.push_back("KFC");
	v2.push_back("Burger King");
	v2.push_back("CanesD");

	cout << findRestaurant(v,v2);
	return 0;

}

string findRestaurant(vector<string>& list1, vector<string>& list2) {
	map<int,string> mymap;
	vector<int> tmp;
	vector<char> string;
	for(int i = 0; i < list1.size(); i++){
		for(int j = 0; j < list2.size(); j++){
			if(list1[i] == list2[j] && (mymap.find(i + j) == mymap.end())){
				mymap[i + j] = list1[i];
				tmp.push_back(i + j);
			}
		}
	}

	int biggest = 0;
	for(int i = 0; i < tmp.size(); i++){
		if(biggest < tmp[i]){
			biggest = tmp[i];
		}
	}
	return mymap[biggest];
}