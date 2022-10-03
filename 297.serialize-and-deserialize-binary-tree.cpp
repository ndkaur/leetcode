/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {  // T-> o(n)  s-> O(n)
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { // tree->string
        if(!root) return "";

        string s= "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr==NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(curr->val)+',');
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { // string -> tree
        if(data.size()==0) return NULL;
        stringstream s(data); // convert string into form like cin , << insert dat , >> read data 
        string str;
        getline(s, str, ',') ;  // root // keeep on adding str till , comes
        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            // string -> root left right 
            getline(s, str, ','); // calling for ext left val
            if(str=="#"){
                node->left=NULL;
            }
            else {
                TreeNode*  leftNode= new TreeNode(stoi(str));
                node->left= leftNode;
                q.push(leftNode);
            }
            
            getline(s,str,','); // calling for next right val 
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* rightNode= new TreeNode(stoi(str));
                node->right= rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

455