/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
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
    bool halvesAreAlike(string s) {
        int n = s.size();
        set<char> st={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int cnt = 0;
        int mid = n/2;
        for(int i=0; i<mid; i++){
            char one = s[i];
            char two = s[mid+i];
            if(st.find(one)!=st.end())
                cnt++;
            if(st.find(two)!=st.end())
                cnt--;
        }
        return cnt==0;
    }
};

// @lc code=end


int main(){

    return 0;
}