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


class Solution0 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;
        for(int num:nums){
            if(num<0)
                neg.push_back(num);
            else if(num>0)   
                pos.push_back(num);
        }
        vector<int> ans;
        for(int i=0; i<neg.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int pos =0;
        int neg =1;
        for(auto num:nums){
            if(num>0){
                ans[pos] = num;
                pos+=2;
            }
            else if(num<0){
                ans[neg] = num;
                neg+= 2;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}