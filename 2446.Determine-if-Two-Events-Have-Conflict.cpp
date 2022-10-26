#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// overlap 
// side     s1 s2 e1 e2   event1[0] <= event2[0] && event2[0] <= event1[1]
// center   s1 s2 e2 e1   event1[0] <= event2[0] && event2[0] <= event2[1] // no need all coverd in outside cases 
// side     s2 s1 e2 e1   event2[0] <= event1[0] && event1[0] <= event2[1]

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // overlap  start1 <= end2  && end1 >= start2 
        
        if(event1[0] <= event2[1] && event1[1] >= event2[0])
            return true;
        return false;
    }
};

int main(){

    return 0;
}