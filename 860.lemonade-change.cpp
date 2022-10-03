/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
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
    bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        int five =0;
        int ten =0;
        for(int bill:bills){
            if(bill == 5){
                five++;
            }
            else if(bill == 10){
                // return 5 back 
                if(five == 0) return false;
                five--;
                ten++;
            }
            else { // it is a 20 note 
                // return one ten and 1five 
                if(five > 0 && ten>0){
                    five--; ten--;
                }
                // no ten note present only five -> we need 3 five notes
                else if(five>=3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end


int main(){

    return 0;
}