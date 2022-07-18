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
    int maximumSum(vector<int>& nums) {
        int n= nums.size();
        
        //  map is like idx is sum  and key is the nums 
        // 4->13
        // 7-> 7, 43 
        // 9-> 18, 36
        unordered_map<int,vector<int>> mp;

        sort(nums.begin(),nums.end());
        for(auto i:nums){
            string s1= to_string(i);
            int sum=0;
            for(auto ch:s1)
                sum+= (ch-'0');
            mp[sum].push_back(i);
        }
        int mx=INT_MIN;
        for(auto itr:mp){
            int n= itr.second.size(); // vector<int> of nums
            if(n>=2){
                //  more than 2 values in array so the max answ we will get from the last two numbers cause they are the gratest of all
                mx= max(mx, (itr.second[n-1])+ (itr.second[n-2]));
            }
        }
        return mx==INT_MIN ? -1 : mx;
    }
};

int main(){

    return 0;
}