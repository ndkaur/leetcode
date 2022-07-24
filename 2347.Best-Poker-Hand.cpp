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
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char, int> ms;
        map<int,int> mr;
        for(auto s:suits){
            ms[s]++;
        }
        for(auto r:ranks){
            mr[r]++;
        }
        string ans="High Card";
        for(auto it:ms){
            if(it.second==5){
                ans= "Flush";
                break;
            }
        }
        for(auto it:mr){
            if(it.second>=3){
                ans= "Three of a Kind";
                break;
            }
            else if(it.second==2){
                ans="Pair";
                break;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}