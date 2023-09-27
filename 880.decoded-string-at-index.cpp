/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
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
    string decodeAtIndex(string s, int k) {
        int n = s.size();
        long long len = 0;
        // finding the total len that will be after mutliplying all nums 
        for(auto ch:s){
            if(isdigit(ch)){
                int repeat = ch-'0';
                len = len*repeat;
            }
            else 
                len++;
        }
        // now finding the kth char in the whole word
        for(int i=n-1; i>=0; i--){
            // now start from behind 
            char ch = s[i];
            if(isdigit(ch)){
                // if its a digit simply reduce the len and move ahead 
                // balance the values of k cause if sometimes the len can get less than k
                // len = 9 and k =10 then k%len = 10%9 = 1
                int repeat = ch -'0';
                len = len/repeat; 
                k = k%len;
            }
            else {// if its a alphabet then keep on reducing the len 
                if(k==0 || k==len)
                    return string(1,ch);
                len--;
            }
        }
        return  "";
    }
};
// @lc code=end


int main(){

    return 0;
}