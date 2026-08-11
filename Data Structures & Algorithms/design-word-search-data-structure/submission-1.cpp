class PrefixNode {
    public:
    unordered_map<char, PrefixNode*> mp;
    bool isEnd = false;
};

class WordDictionary {
public:
    
    WordDictionary() {
    }
    PrefixNode* root = new PrefixNode();
    void addWord(string word) {
        PrefixNode* cur = root;
        for(char& c: word) {
            if(!cur->mp.contains(c)) cur->mp[c] = new PrefixNode();
            cur = cur->mp[c];
        }
        cur->isEnd = true;
    }

    bool searchSubString(string word, PrefixNode* cur) {
        // if(word == "") return true;
        for(int i=0; i< word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(auto node: cur->mp) {
                    string tmp = word.substr(i+1, word.size()-i+1);
                    if(searchSubString(tmp, node.second)) return true;
                }
                return false;
            } else if(!cur->mp.contains(c)) return false;
            cur = cur-> mp[c];
        }
        return cur->isEnd;
    }
    
    bool search(string word) {
        PrefixNode* cur = root;
        return searchSubString(word, cur);
    }
};
