/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
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

// 1 1 1 1 2 2 2 2 2 2
// this case will fail if we use a map and make partition according to the count of all the number
// cause 1-> 4 time  , 2->6 time so it will return false 
// but we can make partitions on bacis of groups of 2 {1,1} {1,1} {2,2} {2,2} {2,2} 
// so for that purpose we need to find gcd 


class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n=deck.size();
        map<int,int> freq;
        for(int i=0;i<n;i++)
            freq[deck[i]]++;
        vector<int> extra;

        for(auto itr : freq)
            extra.push_back(itr.second);
        // find the gcd of count of numbers so to divode the highest no of count into pair
        int gc=extra[0];
        for(auto x:extra)
            gc=__gcd(gc,x);
        
        if(gc==1)
            return false;
        
        return true;
    }
};

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()==1)
            return false;
        unordered_map<int,int> mp;
        for(int i:deck)
            mp[i]++;
        int mx=0;
        for(auto it:mp){
            mx= __gcd(it.second,mx);
        }
        return mx>=2;
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> deck={1};
    bool out=sol.hasGroupsSizeX(deck);
    cout<<out;
    return 0;
}