class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" || tokens[i] == "-")
            {
                int operand1 = s.top();
                s.pop();
                int operand2 = s.top();
                s.pop();

                if(tokens[i] == "+") s.push(operand2 + operand1);
                else if(tokens[i] == "-") s.push(operand2 - operand1);
                else if(tokens[i] == "*") s.push(operand2 * operand1);
                else s.push(operand2 / operand1);
            }
            else s.push(stoi(tokens[i]));
        }

        return s.top();
    }
};
