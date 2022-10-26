/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
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

// o(n^2) 
class MyCalendarTwo {
public:
// need to keep check for 3 overlaps so those who overlaped 2 times put then in overlap arr
    vector<pair<int,int>> overlap;
    vector<pair<int,int>> arr;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // check for 3rd overlap 
        for(auto itr: overlap){
            if(itr.first < end &&  itr.second > start)
                return false;
        }
        // check for 2nd overlap
        for(auto itr: arr){
            // when overlap for the first time then add to overlap arr
            if(itr.first < end && itr.second > start) // max of start , min of end 
                overlap.push_back({max(start,itr.first), min(end, itr.second)});
        }
        arr.push_back({start, end});
        return true;
    }
};


// s1 e1 overlap arr
// s2 e2 start end    ->  s1 <= e2  e1 >= s2

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end


int main(){

    return 0;
}