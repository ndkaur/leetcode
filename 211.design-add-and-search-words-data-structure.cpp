/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start



class TrieNode{
public:
    TrieNode* child[26];
    bool isword = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            int ch = word[i]-'a';
            // does not exist 
            if(!node->child[ch]){
                node->child[ch] = new TrieNode();
            }
            node= node->child[ch];
        }
        node->isword = true;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }

    bool helper(string &word, int idx, TrieNode* node){
        for(int i=idx; i<word.size(); i++){
            if(word[i]!='.'){
                int ch = word[i]-'a';
                if(!node->child[ch])
                    return false;
                node = node->child[ch];
            }
            else{// its a dot then match with each char from a to z
                for(int ch=0; ch<26; ++ch){
                    // check if the char we choose exist in trie and then check the reming word chars 
                    if(node->child[ch] && helper(word, i+1, node->child[ch]))
                        return true;
                }
                return false;
            }
        }
        return node->isword;
    }
};

class TrieNode{
public:
    TrieNode* child[26];
    bool isword = false;
    // TrieNode(){
    //     isword = false;
    //     for(auto &ch:child){
    //         ch = NULL;
    //     }
    // }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            int ch = word[i]-'a';
            // does not exist 
            if(!node->child[ch]){
                node->child[ch] = new TrieNode();
            }
            node= node->child[ch];
        }
        node->isword = true;
    }
    
    bool search(string word) {
        return helper(word, root);
    }

    bool helper(string word, TrieNode* node){
        for(int i=0; i<word.size(); i++){
            int ch = word[i]-'a';
            if(word[i]!='.'){
                if(!node->child[ch])
                    return false;
                node = node->child[ch];
            }
            else{
                bool found = false;
                

                int j=0;
                for(; j<26; j++){
                    if(node->child[j])
                        found = found | helper(word.substr(i+1), node->child[j]);
                        if(found)
                            return true;
                }
                if(j==26)
                    return false;
            }
        }
        return node->isword;
    }
};




/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

