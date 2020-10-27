/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
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
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n= distance.size();
        int sum=0;
        int back=0;
        if(start>destination)
            swap(start,destination);
        for(auto i=0;i<n;i++){
            if(i>=start && i<destination)
                sum+= distance[i];
            else 
                back+= distance[i];
        }
        int ans =min(sum,back);
        return ans;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> distance ={3,6,7,2,9,10,7,16,11};
    int start=6;
    int destination=2;
    int ans=sol.distanceBetweenBusStops(distance,start,destination);
    cout<<ans;
    return 0;
}