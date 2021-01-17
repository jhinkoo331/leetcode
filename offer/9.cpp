/**
 * @brief 99, 96
 */
class CQueue {
public:
        CQueue() {
                while(s.size())
                        s.pop();
                while(ss.size())
                        ss.pop();
        }
        
        void appendTail(int value) {
                s.push(value);
        }
        
        int deleteHead() {
                if(ss.empty())
                        while(s.size()){
                                ss.push(s.top());
                                s.pop();
                        }
                int ans = -1;
                if(ss.size()){
                        ans = ss.top();
                        ss.pop();
                }
                return ans;
        }
private:
        stack<int> s, ss;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */