class MyQueue {
public:
    // MyQueue() {
        
    // }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        const int peeker = peek();
        const int val=output.top();
        output.pop();
        return val;
    }
    
    int peek() { // top of queue will be whatever is bottom of input stack
        if(output.empty()) // if output array is empty
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        // if(input.isempty() && output.isempty())
        // {
        //     retur false;
        // }
        // else
        // {
        //     return true;
        // }
        return input.empty() && output.empty();
        // gives true or false
    }

    public:
    stack<int> input;
    stack<int> output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */