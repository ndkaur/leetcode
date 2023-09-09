/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */
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

// @lc code=start

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int i =0;
        int j =0;

        int happy = 0;
        int angry =0;

        int mx =0;

        while(j<n){
            if(grumpy[j]==0) // happy 
                happy += customers[j];
            if(grumpy[j]==1) // angry 
                angry += customers[j];
            
            // now mintues reached
            // we can keep the angry as happy for only given minutes
            if(j-i+1==minutes){
                mx = max(mx, angry);
                if(grumpy[i]==1)
                    angry -= customers[i];
                i++;
            }
            j++;
        }
        // final ans will be the happy customers and the non grumy left after mintues swap
        return happy + mx;
    }
};

// @lc code=end


int main(){

    return 0;
}