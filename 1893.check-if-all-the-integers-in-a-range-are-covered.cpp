/*
 * @lc app=leetcode id=1893 lang=cpp
 *
 * [1893] Check if All the Integers in a Range Are Covered
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> temp(51,0);
        for(int i=0;i<ranges.size();i++){
            for(int j=ranges[i][0]; j<=ranges[i][1];j++){
                temp[j]=1;
            }
        }
        for(int i=left; i<=right;i++){
            if(temp[i]!=1)
                return false;
        }
        return true;
    }
};


// line sweep 
class Solution { //Time: O(n + m), where m is the number of ranges.
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();
        vector<int> arr(52,0);
        for(auto range:ranges){
            arr[range[0]]++;
            arr[range[1]+1]--; // iclusive 
        }
        int overlap = 0;
        for(int i=1; i<=right; i++){
            overlap += arr[i];
            if(i>=left && overlap==0){
                return false;
            }
        }
        return true;
    }
};

// @lc code=end


int main(){

    return 0;
}