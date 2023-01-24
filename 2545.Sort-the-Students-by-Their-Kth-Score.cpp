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
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();
        priority_queue<pair<int,int>> pq; // col val, i
        for(int i=0; i<n; i++){
            pq.push({score[i][k], i});
        }
        vector<vector<int>> ans;
        while(pq.size()){
            int row = pq.top().second;
            pq.pop();
            ans.push_back(score[row]);
        }
        return ans;
    }
};

// quick sort ->O(nlogn)
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        sort(score.begin(), score.end(), [&](const auto &s1 , const auto &s2){
            return s1[k] > s2[k];
        });
        return score;
    }
};


int main(){

    return 0;
}