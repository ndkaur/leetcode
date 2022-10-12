#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class MinStack {
public:
    stack<int> s;
    stack<int> minn;
    int ans;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.size()==0){
            s.push(x);
            minn.push(x);
            ans=x; // ans is used for storing the min val 
        }
        else{
            s.push(x);
            if(x<ans){ // one more val came which is min than the prev min ie ans
                minn.push(x);
                ans=x;// marking the new min 
            }
        }
    }
    
    void pop() {
        if(s.size()==0)
            return;
        if(s.top()==minn.top()){
            minn.pop(); // poped the min ele 
            if(minn.size())
                ans=minn.top(); // marking the new min ele 
            else // if no size 
                ans=INT_MIN; // new min val
        }
        s.pop();
    }
    
    int top() {
        if(s.size())
            return s.top();
        return INT_MIN;
    }
    
    int getMin() {
        if(s.size())
            return minn.top();
        return INT_MIN;
    }
};

class MinStack { //O(1)  space->O(N)
public:
    vector<pair<int,int>> stk; // {val, minval}
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.size()==0) // empty array
            stk.push_back({val,val});
        else  // not empty , insert val and the min of curr val and prev val
            stk.push_back({val,min(val,stk.back().second)});
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() { 
        return stk.back().first;
    }
    
    int getMin() { // return the min ele , min elem is the second val of pair
        return stk.back().second;
    }
};

class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x <= getMin()) // empty or new min val found
            s2.push(x);
    }
    
    void pop() {
        if(s1.top() == getMin())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};


class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty())
            stk.push({val,val});
        else 
            stk.push({val, min(val, stk.top().second)});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(){
    MinStack s;
    s.push(-1);
    cout<<(s.getMin());
    s.push(-1);
    s.push(-3);
    s.push(-2);
    cout<<(s.getMin());
    s.push(-10);
    s.push(-10);
    cout<<(s.getMin());
    s.push(-10);

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<(s.top());
    cout<<(s.getMin());
    return 0;
}