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





int main(){

    return 0;
}