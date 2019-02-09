class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> my_stack;
    int size;
    MyQueue() {
        this->size=0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        my_stack.push(x);
        ++(this->size);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        vector<int> buffer;
        for(int i=0;i<this->size;++i){
            buffer.push_back(my_stack.top());
            my_stack.pop();
        }
        --(this->size);
        for(auto riter=buffer.rbegin()+1;riter!=buffer.rend();++riter){
            my_stack.push(*riter);
        }
        return *(buffer.rbegin());
    }
    
    /** Get the front element. */
    int peek() {
        vector<int> buffer;
        for(int i=0;i<this->size;++i){
            buffer.push_back(my_stack.top());
            my_stack.pop();
        }
        for(auto riter=buffer.rbegin();riter!=buffer.rend();++riter){
            my_stack.push(*riter);
        }
        return *(buffer.rbegin());
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(this->size<=0)
            return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
