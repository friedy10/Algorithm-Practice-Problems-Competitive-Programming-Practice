#include<bits/stdc++.h>
 
using namespace std;

int count(int amount, vector<int> coins)
{
   vector<int> combinations(amount+1);

   combinations[0] = 1;
   
   for(int i = 0; i < coins.size(); ++i){
       for(int j = 1; j < combinations.size(); ++j){
           if(j >= coins[i]){
               combinations[j] += combinations[j - coins[i]];
           }
       }
   }
   return combinations[amount];
}
 
// Driver program to test above function
int main()
{
    int a,n;
    vector<int> vec;
    cin >> a >> n;
    while(n--){
        int coin;
        cin >> coin;
        vec.push_back(coin);
    }

    cout << count(a, vec) << endl;
    return 0;
}