class MinStack {
public:
    stack <int> s1;
    stack <int> s2;

    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if (s2.empty()) s2.push(val);
        else {
            if (s2.top() >= val) s2.push(val);
        }
    }
    
    void pop() {
        int x = s1.top();
        s1.pop();
        if (s2.top() == x) s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
