/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
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

class MyHashMap {
public:
    vector<int> arr;
    MyHashMap() {
        arr.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        arr[key] = value; 
    }
    
    int get(int key) {
        if(arr[key]==-1)
            return -1;
        else 
            return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};



// using linked list approach 

class Node{
public:
    int key;
    int val;
    Node* next;

    Node(int k=-1, int v=-1, Node* n=NULL) : key(k), val(v), next(n){}
};

class MyHashMap {
public:
    vector<Node*> mp;
    MyHashMap() {
        mp.resize(1000);
        for(int i=0; i<1000; i++){
            mp[i]= new Node();
        }
    }

    int hash(int key){
        return key%1000;
    }

    void put(int key, int value) {
        int hash_key = hash(key);
        Node* curr = mp[hash_key];

        while(curr->next){
            if(curr->next->key==key){
                curr->next->val = value;
                return;
            }
            curr= curr->next;
        }
        curr->next = new Node(key, value);
    }
    
    int get(int key) {
        int hash_key = hash(key);
        Node* curr = mp[hash_key];
        while(curr->next){
            if(curr->next->key==key){
                return curr->next->val;
            }
            curr= curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = hash(key);
        Node* curr = mp[hash_key];
        while(curr->next){
            if(curr->next->key==key){
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr= curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end


int main(){

    return 0;
}