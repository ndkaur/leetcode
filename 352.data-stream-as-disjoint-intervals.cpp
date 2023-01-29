/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
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

// cant use simple array and sort function on it 

// o(logn) + O(n)
class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        // 1  2  3  7 -> merge in one array till its continuous
        // 1 3 7
        int start = -1;
        int end = -1;
        for(auto itr:s){
            if(start == -1){ // at the beginning
                start =  itr;
                end = itr;
            }
            else if(itr == end+1){ // check for consectutive
                end = itr;
            }
            else{ // not consecutive then push in ans and update 
                ans.push_back({start,end});
                start =  end = itr;
            }
        }
        // pushing the remaining range 
        if(start != -1)
            ans.push_back({start, end});
        
        return ans;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end



int main(){

    return 0;
}