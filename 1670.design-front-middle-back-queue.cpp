/*
 * @lc app=leetcode id=1670 lang=cpp
 *
 * [1670] Design Front Middle Back Queue
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
class FrontMiddleBackQueue {
public:
    deque<int> dq1, dq2;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        dq1.push_front(val);
        while(dq1.size()-dq2.size()>1){ // diff more than one 
        // remove last element of d1 and push it in d2
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
    }
    
    void pushMiddle(int val) {
        if(dq1.size()== dq2.size())
            dq1.push_back(val);
        else{ // size difference more than one 
            dq2.push_front(dq1.back()); // last elemnet of d1 put in d2
            dq1.pop_back();
            dq1.push_back(val);
        }
    }
    
    void pushBack(int val) {
        dq2.push_back(val);
        while(dq2.size()> dq1.size()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
    }
    
    int popFront() {
        if(dq1.empty()) return -1;
        int ans = dq1.front();
        dq1.pop_front();
        while(dq2.size()> dq1.size()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    int popMiddle() {
        if(dq1.empty()) return -1;
        int ans= dq1.back();
        dq1.pop_back();
        while(dq2.size()>dq1.size()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    int popBack() {
        if(dq1.empty()) return -1;
        if(dq2.empty()){ // one element in dq1
            int ans = dq1.back();
            dq1.pop_back();
            return ans;
        }
        int ans= dq2.back();
        dq2.pop_back();
        while(dq1.size()-dq2.size()>1){
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
        return ans;
    }
};


class node{
public:
    int data{0};
    node* next{nullptr};
    node* prev{nullptr};
    node(int data): data(data){}
};
class FrontMiddleBackQueue {
public:
    node* head= NULL;
    node* last= NULL;
    FrontMiddleBackQueue() {
        head= last= NULL;
    }
    
    void pushFront(int val) {
        node* newNode = new node(val);
        if(!head){
            head= last = newNode;
        } else{
            newNode->next= head;
            head->prev=newNode;
            head= newNode;
        }
    }
    
    void pushMiddle(int val) {
        if(!head || !head->next){
            pushFront(val);
            return ;
        }
        //  already a list existing then find mid 
        node* slow= head;
        node* fast= head;
        node* past= head;
        while(fast && fast->next){
            past= slow;
            slow= slow->next;
            fast= fast ->next->next;
        }
        node* newNode = new node(val);
        past->next= newNode;
        newNode->prev= past;
        newNode->next= slow;
        slow->prev= newNode;
    }
    
    void pushBack(int val) {
        node* newNode= new node(val);
        if(!head){
            head= last = newNode;
        } else{
            last-> next= newNode;
            newNode->prev= last;
            last = newNode;
        }
    }
    
    int popFront() {
        if(!head){
            return -1;
        }
        int temp = head->data;
        if(!head->next){
            head= last= NULL;
            return temp;
        }
        else{
            head = head->next;
            head->prev= NULL;
        }
        return temp;
    }
    
    int popMiddle() {
        if(!head)
            return -1;
        else if(!head->next || !head->next->next){
            return popFront();
        }
        node* slow=head;
        node* fast = head;
        node* past= head;
        while(fast && fast->next){
            past= slow;
            slow= slow->next;
            fast= fast->next->next;
        }
        int d= fast ? slow->data : past->data;
        //  even no of nodes fast is null
        // past slow next fast
        if(!fast){
            //  even node then remove node previous to mid = past 
            //  temp = prev<-past 
            //  removed past by changing next of temp
            node* temp= past->prev;
            temp->next= slow;
            slow->prev= temp;
        } else{
            //  odd node then remove the mid element which is = slow
            node* temp = slow->next;
            past->next= temp;
            temp->prev= past;
        }
        return d;
    }
    
    int popBack() {
        if(!last)
            return -1;
        int d= last->data;
        if(!head->next)
            head= last= NULL;
        else {
            last= last->prev;
            last->next= NULL;
        }
        return d;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end


class FrontMiddleBackQueue {
    deque<int> dq1, dq2;
public:
    FrontMiddleBackQueue() {
        
    }
//      we assume that dq1 size can be 1 greater than dq2 size
    void pushFront(int val) {
        dq1.push_front(val);
//          if size diff equal to 1
        while(dq1.size()-dq2.size()>1){
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
    }
//      whenever pop is from dq2 we check the diff btw dq1 and dq2 are of 1
    void pushMiddle(int val) {
        if(dq1.size()==dq2.size())
            dq1.push_back(val);
        else{
            dq2.push_front(dq1.back());
            dq1.pop_back();
            dq1.push_back(val);
        }
            
    }
    
    void pushBack(int val) {
        dq2.push_back(val);
        while(dq2.size()>dq1.size()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        
    }
    
    int popFront() {
        if(dq1.empty()) 
            return -1;
        int ans= dq1.front();
        dq1.pop_front();
        while(dq2.size()>dq1.size()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    int popMiddle() {
        if(dq1.empty()) return -1;
        int ans= dq1.back();
        dq1.pop_back();
        while(dq2.size()> dq1.size()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    int popBack() {
        if(dq1.empty()) return -1;
        if(dq2.empty()){
            int ans= dq1.back();
            dq1.pop_back();
            return ans;
        }
        int ans= dq2.back();
        dq2.pop_back();
        while(dq1.size()-dq2.size()>1){
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
        return ans;
    }
};

//  using array 

class FrontMiddleBackQueue {
    vector<int> arr;
public:
    FrontMiddleBackQueue() {
        
    }

    void pushFront(int val) {
        arr.insert(arr.begin(), val);
    }

    void pushMiddle(int val) {
        int mid= arr.size()/2;
        arr.insert(arr.begin()+mid, val);
    }
    
    void pushBack(int val) {
        arr.push_back(val);
    }
    
    int popFront() {
        if(arr.size()==0) 
            return -1;
        int val= arr[0];
        arr.erase(arr.begin());
        return val;
    }
    
    int popMiddle() {
        if(arr.size()==0)
            return -1;
        int mid= (arr.size()%2==0) ? (arr.size()/2)-1 : arr.size()/2;
        int val= arr[mid];
        arr.erase(arr.begin()+mid);
        return val;
    }
    
    int popBack() {
        if(arr.size()==0)
            return -1;
        int val= arr.back();
        arr.pop_back();
        return val;
    }
};



int main(){

    return 0;
}