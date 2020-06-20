/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len =seats.size();
        int zcount=0;
        int ans=0;
        for(int i=0;i<len;i++){ //{1,0,0,0,1,0,1}
            if(seats[i]==1)
               zcount =0;
            else{
                zcount++;
                ans=max(ans,(zcount+1)/2);
            }
        }

        for(int i=0;i<len;i++){ //{0,0,0,1}
            if(seats[i]==1){
                ans=max(ans,i);
                break;
            }
        }
        for(int i=len-1;i>=0;i--){ //{1,0,0,0}
            if(seats[i]==1){
                ans=max(ans,len-1-i);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> seats={1,0,1,1};
    int ans=sol.maxDistToClosest(seats);
    cout<<ans;
    return 0;
}