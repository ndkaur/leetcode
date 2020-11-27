/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>count;
        for(auto employee : employees) count[employee->id] = employee;
        int sum=0;
        queue<Employee*> q;
        q.push(count[id]);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(auto employee : p->subordinates)
                q.push(count[employee]);
            sum+= p->importance;
        }
        return sum;
    }
};
  
// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    }
    return 0;
}