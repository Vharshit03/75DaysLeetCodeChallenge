class TrieNode {
    TrieNode* links[26];
    bool flag;

    public:
    bool checkNode(char ch){
        return links[ch-'a']!=NULL;
    }

    bool checkNode(int index){
        return links[index]!=NULL;
    }

    void setNode(char ch,TrieNode* node){
        links[ch-'a'] = node;
    }

    TrieNode* getNode(char ch){
        return links[ch-'a'];
    }

    TrieNode* get(int index){
        return links[index];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
   
};

class WordDictionary {
private: TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size(); i++){
            if(!node->checkNode(word[i])){
                node->setNode(word[i],new TrieNode());
            }

            node = node->getNode(word[i]);
        }

        node->setEnd();
    }

    bool searchUtil(TrieNode* root,string word){

        TrieNode* node = root;
        for(int i=0;i<word.size(); i++){

            char ch = word[i];

            if(ch=='.'){
                for(int j=0;j<26;j++){
                    
                    if(node->checkNode(j)){
                        if(searchUtil(node->get(j),word.substr(i+1)))
                        return true;
                    }
                }
                return false;
            }
            else if(!node->checkNode(ch))
            return false;

            node = node->getNode(ch);
        }

        return node!=NULL && node->isEnd();
    }
    
    bool search(string word) {

        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */