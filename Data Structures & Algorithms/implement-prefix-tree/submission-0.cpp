class PrefixNode {
    public:
    unordered_map<char, PrefixNode*> mp;
    bool isEnd = false;
};
class PrefixTree {
public:
    PrefixTree() {
    }
    PrefixNode* root = new PrefixNode();   
    void insert(string word) {
        PrefixNode* cur = root;
        for(char& c: word) {
            if(!cur->mp.contains(c)) cur->mp[c] = new PrefixNode();
            cur = cur->mp[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        PrefixNode* cur = root;
        for(char& c: word) {
            if(!cur->mp.contains(c)) return false;
            cur = cur->mp[c];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* cur = root;
        for(char& c: prefix) {
            if(!cur->mp.contains(c)) return false;
            else cur = cur->mp[c];
        }
        return true;
    }
};
