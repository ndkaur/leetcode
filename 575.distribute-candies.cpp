/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


// @lc code=start

class Solution0 {
public:
    int distributeCandies(vector<int>& candyType) {
        int n= candyType.size();
        int can_eat = n/2;
        int unique =0;
        for(int i=0;i<n;i++){
            bool uniqueCheck =true;
            for(int j=0;j<i;j++){
                if(candyType[i]==candyType[j]){
                    uniqueCheck =false;
                    break;
                }
            }
            if(uniqueCheck)
                unique++;
        }
        return min(unique,can_eat);
    } // O(n^2)
};

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n= candyType.size();
        int can_eat = n/2;
        int unique=1;
        sort(candyType.begin(),candyType.end());
        for(int i=1;i<n ;i++){
            if(candyType[i]!=candyType[i-1])
                unique++;
        }
        return min(unique , can_eat);
    }  // O(n)
};   

// @lc code=end


int main(){
    Solution sol;
    vector<int> candyType ={6,6,1,1,2,2};
    int n=sol.distributeCandies(candyType);
    cout<<n;
    return 0;
}