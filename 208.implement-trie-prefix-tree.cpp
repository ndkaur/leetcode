/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start


class TrieNode{
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for(auto& c:child){
            c = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            // check if word already exist 
            int ch = word[i]-'a';
            if(!node->child[ch]){ // doent already exist then add it 
                node->child[ch] = new TrieNode();
            }
            //move ahead 
            node = node->child[ch];
        }
        // we reached end of word mark flag as true
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            int ch = word[i]-'a';
            // if that ch doesnot exist 
            if(!node->child[ch])
                return false;
            // if it exist then move ahead till the end of word
            node=  node->child[ch];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=  root;
        for(int i=0; i<prefix.size(); i++){
            int ch = prefix[i]-'a';
            if(!node->child[ch])
                return false;
            node = node->child[ch];
        }
        return true;
    }
};

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node= node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return false;
            node= node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node= root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i]))
                return false;
            node= node->get(prefix[i]);
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

