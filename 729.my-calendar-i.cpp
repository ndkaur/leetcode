/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
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
class MyCalendar {
private:
    map<int,int> mp; // num,val
public:
    MyCalendar() {
        
    }
    // kind of prefix sum technique 
    //give start +1 
    // give end -1 
    bool book(int start, int end) {
       mp[start]++;
       mp[end]--;
       // to count the running sum
       int sum=0;
       for(auto itr=mp.begin(); itr!=mp.end();itr++){
            sum+= itr->second;
            if(sum>1){
                mp[start]--;
                mp[end]++;
                return false;
            }
       }
       return true;
    }
};

// inital state -> {a,b}
// current state-> {c,d}   
// if overlap then it will be like a  c  b  d 
//  condition will  be -> c<b && a<d 


// using condition in array form 
class MyCalendar { // o(n^2)
public:
    vector<pair<int,int>> arr;
    MyCalendar() {  
    }
    
    bool book(int start, int end) {
        // cur is end and start
        // initial ->itr is what is already in 
        for(auto itr: arr){
            // c<b && a<d  // overlap case
            if(start < itr.second && itr.first<end)
                return false;
        }
        arr.push_back({start,end});
        return true;
    }
};


class MyCalendar { // o(n^2)
public:
    vector<pair<int,int>> arr;
    MyCalendar() {  
    }
    
    bool book(int start, int end) {
        // cur is end and start
        // initial ->itr is what is already in 
        for(auto itr: arr){
            // c<b && a<d  // overlap case
            if(start < itr.second && itr.first<end)
                return false;
        }
        arr.push_back({start,end});
        return true;
    }
};

// s1 e1 arr
// s2 e2 start end    ->  s1 <= e2  e1 >= s2

//  using lowe bound 

class MyCalendar { // O(nlog(n))
public:
    set<pair<int,int>> s;
    MyCalendar() {  
    }
    
    bool book(int start, int end) {
        // cur is end and start
        // initial ->itr is what is already in 
        // finding the imidiate greater number then start which wil be already in set if overlap exist 
        auto it= s.lower_bound({start,end});
        // a<d
        if(it!= s.end() && it->first< end)
            return false;
        // c<b
        if(it!=s.begin() && start < (--it)->second)
            return false;
        // if no overlap then insert
        s.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end


int main(){

    return 0;
}