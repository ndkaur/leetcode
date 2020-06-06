#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vector<bool> &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len= candies.size();
        vector<bool> out;
        int mx= *max_element(candies.begin(),candies.end());

        for(int i=0;i<len;i++){
            int sum=candies[i]+extraCandies;
            if(sum>=mx){
                out.push_back(true);
            }
            else 
                out.push_back(false);
        }
        return out;
    }
};
int main(){
    Solution sol;
    vi candies={2,3,5,1,3};
    vector<bool> out;
    out = sol.kidsWithCandies(candies,3);
    // int len,i;
    print(out);
    return 0;
}
