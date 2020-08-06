/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
    int numComponents(ListNode* head, vector<int>& g) {
        unordered_set<int> s(g.begin(),g.end());
        ListNode *curr=head;
        int count=0;
        while(curr){
            if(s.count(curr->val) && (curr->next==NULL || !s.count(curr->next->val)))
                count++;
            curr=curr->next;
        }
        return count;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> a={0,1,2,3,4};
    ListNode *head=createList(a);
    vector<int> g={0,3,1,4};
    int ans=sol.numComponents(head,g);
    cout<<ans;
    return 0;
}
