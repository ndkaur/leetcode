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
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int  pos =0;
        int neg =0;
        for(int i=0; i<n; i++){
            if(nums[i] >0)
                pos++;
            else if(nums[i] < 0)
                neg++; 
        }
        return max(pos,neg);
    }
};

int main(){

    return 0;
}