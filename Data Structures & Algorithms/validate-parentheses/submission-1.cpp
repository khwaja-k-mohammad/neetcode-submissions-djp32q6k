class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            char currChar = s[i];

            if(st.size() == 0) st.push(currChar);
            else {
                char prevChar = st.top();
                if((currChar == ']' && prevChar == '[') ||
                   (currChar == '}' && prevChar == '{') ||
                   (currChar == ')' && prevChar == '(')
                ) {
                    st.pop();
                }
                else if(currChar == '{' || currChar == '(' || currChar == '[') st.push(currChar);
                else return false;
            }
        }

        return st.size() == 0;
    }
};
