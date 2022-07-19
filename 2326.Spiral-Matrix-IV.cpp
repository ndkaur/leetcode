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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> spiral(m, vector<int>(n,-1));
        int i=0;
        int j=0;
        // the thing that remain same we write acc to direction of movement ++ or --
        while(head!=NULL){
            // going from left to right = col changes row remain same
            if(j<n){
                while(head!=NULL && j<n && spiral[i][j]==-1){
                    spiral[i][j]= head->val;
                    head= head->next;
                    j++;
                }
                if(head==NULL)
                    break;
                // changing the direction 
                i++;
                j--;
            }
            // going from right top to right bottom row chnges col same
            if(i<m){
                while(head!=NULL && i<m && spiral[i][j]==-1){
                    spiral[i][j] = head->val;
                    head= head->next;
                    i++;
                }
                // changing the dir 
                i--;
                j--;
            }
            // goint from right bottom to left bottom col changes row same 
            if(j>=0){
                while(head!=NULL && j>=0 && spiral[i][j]==-1){
                    spiral[i][j]= head->val;
                    head= head->next;
                    j--;
                }
                // chnging the direction
                i--;
                j++;
            }
            // going from left bottom to left top 
            if(i>=0){
                while(head!=NULL && i>=0 && spiral[i][j]==-1){
                    spiral[i][j]=  head->val;
                    head= head->next;
                    i--;
                }
                i++;
                j++;
            }
            // one row of spiral got filled
            m--;
            n++;
        }
        return spiral;
    }
};



int main(){

    return 0;
}