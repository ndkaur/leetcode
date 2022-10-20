/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
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

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000


class Solution {
public:
    string intToRoman(int num) {
        vector<int> numbers[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman[13] ={"M","CM" ,"D", "CD","C" ,"XC", "L" ,"XL" ,"X", "IX","V","IV","I"};
        string ans;
        for(int i=0; i<13; i++){
            while(num >= numbers[i]){
                ans.append(roman[i]);
                num = num - numbers[i];
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}