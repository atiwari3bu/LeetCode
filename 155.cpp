class MinStack {
public:
    /* initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MinStack() {
        
    }
    
    void push(int x) {
        if(s2.empty() || s2.top()>=x){
            s2.push(x);
        }
        s1.push(x);
    }
    
    void pop() {
        if(s1.top()==s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
