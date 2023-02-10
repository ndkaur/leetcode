/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
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
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        int ans =0;
        while(j<n){
            mp[fruits[j]]++;
            if(st.size() <= 2){
                ans = max(ans, j-i+1);
            }
            else{
                mp[fruits[i]]--;
                if(mp[fruits] == 0)
                    mp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
}; 

// @lc code=end


int main(){

    return 0;
}