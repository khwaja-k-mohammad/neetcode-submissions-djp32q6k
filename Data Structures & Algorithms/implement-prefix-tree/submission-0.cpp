class PrefixTree {
public:

    struct TrieNode
    {
        bool isWord = false;
        vector<TrieNode*> children{26, nullptr};
    };
    
    TrieNode *root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode *temp = this -> root;

        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if(!temp -> children[index]) {
                TrieNode *currNode = new TrieNode();
                temp -> children[index] = currNode;
            }
            
            temp = temp -> children[index];
        }

        temp -> isWord = true;
    }
    
    bool search(string word) {
        
        TrieNode *temp =  this -> root;

        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if(! temp -> children[index]) return false;
            temp = temp -> children[index];
        }

        return temp -> isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp =  this -> root;

        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i] - 'a';
            if(! temp -> children[index]) return false;
            temp = temp -> children[index];
        }

        return true;
    }
};