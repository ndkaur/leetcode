/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        ListNode *curr=head;
        while(curr){
            int cv=curr->val;
            ListNode *temp=curr->next;
            while(temp && temp->val<=cv){
                    temp=temp->next;
            }
            if(temp)
                result.push_back(temp->val);
            else 
                result.push_back(0);
            curr=curr->next;
        }
        return result;
    }
};
// @lc code=end


int main(){

    return 0;
}