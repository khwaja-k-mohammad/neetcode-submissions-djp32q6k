class Solution {
    /**
     * @param {string[]} tokens
     * @return {number}
     */
    evalRPN(tokens) {

        const stack = [];
        for(let i=0;i<tokens.length;i++)
        {
            if(tokens[i] == '*' || tokens[i] == '/' || tokens[i] == '+' || tokens[i] == '-') 
            {
                const operand1 = stack.pop();
                const operand2 = stack.pop();

                switch(tokens[i])
                {
                    case "*": stack.push(operand2 * operand1);
                                break;
                    
                    case "/": let val = operand2 / operand1;
                              stack.push(parseInt(val));
                              break;

                    case "+": stack.push(operand2 + operand1);
                                break;

                    case "-": stack.push(operand2 - operand1);
                                break;
                }
            }
            else stack.push(Number(tokens[i]));
        }

        return stack.at(-1);
    }
}
