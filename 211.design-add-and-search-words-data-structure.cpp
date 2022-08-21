/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containKey(char ch){
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

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root= new Node();
    }
    
    void addWord(string word) {
        Node* node= root;
        for(int i=0; i<word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            node= node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node= root;
        return helper(word, node);
    }

    bool helper(string word, Node* node){

        for(int i=0; i<word.size(); i++){
            if(word[i] == '.'){ // if . is found 
            // can match . with any char so that the rest of the remaining chars of string can be also matched with rest of the trie 
            // we give value of . to that char which is preset next in trie so that the remaining string can also be matched 
                for(char ch='a'; ch<='z'; ch++){
                    if(node->containKey(ch) && helper(word.substr(i+1), node->get(ch)))
                        return true;
                }
                return false;
            }
            else{ // if its not a . then simply check if i present or not
                if(!node->containKey(word[i]))
                    return false;
                node = node->get(word[i]);
            }
        }
        return node->isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

