class MyQueue {
public:
    //queue hai jo pehle aaya hai wo pehle rahega
    //s1 me element normal stack ki tarah dalte rahenge
    //jab queue se nikalna hoga --> tb s1 ke elements ko ulta karke s2 me dal denge isse jo sabse pehle aaya rha wo s2 ke top me aa jaega wahi queue ka front hai


    //s1---------------------->storage
    //s2---------------------->reversing machine

    stack<int>s1,s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    //
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        //same as the top but without removing it
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */