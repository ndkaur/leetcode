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
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        // prefix sum
        vector<int> temp(n+1, 0);
        for(auto q:queries){
            temp[q[0]]++;
            temp[q[1]+1]--;
        }
        int sum =0;
        for(int i=0; i<n; i++){
            sum+=temp[i];
            if(sum<nums[i])
                return false;
        }
        return true;
    }
};

int main(){

    return 0;
}