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
        vector<int> ans;
        ListNode* curr= head;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            while(temp!=NULL && temp->val<= curr->val){ // till the time values are less or equal move ahead
                temp= temp->next;
            }
            // check if temp exist can be possible that no greater val found 
            if(temp) 
                ans.push_back(temp->val);
            else
                ans.push_back(0);
            curr= curr->next;
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}