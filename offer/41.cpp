/**
 * @brief [99, 99]
 * 
 */
class MedianFinder {
public:
        /** initialize your data structure here. */
        MedianFinder() {
                while(left.size())
                        left.pop();
                while(right.size())
                        right.pop();
                left.push(0x80000000);          // to make sure the both pq not empty
                right.push(0x7fffffff);
        }
        void addNum(int num) {
                if(left.size() == right.size())
                        if(num <= right.top())
                                left.push(num);
                        else {
                                left.push(right.top());
                                right.pop();
                                right.push(num);
                        }
                else
                        if(num >= left.top())
                                right.push(num);
                        else{
                                right.push(left.top());
                                left.pop();
                                left.push(num);
                        }
        }
        
        double findMedian() {
                if(left.size() == right.size())
                        return float(left.top() + right.top()) / 2;
                else
                        return left.top();
        }
private:
        priority_queue<int, vector<int>, less<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */