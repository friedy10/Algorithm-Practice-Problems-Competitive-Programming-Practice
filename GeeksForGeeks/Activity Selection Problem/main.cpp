#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


struct Activiy {
    int start;
    int finish;
};

// Used to sort by finish time
bool compare(Activiy a, Activiy b){return a.finish < b.finish;};

vector<Activiy>
SortAndSetup(int a[], int b[]){
    vector<Activiy> active;
    int size = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < size+1; i++){
        Activiy ac;
        ac.start = a[i];
        ac.finish = b[i];
        cout << "PUSHING BACK " << a[i] << " " << b[i] << endl;
        active.push_back(ac);
    }
    sort(active.begin(), active.end(), compare);
    return active;
}

void
printAll(vector<int> a){
    for(std::vector<int>::iterator it = a.begin(); it != a.end(); ++it){
        cout << *it << endl;
    }
}

int 
main(){
    int a[] = {10,20,12};
    int b[] = {20,30,25};

    vector<int> posible_activites;
    vector<Activiy> prob = SortAndSetup(a,b);

    int j = 0;
    cout << "WORKING" << endl;
    posible_activites.push_back(0);

    for(size_t i=1; i < prob.size(); i++){
        if (prob[i].start >= prob[j].finish){
            posible_activites.push_back(i);
            j = i;
        }
    }
    printAll(posible_activites);
    return 0;
}