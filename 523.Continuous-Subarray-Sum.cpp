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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2)
            return false;
        unordered_map<int,int> mp;
        mp[0]=-1;

        int sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(k!=0)
                sum = sum%k;
            if(mp.find(sum)!=mp.end()){// found
                if(i-mp[sum]>1) // check if length greater than or equal to 2 
                    return true;
            }
            else 
                mp[sum] = i;
        }
        return false;
    }
};

// sum =23 23%6 = 5 , 7 7%6 , 1 ,5%6 = 5 exist i=2-0 =2
// mp[5] = 0  
// mp[1] = 1

int main(){

    return 0;
}