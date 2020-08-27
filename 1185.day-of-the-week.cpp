/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
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
class Solution {
public:
    const vector<int> days_in_month{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const vector<string> week_day{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    static bool is_leap_year(int y) {return (y%4==0 && y%100!=0) || y%400==0;};
    
    string dayOfTheWeek(int day, int month, int year) {
        int days = 0;
        for(int y = 1971; y < year; ++y) days += is_leap_year(y) ? 366 : 365;
        for(int m = 1; m < month; ++m) days += (m==2 && is_leap_year(year)) ? 29 : days_in_month[m];
        days += day + 4; 
        return week_day[days%7];
    }
};
// @lc code=end

int main(){
    Solution sol;
    int day=29;
    int month=2;
    int year=2000;
    string ans=sol.dayOfTheWeek(day,month,year);
    cout<<ans;
    return 0;
}
