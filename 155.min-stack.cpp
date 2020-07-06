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
            ans=x;
        }
        else{
            s.push(x);
            if(x<ans){
                minn.push(x);
                ans=x;
            }
        }
    }
    
    void pop() {
        if(s.size()==0)
            return;
        if(s.top()==minn.top()){
            minn.pop();
            if(minn.size())
                ans=minn.top();
            else 
                ans=INT_MIN;
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