/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
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
class RandomizedSet {
public:
    unordered_map<int,int> mp;//val, idx
    vector<int> arr;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            arr.push_back(val);
            // idx of the val will be the size of array 
            mp[val] = arr.size()-1;
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        else{ // mp = idx ->val
            int idx = mp[val];
            int lastVal = arr.back();
            // swap the val to be removed to the last of array 
            arr[idx] = lastVal; // delting from array by replacing the idxval to the last val
            arr.pop_back(); // now removing the original occurence of last val from the end
            mp[lastVal] = idx; // now changing the idx of last val in map also 
            mp.erase(val); // removing the val from map
            return true;
        }
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end




class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)!=st.end())
            return false;
        else{
            st.insert(val);
            return true;
        }
    }
    
    bool remove(int val) { 
        if(st.find(val)==st.end())
            return false;
        else{
            st.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        // return arr[rand()%arr.size()];
        int pos = rand()%st.size();
        return *next(st.begin(), pos);
    }
};



int main(){

    return 0;
}