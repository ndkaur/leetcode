/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
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
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto itr:mp){
            if(st.find(itr.second)==st.end()){
                st.insert(itr.second);
            }
            else 
                return false;
        }
        return true;
    }
};


class Solution1 {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> temp;
        for(int i=0; i<n; i++){
            int cnt=1;
            while(i+1<n && arr[i]==arr[i+1]){
                cnt++;
                i++;
            }
            temp.push_back(cnt);
        }
        sort(temp.begin(), temp.end());

        for(int i=1; i<temp.size(); i++){
            if(temp[i]==temp[i-1])
                return false;
        }
        return true;
    }
};


// @lc code=end


int main(){

    return 0;
}