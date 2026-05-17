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
                const operand1 = stack.at(-1);
                const operand2 = stack.at(-2);

                stack.pop();
                stack.pop();

                switch(tokens[i])
                {
                    case "*": stack.push(operand2 * operand1);
                                break;
                    
                    case "/": let val = operand2 / operand1;
                              val = (val < 0) ? Math.ceil(val) : Math.floor(val);
                              stack.push(val);
                              break;

                    case "+": stack.push(operand2 + operand1);
                                break;

                    case "-": stack.push(operand2 - operand1);
                                break;
                }
            }
            else stack.push(Number(tokens[i]));

            console.log(stack.at(-1));
        }

        return stack.at(-1);
    }
}
