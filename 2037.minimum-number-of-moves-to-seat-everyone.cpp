/*
 * @lc app=leetcode id=2037 lang=cpp
 *
 * [2037] Minimum Number of Moves to Seat Everyone
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
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int m = students.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans=0;
        for(int i=0; i<n; i++){
            ans += abs(seats[i]-students[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int s= seats.size();
        int n= students.size();
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        // 1 4 5 9    // 1 2 3 6
        int count=0;
        int i=0;
        for(int j=0;j<n;j++){
            if(seats[i]==students[j]){
                i++;
            }
            else{
                count += abs(seats[i]-students[j]);
                i++;
            }   
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> seats={2,2,6,6};
    vector<int> students={1,3,2,6};
    int ans = sol.minMovesToSeat(seats,students);
    cout<<ans;
    return 0;
}