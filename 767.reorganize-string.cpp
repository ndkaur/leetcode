/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
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

class Solution { // O(nlogn )
public:
    string reorganizeString(string s) {
        int n = s.size();
        map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        // max heap 
        priority_queue<pair<int,char>> pq; // freq char
        for(auto itr:mp){
            if(itr.second > (n+1)/2)
                return "";
            pq.push({itr.second,itr.first}); // freq, char
        }
        string ans = "";
        while(pq.size()>=2){
            // have to compare the 2 top chars of pq
            int ch1 = pq.top().second;
            int freq1 = pq.top().first;
            ans += ch1;
            pq.pop();
            
            int ch2 = pq.top().second;
            int freq2 = pq.top().first;
            ans += ch2;
            pq.pop();

            if(freq1>1){
                pq.push({freq1 - 1 , ch1});
            }
            if(freq2 > 1){
                pq.push({freq2 - 1, ch2});
            }
        }
        if(pq.size()==1)
            ans += pq.top().second;
        return ans;
    }
};

// eg -> vvvlo  
// mp -> v-3  l-1 o-1
// pq  v-3 l-1 o-1
// pq.size() >=  2 ? yes 
// size check with 2 cause if we have 2 elemts then can simly place them
// ch1 = v-3  l-1  
// ans = vl 
// pq = v-2 o-1
// ans = vl + vo 
// pq = v-1
// ans = vl + vo + v


// @lc code=end


int main(){

    return 0;
}