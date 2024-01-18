/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
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

class Solution { //time-> O(3^n) ,  space-> O(n^3)
public:
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        vector<string> ans;
    //backtrack(idx, path, sum till now, prev sum, num, target)
    // prev sum required in case of passing the multiply case 
        // string path ="";
        backtrack(0,"", 0, 0, num, target, ans);
        return ans;
    }

    void backtrack(int idx, const string& path, long sumSoFar, long prevSum, string num, int target, vector<string>& ans){
        int n = num.size();
        // base case
        if(idx==n){
            if(sumSoFar==target){
                ans.push_back(path);
            }
            return;
        }

        string numStr;
        long val = 0;

        for(int i=idx; i<n; i++){
            if(i>idx && num[idx]=='0')
                break;

            numStr += num[i];// string format 
            val = val*10 + num[i]-'0'; // making it actual val in int , actual value int format 

            if(idx==0){ // starting first val 
                backtrack(i+1, path+numStr, val, val, num, target, ans);
            }
            else{
                backtrack(i+1, path+"+"+numStr, sumSoFar + val, +val, num, target, ans);
                backtrack(i+1, path+"-"+numStr, sumSoFar-val, -val, num, target, ans);
                backtrack(i+1, path+"*"+numStr, sumSoFar-prevSum+prevSum*val, prevSum*val, num, target, ans);
            }
        }
    }
};

// in case of multiply it has high precendence then all 
// 7+3*2 ,  10*2 = 20  which is wrong
// but if we use the prev sum  
// 7+3 = 10  , so 10-3+3*2 = 7+6 = 13  -> we are adding 3*2 = prevVal * curr val = next passing on prev val
//  

// eg :- 1+2*3 -> 1+2 = 3  
// 3-2+2*3 = 1+6 = 7 , now to make 7 we added 6 so prev num = 6 


// @lc code=end


int main(){

    return 0;
}