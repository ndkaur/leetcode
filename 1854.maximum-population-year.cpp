/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
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

// kind of prefix sum 
//  give 1 to enter year and -1 to exit year 
// then find the sum and increase the cnt 
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> arr(101,0);
        for(vector<int> log:logs){
            arr[log[0]-1950]++;
            arr[log[1]-1950]--;
        }
        int max=0; 
        int cnt=0;
        int year;
        for(int i=0;i<101;i++){
            cnt+= arr[i];
            if(cnt>max){
                max= cnt;
                year=i;
            }
        }
        return year+1950;
    }
};

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n= logs.size();
        unordered_map<int,int> mp;
        // year, cnt 
        for(int i=0;i<n;i++){
            for(int k=logs[i][0]; k!=logs[i][1];k++){
                mp[k]++;
            }
        }
        int cnt=0;
        int year=0;
        //  the yaer whose cnt is more than 1 means is repeated in more than two sub arrays 
        for(auto it:mp){
            if(it.second>cnt){
                cnt= it.second;
                year= it.first;
            }
            if(it.second==cnt){
                year= min(year, it.first);
            }
        }
        return year;
    }
};
// @lc code=end




int main(){
    Solution sol;
    // vector<vector<int>> logs={{1993,1999},{2000,2010}};
    vector<vector<int>> logs={{1950,1961},{1960,1971},{1970,1981}};
    int ans= sol.maximumPopulation(logs);
    cout<<ans;
    return 0;
}