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
    int minAbsoluteDifference(vector<int>& nums) {
        int  n= nums.size();
        vector<int> one,two;
        for(int i=0; i<n; i++){
            if(nums[i]==1)
                one.push_back(i);
            else if(nums[i]==2)
                two.push_back(i);
        }
        if(one.size()==0 || two.size()==0)
            return -1;
        int mn =INT_MAX;
        

        for(int i=0; i<one.size(); i++){
            for(int j=0; j<two.size(); j++){
                int dif = abs(one[i]-two[j]);
                mn = min(mn, dif);
            }
        }
        return mn;
    }
};


int main(){

    return 0;
}