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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // 18,6,10,3
        // 18,6,6,2,10,1,3
        ListNode* temp = head;
        while(temp && temp->next){
            int a = temp->val;
            int b = temp->next->val;
            int gcd = __gcd(a,b);
            ListNode* store = temp->next;
            temp->next = new ListNode(gcd);
            temp->next->next= store;
            temp= temp->next->next;
        }
        return head;
    }
};

int main(){

    return 0;
}