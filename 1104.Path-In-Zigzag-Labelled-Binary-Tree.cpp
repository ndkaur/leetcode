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
        vector<int> pathInZigZagTree(int label) {
            vector<int> ans;
            ans.push_back(label);
    
            int no_of_nodes=1;
            int sum = 0;
            
            while(sum<label){
                sum += no_of_nodes;
                no_of_nodes*=2;
            } 
            // label =14, sum=15, noof_node =16
            no_of_nodes/=2;
            
            while(label!=1){
                int compliment = 3*no_of_nodes - label -1;
            
                int parent_of_compliment = compliment/2;
                ans.push_back(parent_of_compliment);
                label = parent_of_compliment;
                no_of_nodes/=2;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    
    // when we make a simple binary tree we observe that the zigzag tree has the values swapped for the even rows
    // simple bt-> {1} {2,3} {4,5,6,7}, {8,9, 10, 11, 12, 13,14, 15}
    //zigzag bt-> {1} {3,2} {4,5,6,7}, {15,14,13,12,11,10,9,8,7}
    // the values gets swapped, so instead of making the whole binary tree if we find out a way so that we can know  who is the parent of the label we need 
    // parent in simple bt = node/2
    // in zigzag bt -> parent is parent of swapped node/2
    // we have to find the swapped node then, ?= swapped node, label= node we know
    // start label  ? end .. since its swappe ddistance will be equal
    // start-label = ?-end
    // ? = end+start-label
    
    // how to find start and end val
    // simple bt-> {1} {2,3} {4,5,6,7}, {8,9, 10, 11, 12, 13,14, 15}
    
    // start = no of nodes at that level = 2^level
    // 2^0 = 1, 2^1= 2, 2^2 = 4, 2^3 =8
    
    // end = submation of all the number of nodes present till that level
    // end = 2*nof nodes at that level-1 = 2*(2^level)-1
    //level=0 ->2*1-1 =1 , level=1-> 2*2-1 = 3 , level=2 -> 2*4-1=7, level=3 ->2*8-1=15
    
    // final equation -> ? = end+start-label
    // ? = 2*nodeatthatlevel-1 + nodesathtatlevel -label
    // ? = 3* nodeAtThatLevel-label-1
    
    // bumber of nodes at that level -> how to find it
    // i=1, height = i-1 = 0 , 2^0 = 1 node at level 1 =1
    // i=2, height = 2-1 =1 , 2^1 = 2, nodes at level 2 =2
    
    // we will keep track of sum of all node for each level
    // when we get the sum equal to label or more we will stop , 
    // and calcate the value  of compliment ? using equation 
    // then find the parent of ?compliment  -> ?/2
    


int main(){

    return 0;
}