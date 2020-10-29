/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)  return head;
        ListNode *slow=head;
        ListNode *fast =head;

        //positioning the pointers
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //breaking the lists into two parts
        fast=slow->next;
        slow->next=NULL;

        return merge(sortList(head),sortList(fast));
    }
    // merge sort
    ListNode *merge(ListNode *left,ListNode *right){
        if(!left && !right) return left;
        if(!left) return right;
        if(!right)  return left;

        // new list to insert data
        ListNode *extra = new ListNode(0);
        ListNode *ans=extra;

        //inserting by comparision
        while(left && right){
            if(left->val<=right->val){
                ans->next=left;
                left=left->next;
            }
            else {
                ans->next=right;
                right=right->next;
            }
            ans=ans->next;
        }
        // to insert the values which are not included from left and right
        ans->next=left?left:right;

        return extra->next;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={-1,5,3,4,0};
    ListNode *head=createList(a);
    ListNode *output=sol.sortList(head);
    printList(output);
    return 0;
}
/* My proposal
#include<bits/stdc++.h>
using namespace std;
int main(){
int arr[5] ={-1,5,3,4,0};
sort(arr , arr+5);
for(auto e : arr) cout<<e<<" ";
cout<<endl;
return 0;
}
*/
