class Solution {
public:
    
    int evalRPN(vector<string> &tokens) {
        stack<int> numbers;
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int a = numbers.top();
                numbers.pop();
                int b = numbers.top();
                numbers.pop();
                if(token == "+") numbers.push(b+a);
                if(token == "-") numbers.push(b-a);
                if(token == "*") numbers.push(b*a);
                if(token == "/") numbers.push(b/a);
            }
            else
                numbers.push(stoi(token));
        }
        return numbers.top();
    }
};
