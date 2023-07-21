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
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp1,mp2;
        // split when fre * 2 > size 
        for(int num:nums){
            mp2[num]++;
        }
        // at any index i if split made the freq of ith ele will be 
        // for the left size split = cnt in current map 
        // for the right split = cnt in original total map - current map 
        for(int i=0; i<n; i++){
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            int freq1 = mp1[nums[i]];
            int freq2 = mp2[nums[i]]; 
            // fre * 2 > sz
            if(freq1*2 >(i+1) && freq2*2 > (n-i-1))
                return i;
        }
        return -1;
    }
};

int main(){

    return 0;
}