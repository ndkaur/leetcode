/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
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
    int myAtoi(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        
        int i =0;
        long ans = 0;
        int sign = 1;

        while(i<n && s[i]==' '){ // blank spaces
            i++;
        }
        // handling -ve sign
        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        
        while(i<n){
            // checking it is a number 
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                ans = ans*10 + (s[i]-'0');

                if(ans>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(ans>INT_MAX && sign==1)
                    return INT_MAX;
                    
                i++;
            }
            else 
                return ans*sign;
        }
        return (ans*sign);
    }
};



// @lc code=end


int main(){

    return 0;
}