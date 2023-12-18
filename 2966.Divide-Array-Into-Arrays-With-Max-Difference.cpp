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

class Solution { // O(NlogN)
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // logn
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=2; i<n; i+=3){
            if(nums[i]-nums[i-2]>k) // if last pair has diff > k then cna tpossible
                return {};
            ans.push_back({nums[i-2], nums[i-1], nums[i]});
        }
        return ans;
    }
};

int main(){

    return 0;
}