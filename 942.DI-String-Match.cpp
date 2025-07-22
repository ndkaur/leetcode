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
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> nums;
        for(int i=0; i<=n; i++){
            nums.push_back(i);
        }

        int i = 0;
        int j = nums.size()-1;
        vector<int> ans;
        for(auto ch:s){
            if(ch=='I'){
                ans.push_back(nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]);
                j--;
            }
        }
        while(i<=j){
            ans.push_back(nums[i]);
            i++;
        }
        return ans;
    }
};

// 0 1 2 3 4


int main(){

    return 0;
}