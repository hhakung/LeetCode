class MinStack {
public:
    vector<pair<int, int>> m_minStack;
    
    MinStack() {
    }
    
    void push(int val) {
        if( m_minStack.empty() )
        {
            m_minStack.emplace_back( val, val );
        }
        else
        {
            auto const lastMin { m_minStack.back().second };
            m_minStack.emplace_back( val, val < lastMin ? val : lastMin );
        }
    }
    
    void pop() {
        m_minStack.pop_back();
    }
    
    int top() {
        return m_minStack.back().first;
    }
    
    int getMin() {
        return m_minStack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */