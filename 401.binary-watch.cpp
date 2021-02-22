/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
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
    vector<int> hour={1,2,4,8};
    vector<int> minute={1,2,4,8,16,32};
public:
    vector<string> readBinaryWatch(int num) {
       vector<string> res;
       helper(res,make_pair(0,0),num,0);
       return res;
    }
    void helper(vector<string>&res,pair<int,int> time,int num, int start_point){
        if(num==0){
            res.push_back(to_string(time.first)+(time.second<10 ? ":0" : ":")+ to_string(time.second));
            return;
        }
        for(int i=start_point;i<hour.size()+minute.size();i++){
            if(i<hour.size()){
                time.first += hour[i];
                if(time.first<12)
                    helper(res,time,num-1,i+1);
                time.first -= hour[i];
            }
            else{
                time.second += minute[i-hour.size()];
                if(time.second<60) 
                    helper(res,time,num-1,i+1);
                time.second -= minute[i-hour.size()];
            }
        }
    }
};
// @lc code=end


int main(){
    Solution sol;
    int num=2;
    vector<string> ans =sol.readBinaryWatch(num);
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}