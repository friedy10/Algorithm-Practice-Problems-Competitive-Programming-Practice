#include <bits/stdc++.h>

using namespace std;

float computeAverage(vector<float> values);
float roundTwo(float num);

int main(){
    vector<float> results;
    while(true){
        int n;
        cin >> n;
        vector<float> money;
        if(n == 0) break;
        while(n--){
            float hand; 
            cin >> hand;
            money.push_back(hand);
        }
        float avg = roundTwo(computeAverage(money));
        float payment = 0;
        float npayment = 0;
        for(float x : money){
            if(x > avg){
                payment += x - avg;
            }else{
                npayment += avg - x;
            }
        }
        results.push_back((npayment < payment ? npayment : payment));
        money.clear();
    }
    for(float r : results){
        cout << "$" << r << endl;
    }
}

float computeAverage(vector<float> values){
    float total;

    for(float x : values){
        total +=x;
    }
    return (total / values.size());
}

float roundTwo(float num){
    float j = (int) (num * 100 + .5);
    return (float) j/100;
}