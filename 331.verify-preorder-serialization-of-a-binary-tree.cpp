/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */
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

// @lc code=start

// 9 3 4 # # 1 # # 2 # 6 # #
//   9    9 3 3 4 4 # # 1 1 # # 2 2 # 6 6 # #
// n= 1 0 2 1 3 2 4 3 2 1 3 2 1 0 2 1 0 2 1 0

class Solution { //t-> O(n)  s->O(1)
public:
    bool isValidSerialization(string preorder) {
        //  use concept of getline 
        stringstream ss(preorder);
        string curr;
        int node=1;
        while(getline(ss, curr,',')){
            node--;
            if(node<0) return false;
            if(curr!="#") 
                node+=2;
        }
        return node==0; // if proper tree then node==0
    }
};


// for bt -> null count== node count+1
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nodeCnt=0;
        int nullCnt=0;
        vector<string> v= split(preorder,',');
        for(int i=0;i<v.size();i++){
            if(v[i]=="#") nullCnt++;
            else  nodeCnt++;
            if(nullCnt >= nodeCnt+1 && i!=v.size()-1) // out split string i hasnt reached end and still nullcnt > nodecnt
                return false;
        }
        return nullCnt== nodeCnt+1;
    }
    vector<string> split(string pre, char delim){
        vector<string> ans;
        while(!pre.empty()){
            int idx= pre.find_first_of(delim);
            if(idx==-1){
                ans.push_back(pre);
                pre.clear();
            }
            else{
                ans.push_back(pre.substr(0,idx));
                pre = pre.substr(idx+1, pre.size()-idx-1);
            }
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}