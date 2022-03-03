/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* h1= list1;
        ListNode* h2= list1;
        while(b--){
            h2= h2->next;
        }
        while(a!=1){
            h1= h1->next;
            a--;
        }
        h1->next=list2;
        while(h1->next!=NULL){
            h1= h1->next;
        }
        h1->next= h2->next;
        return list1;
    }
};
// @lc code=end


int main(){

    return 0;
}