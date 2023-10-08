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

class Solution {
public:
    int minProcessingTime(vector<int>& time, vector<int>& tasks) {
        int n = time.size();
        int m = tasks.size();
        // main logic :-  give the maximum process time to minimum 4 tasks
        // process time  in decreasing order 
        // tasks time in ascending order 

        sort(tasks.begin(), tasks.end());
        sort(time.begin(), time.end(),[](const int a, const int b){ 
                        return a>b;}); // descending order
        
        int idx =0; // idx of task array 
        int mx =0;
        // each processor can take 4 core 
       
        for(int i=0; i<n; i++){ // using loop on time array wrt first 4 tasks
            int cur =0;
            int cnt =0; // cnt of 4 cores
            while(idx<m && cnt<4){ // 
                cur = max(cur, time[i]+tasks[idx]);
                idx++;
                cnt++;
            }
            mx = max(mx, cur);
        }
        return mx;
    }
};

int main(){

    return 0;
}