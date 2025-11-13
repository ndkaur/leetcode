/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
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
// class MyHashSet {
//     int numBuckets;
//     vector<vector<int>> buckets;
//     int hash_function(int key){
//         return key % numBuckets;
//     }
// public:
//     MyHashSet() {
//         numBuckets = 15000;
//         buckets= vector<vector<int>>(numBuckets,vector<int>{});
//     }
    
//     void add(int key) {
//         int i= hash_function(key);
//         if(find(buckets[i].begin(),buckets[i].end,key)== buckets[i].end())
//             buckets[i].push_back(key);
//     }
    
//     void remove(int key) {
//         int i= hash_function(key);
//         auto itr= find(buckets[i].begin(),buckets[i].end(),key);
//         if(itr!= buckets[i].end())
//             buckets[i].erase(itr);
//     }
    
//     bool contains(int key) {
//         int i= hash_function(key);
//         if(find(buckets[i].begin(),buckets[i].end(),key)== buckets[i].end())
//             return false;
//         return true;
//     }
// };

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

class MyHashSet {
    vector<int> m;
    int sz;
public:
    MyHashSet() {
        sz= 1e6+1;
        m.resize(sz);
    }
    
    void add(int key) {
        m[key]=1;
    }
    
    void remove(int key) {
        m[key]=0;
    }
    
    bool contains(int key) {
        return m[key];
    }
};


class MyHashSet {
public:
    int numBuckets;
    vector<list<int>> buckets;

    int hash(int key){
        return  key%numBuckets;
    }

    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets, list<int>{});
    }
    
    void add(int key) { 
        int idx = hash(key);
        auto itr = find(buckets[idx].begin(), buckets[idx].end(), key);
        if(itr==buckets[idx].end())
            buckets[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto itr = find(buckets[idx].begin(), buckets[idx].end(), key);
        if(itr!=buckets[idx].end())
            buckets[idx].erase(itr);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        auto itr = find(buckets[idx].begin(), buckets[idx].end(), key);

        return itr != buckets[idx].end();
    }
};


class MyHashSet {
public:
    ListNode* head;
    MyHashSet() {
        head= new ListNode(-1);
    }
    
    void add(int key) {
        ListNode* temp= head;
        while(temp->next!=NULL){
            //  if key val already exists 
            if(temp->next->val==key) 
                return;
            temp=temp->next;
        }
        ListNode* newNode= new ListNode(key);
        temp->next = newNode;
    }
    
    void remove(int key) {
       ListNode* temp=head;
       while(temp->next!=NULL){
           if(temp->next->val==key){
                temp->next= temp->next->next;
                break;
           }
           temp=temp->next;
       }
    }
    
    bool contains(int key) {
        ListNode* temp=head->next;
        while(temp!=NULL){
            if(temp->val==key)
                return true;
            temp= temp->next;
        }
        return false;
    }
};


class MyHashSet {
public:
//      doubly linked list 
    vector<list<int>> m;
    int sz;
    
    MyHashSet() {
       int sz= 1e6+1;
        m.resize(sz);
    }
    
    int hash(int key){
        return key%sz; // one smaller idx
    }
    
    list<int> :: iterator search(int key){
        int i= hash(key);
        return find(m[i].begin(), m[i].end(), key);
    }
    
    
    void add(int key) {
        // check if already exist or not 
        if(contains(key)) return;
        int i= hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
//          key doesnot exist
       if(!contains(key))
           return;
        int i= hash(key);
        // at every i there can be exisiting multiple node values linked to each other 
//          so search for the apt value that needs to be deleted
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
       int i= hash(key);
        if(search(key)!= m[i].end()) // if key found
            return true;
        return false;
    }
};


// @lc code=end


int main(){

    return 0;
}