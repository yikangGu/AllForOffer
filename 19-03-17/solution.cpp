class Solution
{
public:
	int max_in(queue<int> in){
        queue<int> back(in);
        int max_ret = INT_MIN;
        while(!back.empty()){
            max_ret = max(max_ret, back.front());
            back.pop();
        }
        return max_ret;
    }
    
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        queue<int> buf;
        vector<int> ret;
        if(num.size()<size || size == 0){
            return ret;
        }
        for( const auto n : num){
            buf.push(n);
            while(buf.size()>size){
                buf.pop();
            } 
            if(buf.size()==size){
                ret.push_back(max_in(buf));
            }
        }
        return ret;
    }

    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp,ret;
        while(!stack1.empty()){
            temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }
        if(!stack2.empty()){
            ret = stack2.top();
            stack2.pop();
        }
        while(!stack2.empty()){
            temp = stack2.top();
            stack1.push(temp);
            stack2.pop();
        }
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
