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

class Solution { // O(n+m log n)
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pair<int,int>>> pq;

        for(auto c:classes){
            int pass = c[0];
            int total = c[1];
            long double ratioo = (double)(pass+1)/(total+1) - (double)(pass)/total;
            pq.push({ratioo, {pass, total}});
        }

        while(extraStudents){
            auto t = pq.top();
            pq.pop();
            extraStudents--;

            double pass = t.second.first;
            double total = t.second.second;
            pass++;
            total++;
            long double ratioo = (double)(pass+1)/(total+1) - (double)(pass)/total;

            pq.push({ratioo, {pass, total}});
        }

        double ans = 0;
        while(pq.size()){
            auto t = pq.top();
            pq.pop();
            ans += (double)(t.second.first)/(t.second.second);
        }
        return (double)ans/(classes.size());
    }
};

// we need to find the ratio that will have max increment using formula 
// a/b - (a+1)/(b+1)
// we use heap to store this value for each class then increment extra student for the top elem on the max heap 

int main(){

    return 0;
}