class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }
    
    void push(int x) {
        if(q1.empty()){
            // push x and then whole q2 to it
            q1.push(x);

            while(!q2.empty()){
                int t = q2.front();
                q1.push(t);
                q2.pop();
            }
        }else if(q2.empty()){
            q2.push(x);

            while(!q1.empty()){
                int t = q1.front();
                q2.push(t);
                q1.pop();
            }
        }
    }
    
    int pop() {
        if(!q1.empty()){
            int t = q1.front();
            q1.pop();
            return t;
        }else if(!q2.empty()){
            int t = q2.front();
            q2.pop();
            return t;
        }

        return 0;
    }
    
    int top() {
        if(!q1.empty()){
            int t = q1.front();
            
            return t;
        }else if(!q2.empty()){
            int t = q2.front();
            
            return t;
        }

        return 0;
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */