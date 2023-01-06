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
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        map<int,int> mp;
        for(int i: tasks){
            mp[i]++;
        }
        int cnt = 0;
        for(auto itr: mp){
            if(itr.second == 1)
                return -1;
            if(itr.second % 3 == 0 ){
                cnt += itr.second/3;
            }
            else{
                cnt += itr.second/3 +1;
            }
        }
        return cnt;
    }
}; 


int main(){

    return 0;
}