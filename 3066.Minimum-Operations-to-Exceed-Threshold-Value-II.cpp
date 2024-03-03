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
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
     
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        while(pq.size() && pq.top()<k){
            long long one = pq.top();
            pq.pop();
            long long two = pq.top();
            pq.pop();
            long long temp = one*2 + two;
            pq.push(temp);
            cnt++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}