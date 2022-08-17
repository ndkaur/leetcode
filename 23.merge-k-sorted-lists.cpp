/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// pq  T ->O(n*k)log(n*k)
// class cmp{
// public:
//     bool operator()(ListNode* a, ListNode* b){
//         return a->val > b->val;
//     }
// };
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//         ListNode* dummy= new ListNode(-1);
//         ListNode* tail= dummy;
        
//         priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
//         // pushed all the lists to the pq
//         // pq will store the list with the min elemts on top
//         for(int i=0;i<lists.size();i++){
//             if(lists[i]!=NULL){
//                 pq.push(lists[i]);
//             }
//         }
        
//         while(pq.size()){
//             ListNode* temp= pq.top();
//             tail->next= temp;
//             tail= temp;
//             pq.pop();
            // if values of that list is remaining 
//             if(temp->next!=NULL){
//                 pq.push(temp->next);
//             }
//         }
//         return dummy->next;
//     }
// };

// simple pq
class Solution { //tc->O(Nlogk)   sc-> O(k)
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<int , vector<int>, greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* head= lists[i];
            // push all lists val in pq
            while(head!=NULL){
                pq.push(head->val);
                head= head->next;
            }
        }

        ListNode* start= NULL;
        ListNode* end= NULL;
        while(!pq.empty()){
            // start of the list no elemt added , first elem to be added 
            if(start==NULL){
                start= new ListNode(pq.top());
                end= start; // end will be the same as start cause a new list is creted with only one elem in it 
                pq.pop();
            }
            else{
                end->next = new ListNode(pq.top());
                pq.pop();
                end= end->next;
            }
        }
        return start;
    }
};

// brute force 
class Solution { // tc->O(nk)   sc->O(1)
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        while(lists.size()>1){
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else {
            l2->next=  merge(l1, l2->next);
            return l2;
        }
    }
};



// @lc code=end

int main(){

    return 0;
}
