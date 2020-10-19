#include "util\frequently_included.h"

/**
 * @brief this solution is a general choice if the given numbers
 * @brief have no restriction or distribution pattern.
 * @perf: 87, 6
 * 
 */
class _1{
public:
        /** initialize your data structure here. */
        _1() {}
        /**
         * @brief elements in small is all smaller or equal to the minium element in big,
         * @brief small.size() == big.size() or small.size() = big.size() + 1 should be maintained.
         */
        void addNum(int num){
                if(small.size() == big.size()){ // insert into small
                        if(big.empty() || num <= big.top())
                                small.push(num);
                        else if(big.top() < num){
                                small.push(big.top());
                                big.pop();
                                big.push(num);
                        }
                } else {                        // insert into big
                        if(num >= small.top())
                                big.push(num);
                        else {
                                big.push(small.top());
                                small.pop();
                                small.push(num);
                        }
                }
        }
        double findMedian(){
                if(small.empty())
                        return 0;
                else if(small.size() > big.size())
                        return small.top();
                else
                        return ((float)(small.top() + big.top())) / 2;
        }
private:
        priority_queue<int> small;
        priority_queue<int, vector<int>, std::greater<int>> big;
};

class MedianFinder {
public:
        /** initialize your data structure here. */
        MedianFinder() {
                shadow = new _1();      
        }
        
        void addNum(int num) {
                shadow->addNum(num);
        }
        
        double findMedian() {
                return shadow->findMedian();
        }
private:
        _1* shadow;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
        MedianFinder mf;
        vector<int> v{6,10,2,6,5,0,6,3,1,0,0};
        for(auto e: v){
                mf.addNum(e);
                printf("%f\n", mf.findMedian());
        }
        return 0;
}
