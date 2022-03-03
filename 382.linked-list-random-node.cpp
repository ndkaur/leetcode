/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
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
private:
    ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res=head->val;
        ListNode* node =head->next;
        int i=2;
        while(node){
            int j=rand()%i;
            if(j==0)
                res=node->val;
            i++;
            node=node->next;
        }
        return res;
    }
};

class Solution { // array 
public:
    vector<int> ans;
    Solution(ListNode* head) {
        while(head){
            ans.push_back(head->val);
            head= head->next;
        }
    }
    
    int getRandom() {
        return ans[rand()% ans.size()];
    }
};


class Solution {  // reservoir sampling method
public:
    ListNode* curr;
    Solution(ListNode* head) {
        curr= head;
    }
    
    int getRandom() {
        int ans=0;
        int len=1;
        ListNode* temp= curr;
        while(temp){
            if(rand()% len==0)
                ans= temp->val;
            len++;
            temp= temp->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    }
    return 0;
}