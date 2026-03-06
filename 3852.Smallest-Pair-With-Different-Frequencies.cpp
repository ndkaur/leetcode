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
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        
        vector<pair<int,int>> temp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto itr:mp){
            temp.push_back({itr.first, itr.second});
        }
            
        sort(temp.begin(), temp.end());

        // for(auto i:temp){
        //     cout<<i.first<<" "<<i.second;
        // }
        for(int i=0; i<temp.size(); i++){
            int one_val = temp[i].first;
            int one_freq = temp[i].second;

            for(int j=i+1; j<temp.size(); j++){
                int second_val = temp[j].first;
                int second_freq = temp[j].second;

                if(second_freq!=one_freq){
                    return {one_val, second_val};
                }
            }
        }
        return {-1,-1};
    }
};


int main(){

    return 0;
}