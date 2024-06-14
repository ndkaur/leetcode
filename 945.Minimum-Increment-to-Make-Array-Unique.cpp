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
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //1 1 2 2 3 7
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){ // we sorted array so the prev num cant be greater , if its greater then that means we have done a move of increment 
                // cnt is the diff btw two nums and add1 for 1move
                cnt+=(nums[i-1]+ 1- nums[i]);
                nums[i] = nums[i-1]+1;
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}