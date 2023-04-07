/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
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
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int cnt = 0;
        int i = 0;
        int j = n-1;
        // 1 2 2 3  l=3
        // 3 3 4 5  l=5
        
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }
            else{
               j--;
            }
            cnt++;
        }
        
        return cnt;
    }
};
// @lc code=end


int main(){

    return 0;
}