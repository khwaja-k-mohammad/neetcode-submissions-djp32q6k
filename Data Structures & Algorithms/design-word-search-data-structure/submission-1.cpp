struct TrieNode
{
    bool isEOW;
    vector<TrieNode *> children;
    TrieNode(): isEOW(false), children(26, nullptr) {}
};

class WordDictionary {
public:

    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        
        TrieNode *temp = root;
        for(auto ch : word)
        {
            if(!temp -> children[ch - 'a']) temp -> children[ch - 'a'] = new TrieNode();
            temp = temp -> children[ch - 'a'];
        }

        temp -> isEOW = true;
    }
    
    bool searchChar(string word, TrieNode *root, int index)
    {
        if(!root) return false;
        if(index == word.length()) return root -> isEOW;

        char ch = word[index];
        if(ch != '.')
        {
            if(!root -> children[ch - 'a']) return false;
            return searchChar(word, root -> children[ch - 'a'], index+1);
        }
        else {
            for(int i=0;i<26;i++)
            {
                if(root -> children[i]) {
                    if(searchChar(word, root -> children[i], index+1)) return true;
                }
            }

            return false;
        }
    }

    bool search(string word) {
        return searchChar(word, root, 0);
    }
};
