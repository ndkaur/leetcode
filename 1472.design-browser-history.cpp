/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
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

class BrowserHistory { // using doubly linked list 
public:
    list<string> history;
    list<string> :: iterator it;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it= history.begin();
    }
    
    void visit(string url) {
        auto del= it; // delete everything in front of it 
        del++;
        history.erase(del,history.end());
        history.push_back(url);  // add new links
        it++;
    }
    
    string back(int steps) {
        while((it!= history.begin() && steps--)){
            it--;
        }
        return *it; // value of link at that point 
    }
    
    string forward(int steps) {
        while((it!= (--history.end()) && steps--)){
            it++;
        } // pre increment cause the ptr reach out of list
        return *it; 
    }
};



class BrowserHistory { // using array
public:
    string history[105] ={};
    int idx=0;
    int end=0;
    BrowserHistory(string homepage) {
        history[idx]= homepage;
    }
    
    void visit(string url) {
        history[++idx] =url;
        end= idx;
    }
    
    string back(int steps) {
        idx= max(idx-steps ,0);
        return history[idx];
    }
    
    string forward(int steps) {
       idx = min(idx+steps , end);
       return history[idx];
    }
};

class BrowserHistory { // using stack 
public:
    vector<string> tab;
    stack<string> forwardHistory;
    BrowserHistory(string homepage) {
        tab.clear();
        //  clear previous links 
        while(!forwardHistory.empty()){
            forwardHistory.pop();
        }
        //  add homepage 
        tab.push_back(homepage);
    }
    
    void visit(string url) {
        //  for visiting new link delete all previous visited links 
       while(!forwardHistory.empty()){
           forwardHistory.pop();
       }
       tab.push_back(url);
    }
    
    string back(int steps) {
        //  move back to url 
        while(tab.size()>1 && steps){
            //  store in forwardHistory 
            forwardHistory.push(tab.back());
            tab.erase(tab.end()-1);
            steps--;
        }
        return tab.back();
    }
    
    string forward(int steps) {
        //  move ahead to url 
       while(!forwardHistory.empty() && steps){
        //     store in vector<string>tab
           tab.push_back(forwardHistory.top());
           forwardHistory.pop();
           steps--;
       }
       return tab.back();
    }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end



int main(){

    return 0;
}