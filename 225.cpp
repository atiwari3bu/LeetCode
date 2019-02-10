class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int size;
    MyStack() {
        this->size=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        ++(this->size);
        if(this->size>1){
            int max=this->size;
            for(int i=1;i<max;++i){
                int front=q.front();
                q.pop();
                q.push(front);
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front=q.front();
        --(this->size);
        q.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(this->size<=0) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
