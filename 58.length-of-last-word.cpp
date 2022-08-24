/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
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

// doesnot work for some cases like "a "
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int len = s.size();
//         if(len==1)
//             return len;
//         reverse(s.begin(), s.end());
//         int cnt=0;
//         for(int i=0; i<len; i++){
//             while(s[i]!=' '){
//                 cnt++;
//                 i++;
//             }
//             if(cnt>0)
//                 break;
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int cnt=0;
        for(int i=len-1; i>=0; i--){
            if(s[i] == ' ' && cnt>0)
                return cnt;
            if(s[i]!=' ')
                cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int i=len-1;
        int cnt=0;
        while(i>=0 && s[i]==' ')
            i--;
        while(i>=0 && s[i]!=' '){
            cnt++;
            i--;
        }
        return cnt;
    }
};
// @lc code=end


int main(){

    return 0;
}