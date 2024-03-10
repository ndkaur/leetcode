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
    ListNode* frequenciesOfElements(ListNode* head) {
        map<int,int> mp;
        ListNode* curr=  head;
        if(!head)
            return NULL;
        while(curr){
            mp[curr->val]++;
            curr = curr->next;
        }
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        for(auto itr:mp){
            temp->next = new ListNode(itr.second);
            temp = temp->next;
        }
        return ans->next;
    }
};

int main(){

    return 0;
}