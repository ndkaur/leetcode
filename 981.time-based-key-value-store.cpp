/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
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
class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp; // (key,{val, time})
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))
            return "";

        string res="";

        auto& v= mp[key]; // vector<pair< >>

        int l=0;
        int r= (int)v.size()-1;

        while(l <= r){
            int mid = l+(r-l)/2;
            // time of mid < target
            if(v[mid].second <= timestamp){
                res= v[mid].first;
                l= mid+1;
            }
            else 
                r= mid-1;
        }
        return res;
    }
};

// foo ->{bar,1} {bar2,4}


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end


int main(){

    return 0;
}