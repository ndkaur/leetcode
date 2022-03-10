/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
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
class Solution0 {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(auto p:paths) 
            s.insert(p[0]);
        for(auto p:paths){
            if(!s.count(p[1]))
                return p[1];
        }
        return "";
    }
};

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;
        for(auto p:paths){
            mp[p[0]]+= 1;
            mp[p[1]]+=0;
        }
        for(auto [city,dest]:mp){
            if(dest==0)
                return city;
        }
        return "";
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<string>> paths={{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    string ans= sol.destCity(paths);
    for(auto c:ans)
        cout<<c;
    return 0;
}