#include <queue>
#include <deque>
using std::queue;
using std::deque;
/**
 * @brief 46, 26
 */
class MaxQueue {
public:
        MaxQueue() {
                while(q.size())
                        q.pop();
                while(max.size())
                        max.pop_back();
        }
        
        int max_value() {
                return max.size() ? max.front() : -1;
        }
        
        void push_back(int value) {
                q.push(value);
                while(max.size() && max.back() < value)
                        max.pop_back();
                max.push_back(value);
        }
        
        int pop_front() {
                if(q.empty())
                        return -1;
                if(q.front() == max.front())
                        max.pop_front();
                int temp = q.front();
                q.pop();
                return temp;
        }
private:
        queue<int> q;
        deque<int> max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */