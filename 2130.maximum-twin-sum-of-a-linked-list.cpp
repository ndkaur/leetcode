/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* temp= head;
        while(temp){
            arr.push_back(temp->val);
            temp= temp->next;
        }
        int ans =0;
        int n= arr.size();
        for(int i=0;i<n/2;i++){
            int sum = arr[i]+arr[n-1-i];
            ans = max(sum,ans);
        }
        return ans;
    }
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast->next && fast->next->next){
            slow= slow->next;
            fast=fast->next->next;
        }
        // reverse
        ListNode* prev= NULL;
        while(slow){
            ListNode* temp= slow->next;
            slow->next= prev;
            prev= slow;
            slow= temp;
        }
        int sum=0;
        ListNode* ptr=head;
        while(prev!=NULL){
            sum= max(sum, ptr->val+prev->val);
            ptr=ptr->next;
            prev= prev->next;
        }
        return sum;
    }
};

// @lc code=end


int main(){

    return 0;
}