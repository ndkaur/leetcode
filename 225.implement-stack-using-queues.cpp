/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i=1;i<q.size();i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top_val = q.front();
        q.pop();
        return top_val;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=q
int main(){
    MyStack q;
    int out;
    q.push(1);
    q.push(2);
    out =q.top(); cout<<out<<"\n";   // returns 2
    out = q.pop(); cout<<out<<"\n";   // returns 2
    out = q.empty(); cout<<out<<"\n"; // returns false
    
}