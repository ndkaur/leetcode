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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if(!head)
            return NULL;

        int take = 0;
        int ntake = 0;
        ListNode* curr = head;
        ListNode* temp;

        while(curr){
            take++;
            if(take==m){
                temp = curr;
                while(temp && ntake!=n+1){
                    ntake++;
                    temp = temp->next;
                }
                curr->next = temp;
                take = 0;
                ntake = 0;
                curr= curr->next;
            }
            else {
                curr= curr->next;
            }
        }
        return head;
    }
};


int main(){

    return 0;
}