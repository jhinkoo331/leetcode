#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool _1(){
        int sz, sum;
        scanf("%d%d", &sz, &sum);
        priority_queue<int> q1;
        priority_queue<int, vector<int>, std::greater<int>> q2;
        int temp;
        for(int i = 0; i < sz; ++i){
                scanf("%d", &temp);
                q1.push(temp);
        }
        for(int i = 0; i < sz; ++i){
                scanf("%d", &temp);
                q2.push(temp);
        }
        while(q1.size()){
                if(q1.top() + q2.top() > sum)
                        return false;
                q1.pop();
                q2.pop();
        }
        return true;
}


int main(){
        int n;
        scanf("%d", &n);
        while(n--)
                printf(_1() ? "Yes\n" : "No\n");
        return 0;
}

