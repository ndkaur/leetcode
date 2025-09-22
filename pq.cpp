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


class myComparator {
public:
    bool operator() (const pair<int,string>& p1, const pair<int,string>& p2) const {
        if (p1.first == p2.first)  // same rating
            return p1.second > p2.second;  // lexicographically smaller comes first
        return p1.first < p2.first; // higher rating first
    }
};

class Solution {
public: 
    void prio(vector<pair<int,string>>& temp) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, myComparator> pq;
        // priority_queue<pair<int,string>> mx_heap; 
        // priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> mn_heap;
        
        for (auto &itr : temp) {
            pq.push(itr);
        }

        while (!pq.empty()) {
            cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
        }
    }
};


int main() {
    Solution sol;
    vector<pair<int,string>> temp = {
        {1,"apple"},
        {1,"mango"},
        {2,"zebra"},
        {3,"elephant"},
        {8,"hen"}
    };
    sol.prio(temp);
    return 0;
}
