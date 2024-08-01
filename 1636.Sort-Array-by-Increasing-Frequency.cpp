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
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        // if both freq equal then return decreasing order on basis of elem 
        // if not both equal then increasing order basis of frequency
        return (a.second==b.second) ? a.first>b.first : a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        
        vector<pair<int,int>> freq;
        for(auto itr:mp){
            freq.push_back(itr);
        }
        sort(freq.begin(), freq.end(), cmp);
        for(auto f:freq){
            int cnt = f.second;
            int val = f.first;
            while(cnt--){
                ans.push_back(val);
            }
        }

        return ans;
    }
};

int main(){

    return 0;
}