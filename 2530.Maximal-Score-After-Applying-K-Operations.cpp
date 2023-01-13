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
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int num:nums){
            pq.push(num);
        }
        long long ans =0;
        while(k-- && pq.size()){
            int t = pq.top();
            ans += t;
            pq.pop();
            pq.push(ceil((double)t/3));
        }
        return ans;
    }
};

int main(){

    return 0;
}