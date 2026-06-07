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


class Solution {
public:
    int cal(vector<pair<int,int>>& first, vector<pair<int,int>>& second){
        // we want the min sum from first 
        int early = INT_MAX;
        for(int i=0; i<first.size(); i++){
            early = min(early, first[i].first+first[i].second);
        }

        int ans = INT_MAX;
        // check with evry pair 
        // duration = max(early, second_start)
        for(int i=0; i<second.size(); i++){
            int start = max(early, second[i].first);
            int finish = start+ second[i].second;
            ans = min(ans, finish);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>> land, water;
        for(int i=0; i<landStartTime.size(); i++){
            land.push_back({landStartTime[i], landDuration[i]});
        }

        for(int i=0; i<waterStartTime.size(); i++){
            water.push_back({waterStartTime[i],waterDuration[i]});
        }

        int land_first = cal(land, water);
        int water_first = cal(water, land);
        return min(land_first, water_first);
    }
};



int main(){

    return 0;
}