/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
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

// o(n) for map
// log k for pq 
// o(nlogk)

class Solution {
private:
    struct comp {
        bool operator() ( const pair<int,string>& a, const pair<int, string>& b){
        //smaller freq at top // first-> freq   second-> string
        if(a.first != b.first) // no freq equal then go on basis of lexographical
            return a.first > b.first;
        else // freq equal then smaller string will come first 
            return a.second < b.second;
        }       
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string, int> mp;
        for(auto word:words){
            mp[word]++;
        }
        // we want min freq to be on top and in the ans when pq has k size 
        // the one with the max freq must come in the begining of the string ans
        priority_queue<pair<int,string>, vector<pair<int,string>> , comp > pq;
        for(auto itr:mp){
            pq.push({itr.second, itr.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<string> ans;
        while(pq.size()){
            ans.insert(ans.begin() , pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};

// @lc code=end



int main(){

    return 0;
}