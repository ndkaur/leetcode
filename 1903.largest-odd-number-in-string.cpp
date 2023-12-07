/*
 * @lc app=leetcode id=1903 lang=cpp
 *
 * [1903] Largest Odd Number in String
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
    string largestOddNumber(string num) {
        int n= num.size();
        for(int i = n-1; i>=0; i--){
            if(num[i] % 2 == 0)
                num.pop_back();
            else break;
        }
        return num;
    }
};


class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i=n-1; i>=0; i--){
            if((num[i]-'0')%2 !=0){
              return num.substr(0,i+1);
          }
        }
        return "";
    }
};

// 3 5 4 2 7 
// last digit 7 is odd so full number is odd return it 
// eg -> 353427
// full num i odd but if num = 353422
// then we reach till 3 no three is odd it will make remaining number odd
// so ans = substring from starting to that i 

// @lc code=end


int main(){

    return 0;
}