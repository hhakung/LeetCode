class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        m_size = k;
        m_circularQueue.resize( m_size );
        m_head = -1;
        m_tail = -1;
    }
    
    bool enQueue(int value) {
        if( isFull() )
        {
            // queue is full
            return false;
        }
        else
        {
            if( m_head == -1 )
            {
                ++m_head;
            }
            
            m_tail = (m_tail + 1) % m_size;
            m_circularQueue[m_tail] = value;
            
            return true;
        }
    }
    
    bool deQueue() {
        if( isEmpty() )
        {
            // queue is empty
            return false;
        }
        else
        {
            if( m_head == m_tail )
            {
                m_head = -1;
                m_tail = -1;
            }
            else
            {
                m_head = (m_head + 1) % m_size;
            }
            
            return true;
        }
    }
    
    int Front() {
        return (m_head == -1 ) ? -1 : m_circularQueue[m_head];
    }
    
    int Rear() {
        return (m_tail == -1) ? -1 : m_circularQueue[m_tail];
    }
    
    bool isEmpty() {
        return (m_head == -1) && (m_tail == -1);
    }
    
    bool isFull() {
        return ((m_tail + 1) % m_size) == m_head;
    }
    
private:
    vector<int> m_circularQueue;
    int m_size;
    int m_head;
    int m_tail;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */