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
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;

        int cnt = 0;
        vector<int> pref(n,-1);
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                pref[i]=1;
            }
        }

        int p = 0;
        for(int i=0; i<n; i++){
            p += pref[i];
            for(auto itr:mp){
                if(itr.first<p){
                    cnt+=itr.second;
                }
            }
            mp[p]++;
        }
        return cnt;
    }
};


class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int c=0;
            for(int j=i;j<nums.size();j++){  
                    if(nums[j]==target) c+=1;
                    else c-=1;
                if(c>0) sum++;
            }
        }
        return sum;
    }
};


int main(){

    return 0;
}