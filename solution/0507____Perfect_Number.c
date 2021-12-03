#include <stdbool.h>
#include <math.h>


bool _1(int num){
        if(num <= 1)
                return false;
        int root = sqrt(num);
        int sum_of_divisors = 1;
        for(int i = 2; i < root; ++i)
                if(num % i == 0)
                        sum_of_divisors += i + num / i;
        if(root * root == num)
                sum_of_divisors -= root;
        return sum_of_divisors == num;
}


bool checkPerfectNumber(int num){
        return _1(num);
}

int main(){
        checkPerfectNumber(28);
        return 0;
}