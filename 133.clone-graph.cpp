/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* clone(unordered_map<int,Node*> &copy,Node* n){
        if(copy[n->val]) return copy[n->val]; // if copy of this node exist return it
        // create new copy 
        copy[n->val] = new Node(n->val);
        //create copy of neighbours 
        for(auto &x:n->neighbors){
            auto &neighbors_copy = copy[n->val]->neighbors;
            neighbors_copy.push_back(clone(copy,x));
        }
        // return copy of node
        return copy[n->val];
    }
public:
    Node* cloneGraph(Node* node) {
       if(!node) return node;
       unordered_map<int,Node*> copy;
       return clone(copy,node);
    }
};
// @lc code=end

