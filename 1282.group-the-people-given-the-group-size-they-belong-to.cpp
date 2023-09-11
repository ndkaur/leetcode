/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
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
    vector<vector<int>> groupThePeople(vector<int>& group) {
        int n = group.size();
        map<int,vector<int>> mp;
        // mp->number -> indexes of occurence in array 
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
           mp[group[i]].push_back(i);
           if(mp[group[i]].size()==group[i]){
               //ans stores the indexes of the same numbers
               // add the whole array formed for that number in ans[i]
               ans.push_back(mp[group[i]]);
               mp[group[i]].clear(); // claer mp[arr] for next occurence of number if exist
           }
       }
       return ans;
    }
};

//  0 1 2 3 4 5 6
// [3,3,3,3,3,1,3]
//  mp[3] ={0,1,2} now num= 3 arr size =3 so add to ans
//  ans = {{0,1,2}}
// mp[3] = { empty} 
// // i=3 mp[3] = {3,4,}
// i=5 mp[1]= {5}  so size equal of arr to num 
// ans = { {0,1,2}, {5}}
//  i=6  mp[3] = {3,4,6}
// ans = { {0,1,2} , {5} , {3,4,6} }

// @lc code=end


int main(){

    return 0;
}