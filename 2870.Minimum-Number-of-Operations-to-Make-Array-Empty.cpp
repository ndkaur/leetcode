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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int cnt =0;
        for(auto itr:mp){
            if(itr.second%3==0){
                cnt += itr.second/3;
                mp.erase(itr.first);
            }
            else{
                int times = itr.second;
                if(times ==1)
                    return -1;
                if(times%3==1){
                    cnt+= itr.second/3 +1;
                }
                else if(times%3==2){
                    cnt += itr.second/3 +1;
                }
                mp.erase(itr.first);
            }
        }
        if(mp.size()!=0)
            return -1;
        return cnt;
    }
};


int main(){

    return 0;
}