/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
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
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string>v(numRows, "");
        // dir is controling the movement of j 
        //  and j is controling at which vector string index we gonna add the curr char 
        int j = 0, dir = -1;

        for(int i=0; i<s.length(); i++){
            // when j reaches 0 or numRow-1 then change direction 
            if(j == numRows - 1 || j == 0) 
                dir *= (-1); 
            // keep adding chars to different indexed strings
		    v[j] += s[i];

            if(dir == 1)  // dir if +ve move j ahead 
                j++;
            else  // dir is -ve move j behind 
                j--;
        }

        string res;
        for(auto &it : v){
            res += it; 
        } 
        return res;
    }
};


// @lc code=end


int main(){

    return 0;
}