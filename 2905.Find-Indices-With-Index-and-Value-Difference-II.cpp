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
    vector<int> findIndices(vector<int>& nums, int d, int v) {
        int n = nums.size();
       // i -j = diff    , so i-diff = j => j is the min to satisty condtion 
       int mn=0;
       int mx =0;
        for(int i=d; i<n; i++){
            if(nums[i-d] < nums[mn])
                mn = i-d;
            if(nums[i-d] > nums[mx])
                mx = i-d;
            if(nums[i]- nums[mn] >= v)
                return {mn, i};
            if(nums[mx] -nums[i] >=v)
                return {mx,i};
        }
        return {-1,-1};
    }
};



int main(){

    return 0;
}