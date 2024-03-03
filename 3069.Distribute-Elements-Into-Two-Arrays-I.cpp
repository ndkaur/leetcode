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
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1(1, nums[0]);
        vector<int> v2(1, nums[1]);

        for(int i=2; i < nums.size(); ++i){
            if(v1.back() > v2.back()) 
                v1.push_back(nums[i]);
            else 
                v2.push_back(nums[i]);
        }
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    
    }
};

int main(){

    return 0;
}