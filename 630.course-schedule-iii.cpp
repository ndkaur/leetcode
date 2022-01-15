/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start


class Solution0 {  // time limit exceeded
public:
    vector<vector<int>> dp;
    static bool compare(vector<int> &a, vector<int> &b){
        return (a[1]==b[1]) ? (a[0]<b[0]) : (a[1]<b[1]);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n= courses.size();
        int sum=0;
        sort(courses.begin(),courses.end(),compare);
        dp.resize(n+1,vector<int>(10005,0));
        return schedule(courses,0,0);
        return 0;
    }
    int schedule(vector<vector<int>>& courses, int i,int time){
        int n= courses.size();
        if(i==n) return 0;
        if(dp[i][time])
            return dp[i][time];
        int sumNotTaken = schedule(courses,i+1,time);
        int sumTaken=0;
        if(time+courses[i][0]<=courses[i][1])
            sumTaken= 1+schedule(courses,i+1,time+courses[i][0]);
        return dp[i][time]=max(sumTaken,sumNotTaken);
    }
};


class Solution { // priority queue
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n= courses.size();
        sort(courses.begin(),courses.end(),compare);
        int time=0;
        priority_queue<int> pq; //top element greatest of all
        for(int i=0;i<n;i++){
            if(time+courses[i][0]<= courses[i][1]){
                pq.push(courses[i][0]);
                time += courses[i][0];
            }
            else if(!pq.empty() && pq.top()>courses[i][0]){
                // if already greater then just remove it from total time 
                time -= pq.top();
                pq.pop();
                time += courses[i][0];
                pq.push(courses[i][0]);
            }
        }
        return pq.size();
    }
};

// @lc code=end

int main(){
    Solution sol;
    vector<vector<int>> courses={{1,2}};
    int ans = sol.scheduleCourse(courses);
    cout<<ans;
   return 0;
}