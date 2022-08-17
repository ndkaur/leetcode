/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
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

// from linked list we are deleting the address 
// from map we delte the original key 

class LRUCache { // O(N)  O(1)
public:
// creating the doubly linked list 
    class node{
    public: 
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key= _key;
            val = _val;
        }
    };

    int cap;
    unordered_map<int, node*> mp;
    // creting head nad tail
    node* head= new node(-1,-1);
    node* tail = new node(-1,-1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end()){ // if already exist in map
            node* resnode= mp[key]; // storing the address of the key 
            int res= resnode->val; // storing the values for that index 

            mp.erase(key); // deleting the key in map
            deletenode(resnode);  // deleting the address node from list 
            addnode(resnode); // adding node as most recent used 

            mp[key] = head->next; // giving new address to the added node 
            return res;
        }
        return -1; // doesnot exist in map
    }
    
    void put(int key, int value) {
        if(mp.find(key)!= mp.end()){ // if already exist in map then delete it and make it mru 
            node* exnode= mp[key];
            mp.erase(key);
            deletenode(exnode); // deleting the address 
        }
        // if size not allowed 
        if(mp.size() == cap){
            mp.erase(tail->prev->key); // delete the lru
            deletenode(tail->prev);
        } 
        // add a new node as mru 
        addnode(new node(key, value));
        mp[key] = head->next;
    }
    
    void deletenode(node* delnode){
        node* delnext=  delnode->next;
        node* delprev= delnode->prev;
        delprev->next = delnext;
        delnext->prev= delprev;
    }
    
    void addnode(node* newnode){
        node* temp= head->next;
        head->next= newnode;
        newnode->prev= head;
        newnode->next= temp;
        temp->prev= newnode;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


int main(){

    return 0;
}