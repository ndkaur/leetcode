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

// time -> O(N + klogN)
// space ->O(N)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<vector<int>> left; 
        int i =0;
        // we have to take only left side of start index including startidx
        for(; i<n && fruits[i][0]<=startPos; i++){
            // {distance from  start, fruits at that idx}
            left.push_back({startPos - fruits[i][0], fruits[i][1]});
        }
        // idx  idx startPos idx idx
        reverse(left.begin(), left.end());

        vector<vector<int>> right;
        for(; i<n; i++){
            right.push_back({fruits[i][0]-startPos, fruits[i][1]});
        }


        // now making the left and right prefix sum arrays 
        vector<int> pleft(left.size()+1);
        for(int j=0; j<(int)left.size(); j++){
            pleft[j+1] = pleft[j]+left[j][1];
        }
        vector<int> pright(right.size()+1);
        for(int j=0; j<right.size(); j++){
            pright[j+1] = pright[j]+right[j][1];
        }


        // finding ub 
        auto count = [&](const vector<vector<int>>& a, int steps){
            // it is vvi so stl ub will not work , we want idx so -a.begin  , ub of the distance index in the vvi array 
            return upper_bound(
                a.begin(), a.end(), steps, [](int target,const  vector<int>& v){
                    return target<v[0];
                }
            )-a.begin();
        };

        // going left then right and right then left , and taking there max
        int mx = 0;
        for(int i=0; i<=k; i++){
            // start->left->back(right)
            int ub_left = count(left, i);
            int ub_right = count(right, k-2*i);
            mx = max(mx, pleft[ub_left]+pright[ub_right]);
            
            // start->right->back(left)
            ub_right = count(right, i);
            ub_left = count(left, k-2*i);
            mx = max(mx, pright[ub_right]+pleft[ub_left]);
        }
        return mx;
    }
};

// so the process is either we go right , or go left, or go left->right and right->left
// when we traveled from strat to left then coming back will take total-2*i steps moved toward left . 
// idea is to make a vvarray where we store the {distance for each index from start ponint, fruit present at that index} 
// we make such array fro left side distance and right side distance 
// then we also make prefix sum array for both left and s=right side array 

// then we start with each step till steps<=k 
// and for each step we find max of (go left->go right, goright->goleft)

// for finfing that paticular value of fruits at that index we use uper bound and find that ub index and for that index we take the prefix sum till that 

int main(){

    return 0;
}