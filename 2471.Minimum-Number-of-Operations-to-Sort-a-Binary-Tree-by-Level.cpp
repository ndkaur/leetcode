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
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        int cnt =0;
        vector<vector<int>> levels;
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz= q.size();
            vector<int> temp;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            levels.push_back(temp);
        }

        for(auto level:levels){
            cnt += srt(level);
        }
        return cnt;
    }
    int srt(vector<int>& level){
        int n= level.size();
        int cnt =0;
        map<int,int> mp;
        vector<int> temp;
        for(int i=0; i<n; i++){
            temp.push_back(level[i]);
            mp[level[i]] = i;
        }
        sort(temp.begin(), temp.end());
        for(int i=0; i<n; i++){
            if(temp[i] != level[i]){
                int pos = mp[temp[i]];
                // swaping the value according to sorted array 
                swap(level[i], level[pos]);
                // now map is always made according to level array 
                // so swap the values in map also 
                swap(mp[level[pos]], mp[level[i]]);
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}