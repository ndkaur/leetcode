/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
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
    double average(vector<int>& salary) {
        int n = salary.size();
        sort(salary.begin(), salary.end());
        
        double sum =0;

        for(int i=1; i<n-1; i++){
            sum += salary[i];
        }
        sum = sum/(n-2);
        return sum;
    }
};

// @lc code=end


int main(){

    return 0;
}