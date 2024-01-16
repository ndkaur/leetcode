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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int, int> mp; // we only want track of matches lost 

        for(auto match:matches){
            // check if no count in map then mark as 0 
            if(!mp.count(match[0]))
                mp[match[0]] = 0;
            mp[match[1]]++;

        }

        vector<int> one;
        vector<int> two;
        // 0 = that never lost 
        // 1 = lost 1 time  
        for(auto itr:mp){
            if(itr.second==0)
                one.push_back(itr.first);
            else if(itr.second==1)
                two.push_back(itr.first);
        }

        return {one,two};
    }
};

// 1 ->  0
// 2 -> 0
// 3 -> 2
// 4 -> 1
// 5 -> 1
// 6 ->  2
// 7 ->  1
// 8 ->  1
// 9 ->  2
// 10 -> 0

int main(){

    return 0;
}