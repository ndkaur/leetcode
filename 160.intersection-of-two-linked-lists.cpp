/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;

#include "LinkedList.h"
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  brute force :- for headA travel each headB
//O(m*n)
class Solution0 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp;
        while(headA){
            temp= headB;
            while(temp){
                if(temp== headA) 
                    return headA;
                temp=temp->next;
            }
            headA= headA->next;
        }
        return NULL;
    }
};


//  use extra space make map
//O(n+m)  //O(n) for map
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode* , int> mp; // stores the address 
        while(headA){
            mp[headA]++;
            headA=headA->next;
        } 
        while(headB){
            if(mp[headB]>0)  // address already exist 
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

// making the lenghts sync in together then moving together
//  reducing the large lenght so it get equal 
// time > O(len of longest list ) + O( len 1 - len2) + O( len of shorter list) = O(2 len of longest list )  // space -> O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0;
        int l2=0;
        ListNode* h1= headA;
        ListNode* h2= headB;
        while(headA){
            l1++;
            headA=headA->next;
        }
        while(headB){
            l2++;
            headB = headB->next;
        }
        //  taking the ptr in synchronization 
        int diff = abs(l1-l2);
        if(l1>l2){
            while(diff--)
                h1 = h1->next;
        }
        else{
            while(diff--)
                h2= h2->next;
        }

        while(h1 && h2){
            if(h1==h2)
                return h1;
            h1=h1->next;
            h2= h2->next;
        }
        return NULL;
    }
};


//  moving headA with lenght = (m+x)+(n+x)
//  moving headB with lenght = (n+x)+(m+x)
// balancing out the lenghts 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return NULL;
        if(!headB)  return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b){
            if(a){
                a=a->next;
            }
            else 
                a=headB;
            if(b){
                b=b->next;
            }
            else 
                b=headA;
        }
        // deb(a->val);
        return a;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> one={1,9,1,2,4};
    vector<int> two={3,2,4};
    ListNode *headA=createList(one);
    ListNode *headB=createList(two);
    ListNode *ans;
    ans= sol.getIntersectionNode(headA,headB);
    return 0;
}