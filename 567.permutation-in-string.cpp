/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
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
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> freq1(26,0);
        for(auto c:s1){
            freq[c-'a']++;
        }
        vector<int> freq2(26,0);
        int i=0; 
        int j=0;

        while(j<m){
            freq2[s2[j]-'a']++;
            // if size of the window equals to the s1
            if(j-i+1 == n){
                if(checkEqual(freq1,freq2))
                    return true;
            }
            // if window size is still smaller than s1
            if(j-i+1 < n){
                j++;
            }
            else{ // if window size greter than s1 so reduce the size of window 
                // change the pos of i
                freq2[s2[i]-'a']--; 
                i++;
                j++;
            }
        }
        return false;
    }
    bool checkEqual(vector<int>&a , vector<int>& b){
        for(int i=0; i<26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};
// @lc code=end


int main(){
    return 0;
}