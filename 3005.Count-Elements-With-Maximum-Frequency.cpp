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
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            mx = max(mx, mp[nums[i]]);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(mp[nums[i]]==mx)
                cnt++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}