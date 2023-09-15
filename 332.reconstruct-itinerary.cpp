/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
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
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        // src -> {multiset of adj}
        unordered_map<string,multiset<string>> mp;
        for(int i=0; i<n; i++){
            mp[tickets[i][0]].insert(tickets[i][1]);
        }

        // stack to remove case 2 
        stack<string> stk;
        stk.push("JFK");

        vector<string> ans;

        while(!stk.empty()){
            auto node = stk.top();
            if(mp[node].size()==0){ // no adjacents left
                ans.push_back(node);
                stk.pop();
            }
            else{ // it has adjacents 
                auto adj = mp[node].begin();
                stk.push(*adj);
                mp[node].erase(adj);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// 1st case -> maintain the lexcographicall order
    //so all the adjacents must be sorted we can use map -> multiset 
    // multiset keeps elemts sorted 

//2nd case-> what if the smallest adjacent is the dead end 
    // and it does not have an edge back to source 
    // so wee need to make sure that those edges are travesed first with adj node
    //stack will be used for this 

// stack reverse the order so reverse the answer array 

// eg -> {A,B} , {A,C} ,{C,A}
// A-> B , C 
// B-> A
// C -> A 

// without using stack it order would have been like lexico smaller 
// A -> B -> dead end 
// so we needed stack to push all its adjacents 
// and only when all the adjacents are null then pop from stack 
// stk -> A B A C A 
// ans  = A, C, A, B, A
// ans = reverse = A


// @lc code=end


int main(){

    return 0;
}