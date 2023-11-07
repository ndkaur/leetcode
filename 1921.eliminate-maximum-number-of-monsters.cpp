/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        //  speed = dist/time
        //  time = dist/speed
        // time of monster calculate
        int n = speed.size();
        vector<double> time;
        for(int i=0; i<n; i++){
            time.push_back((double)dist[i]/(double)speed[i]);
        }
        sort(time.begin(), time.end()); // min of all times in the begining .. so the first monster arriving will take min time of all 

        int t = 0; // time on our clock 
        int ans = 0;
        for(auto monster_time:time){
            // our clock time is more, ie the time to recharge the sword so 
            // if time required to charge back sword is more and the monster time is less 
            // the monster will arive early so we fail
            if(monster_time<=t){
                break;
            }
            else{
                ans++;
                t++;
            }
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}