/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
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

int main(){

    return 0;
}
// @lc code=start

// Time complexity: O(s1.size()*s2.size())
// Space complexity: O(s1.size() + s2.size())

class Solution {
public:
    string multiply(string s1, string s2) {
       
        if(s1=="0" || s2=="0")
            return "0";
        
        string num1 = "";
        string num2 = "";

        if(s1[0]=='-') {//-ve num 
            num1 = "-"; 
            // seperate the -ve sign 
            s1 = s1.substr(1);
        }
        if(s2[0]=='-'){
            num2="-";
            s2 = s2.substr(1);
        }
        // if both -ve then the ans is +ve
        if(num1=="-" && num2=="-")
            num1= num2 = ""; 

        int n = s1.size();
        int m = s2.size();
        string res(n+m,'0');

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                // res storing carry
                int num = (s1[i]-'0') * (s2[j]-'0') + (res[i+j+1]-'0');
                res[i+j+1] = num%10 +'0'; // updating the value of carry
                res[i+j] += num/10; // actual num 
            }
        }

        int i=0;
        while(i<res.size() && res[i]=='0'){
            i++;
        }
        // adding the -ve signs if present
        return num1+num2 + res.substr(i);
    }
};
// @lc code=end

