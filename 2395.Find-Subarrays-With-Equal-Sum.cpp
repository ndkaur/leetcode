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
    bool findSubarrays(vector<int>& nums) {
        int n= nums.size();
        int cnt=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[j]+nums[j+1] == nums[i]+nums[i+1])
                    cnt++;
            }
        }
        return cnt>=1;
    }
};

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n= nums.size();
        map<int,int> mp;

        for(int i=1; i<n; i++){
           int sum = nums[i-1]+nums[i];
            mp[sum]++;
            if(mp[sum]>1)
                return true;
        }
        return false;
    }
};

int main(){

    return 0;
}