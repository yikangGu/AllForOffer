class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> numbers;
        if(tokens.size() == 0)
            return 0;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                int rightNumber = numbers.top();
                numbers.pop();
                int leftNumber = numbers.top();
                numbers.pop();
                int result = rightNumber + leftNumber;
                numbers.push(result);
            }
            else if(tokens[i] == "-")
            {
                int rightNumber = numbers.top();
                numbers.pop();
                int leftNumber = numbers.top();
                numbers.pop();
                int result = leftNumber - rightNumber;
                numbers.push(result);
            }
            else if(tokens[i] == "*")
            {
                int rightNumber = numbers.top();
                numbers.pop();
                int leftNumber = numbers.top();
                numbers.pop();
                int result = rightNumber * leftNumber;
                numbers.push(result);
            }
            else if(tokens[i] == "/")
            {
                int rightNumber = numbers.top();
                numbers.pop();
                int leftNumber = numbers.top();
                numbers.pop();
                int result = leftNumber / rightNumber;
                numbers.push(result);
            }
            else
                numbers.push(atoi(tokens[i].c_str()));
        }
         
        return numbers.top();
    }
};