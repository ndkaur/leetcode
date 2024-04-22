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
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        string temp = "";

        for(int i=0; i<n; i++){
            int j = i;
            while(j+1<n && nums[j+1]==nums[j]+1){
                j++;
            }
            if(j>i){
                temp += to_string(nums[i]);
                temp += "->";
                temp += to_string(nums[j]);
            }
            else{
                temp += to_string(nums[i]);
            }

            ans.push_back(temp);
            temp = "";
            i = j;
        }
        return ans;
    }
};


int main(){

    return 0;
}
