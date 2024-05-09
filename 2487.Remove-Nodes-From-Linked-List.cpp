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


class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head)
            return NULL;
        head->next = removeNodes(head->next);
        return head->next && head->val<head->next->val ? head->next : head;
    }
};


// 5 2 13 pop all -> 2<13, increasing order formed then pop = decreasing stack
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy  = new ListNode(INT_MAX);
        vector<ListNode*> stk = {dummy};
        while(head){
            // monotonic decresing stack 
            while(stk.size() && stk.back()->val<head->val){ // inc break condition 
                stk.pop_back();
            }
            // setting up links 
            stk.back()->next = head;
            stk.push_back(head);
            head= head->next;
        }
        return dummy->next;
    }
};



int main(){

    return 0;
}