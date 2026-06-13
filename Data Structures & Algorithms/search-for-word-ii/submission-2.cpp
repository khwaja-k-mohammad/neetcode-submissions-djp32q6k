struct TrieNode
{
    bool isEOW;
    string word;
    vector<TrieNode*> children;

    TrieNode(): children(26, NULL), word(""), isEOW(false) {}
};

class Solution {
public: 

    void insertWord(TrieNode *root, string word)
    {
        TrieNode *temp = root;
        for(auto ch : word)
        {
            if(!temp -> children[ch - 'a']) temp -> children[ch-'a'] = new TrieNode();

            temp = temp -> children[ch - 'a'];
        }

        temp -> isEOW = true;
        temp -> word = word;
    }

    void search(vector<vector<char>> &board, TrieNode *root, vector<string> &result, int currRow, int currCol)
    {
        if(!root -> children[board[currRow][currCol] - 'a']) return ;
        
        root = root -> children[board[currRow][currCol] - 'a'];
        if(root -> isEOW) {
            result.push_back(root -> word);
            root -> word = "";
            root -> isEOW = false;
        }

        char tempChar = board[currRow][currCol];
        board[currRow][currCol] = '#';
        vector<pair<int, int>> dirs({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});

        for(int i=0;i<4;i++)
        {
            int tr = currRow + dirs[i].first;
            int tc = currCol + dirs[i].second;

            if((tr < 0 || tr >= board.size()) || (tc < 0 || tc >= board[0].size()) || board[tr][tc] == '#') continue;

            search(board, root, result, tr, tc);
        }

        board[currRow][currCol] = tempChar;
    }

    vector<string> searchBoard(vector<vector<char>> &board, TrieNode *root)
    {
        int rows = board.size();
        int cols = rows == 0 ? 0 : board[0].size();

        vector<string> result;

        for(int i=0;i<rows;i++)
        {
            for(int j = 0; j < cols; j++)
            {
                search(board, root, result, i, j);
            }
        }

        return result;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode *root = new TrieNode();
        
        for(auto word : words) insertWord(root, word);

        return searchBoard(board, root);
    }
};
