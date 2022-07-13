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
    int fillCups(vector<int>& amount) {
        int n= amount.size();
        priority_queue<int> pq;

        for(int a:amount){
            if(a>0)
                pq.push(a);
        }

        int cnt=0;
        while(!pq.empty() && pq.size()>1){
            int a= pq.top()-1;
            pq.pop();
            int b= pq.top()-1;
            pq.pop();

            cnt++;
            if(a>0) pq.push(a);
            if(b>0)  pq.push(b);
        }
        if(pq.size())
            cnt+= pq.top();
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> nums={5,4,4};
    int ans= sol.fillCups(nums);
    cout<<ans;
    return 0;
}