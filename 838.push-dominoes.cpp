/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n= dominoes.size();
        vector<int> forces(n);
        int force=0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R')
                force = n;
            else if(dominoes[i] =='L')
                force=0;
            else 
                force=max(force-1,0);
            forces[i] += force;
        }

        force=0;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i] == 'L')
                force= n;
            else if(dominoes[i]== 'R')
                force=0;
            else 
                force=max(force-1,0 );
            forces[i] -= force;
        }
        string ans="";
        for(int f:forces){
            if(f>0) ans += 'R';
            else if(f<0) ans+='L';
            else ans+= '.';          
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string dominoes = ".L.R...LR..L..";
    string ans =sol.pushDominoes(dominoes);
    for(auto c:ans)
        cout<<c;
    return 0;
}