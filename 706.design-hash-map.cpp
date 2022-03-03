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
    vector<int> m;
    int sz;
    MyHashMap() {
        sz= 1e6+1;
        m.resize(sz);
        fill(m.begin(),m.end(),-1);
    }
    
    void put(int key, int value) {
        m[key]= val;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key]=-1;
    }
};

class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int sz;
    MyHashMap() {
        sz= 1e6+1;
        m.resize(sz);
    }
    int hash_function(int key){
        return key%sz;
    }
    list<pair<int,int>> :: iterator search(int key){
        int i= hash_function(key);
        list<pair<int,int>> :: iterator it = m[i].begin();
        while(it!= m[i].end()){
            if(it->first== key) 
                return it;
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        int i= hash(key);
        remove(key);
        m[i].push_back({key,value});
    }
    
    int get(int key) {
        int i= hash(key);
        list<pair<int,int>> :: iterator it= search(key);
        if(it==m[i].end())
            return -1;
        else return it->second;
    }
    
    void remove(int key) {
        int i= hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it!= m[i].end())  // check if key exist 
            m[i].erase(it));
    }
};


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