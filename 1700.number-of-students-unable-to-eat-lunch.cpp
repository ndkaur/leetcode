/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int cnt=0; // no of time the student is send back of the q , if equal then not posiible to eat sandwitch 
        int i=0;
        //  if size check when student is 1 1 1 and sandwitch is 0 1 1 
        //  infit loop of push pop will begin in queue so check size if equal to cnt means rotation if not begin
        while(q.size() && cnt<q.size()){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                cnt=0;
            }else{
                int temp= q.front();
                q.pop();
                q.push(temp);
                cnt++;
            }
        }
        return q.size();
    }
};
// @lc code=end



int main(){

    return 0;
}