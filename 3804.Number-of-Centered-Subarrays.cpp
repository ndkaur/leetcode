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
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        int cnt= 0;
        for(int i=0; i<n; i++){
            map<int,int> mp;
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                mp[nums[j]]++;
                if(mp.count(sum)>0)
                    cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}