/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
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
    static bool comp(vector<int>&a, vector<int>& b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n= boxTypes.size();
        int ans=0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        for(int i=0;i<n;i++){
                int boxno= boxTypes[i][0];
                int contain = boxTypes[i][1];
                int x= min(boxno,truckSize);
                ans+= x * contain;
                truckSize= truckSize-x;
                if(!truckSize)
                    break;
        }
        return ans;
    } 
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> box={{5,10},{2,5},{4,7},{3,9}};
    int size=10;
    int ans= sol.maximumUnits(box,size);
    cout<<ans;
    return 0;
}