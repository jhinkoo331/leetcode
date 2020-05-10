### 题意解析

实现`pow(double x, int n)`函数的功能

#### 首先, 在实现过程中我们需要注意以下几类特殊情况

* $x^n=0^0$,在数学中,有$\lim_{x \to 0}x^x=1$, 这种情况需要特殊考虑.
* 无论$x$等于多少, 只要$n=0$, 那么返回的值为$1$
* 当$n=2^{-31}$时,使用`abs()`函数获得$n$的绝对值得到的值依然是$2^{-31}$, 根据32位`int`的具体存储方式我们知道,`INT_MIN`的值为$2^{-31}$, 具体原因参考计算机如何给`int`取反

### 实现过程

采用两个*bool*变量记录`n`是否为`INT_MIN`以及`n`是否为负数

```cpp
#include <climits>
bool is_min = n == INT_MIN;
bool is_neg = n < 0;
```

若`n`小于0, 则需要将`n`首先转化为正数, 但是在前面我们提到过, 若`n == INT_MIN`则不能够直接使用`abs()`函数获得绝对值, 因此当`n == INT_MIN`时, 首先执行操作`n++`, 于是我们就可以使用`int`来保存`n`的绝对值了.

```cpp
#include <stdlib>		// abs()
if(is_min)
    n++;
n = abs(n);				// Now n is positive
```

接下来, 我们首先计算当`n = abs(n)`时的结果, 最直接的做法是采用一个循环解决, 即:

```cpp
int ret = 1;			// to store the result value.
while(n--){
    ret *= x;			// this line will be executed for n times
}
return ret;
```

方法非常好, 但是超时了! 当`x = INT_MAX`, 即$x=2^{31}-1$时, `ret *= x`需要执行超过20亿次, 很显然这道题目的关键在于降低时间复杂度, 而降低时间复杂度的关键则在于减少浮点运算(浮点运算是非常耗时的!)

如何降低该运算的次数呢? 仔细分析下面这个数学式子:
$$
x^{24}=x^{2 \times 12}=({x^2})^{12}=(x^2)^{2 \times 6}=[({x^2})^2]^6
$$
其中$x^{24}$次方需要执行24次浮点运算, 而$({x^2})^{12}$需要执行13次浮点运算, 即$x^2$执行一次, 计算$x^2$的12次方执行12次浮点运算, 一共$1+12=13$次运算, $[({x^2})^2]^6$则只需要执行8次浮点运算.

这提示我们可以利用二进制的表示机制来加快运算过程, 例如对于$3^{13}$次方我们有:

* 13表示为二进制为: `1101`
* 其中第一位`1`所代表的值为8, 即$3^8=6561$
* 第二个的`1`所代表的的值为4, 即$3^4=81$
* 第三位的`0`所占"权重"为2, 但是因为是0, 所以对结果无影响
* 第四位的`1`所代表的值为1, 即$3^1=3$
* 最终结果为各个数位上所代表的结果的乘积, 即$6561\times 81 \times 3=1594323$

结合`int`占32位, 其中最高位为符号位, 剩余31位为数值位. 其中从最低位到最高位, 分别对应的值为$x$, $x^2$, $x^4$, $x^8$, ..., $x^{2^{30}}$, 我们使用一个`int data[31]`来保存这些数值, 即:

```cpp
int data[31];
data[0] = x;			// represent the last digit in the binary code n
for(int i = 1; i < 32; i++)
    // every digit's weight is the square of the digit right besides it 
    data[i] = data[i - 1] * data[i - 1];
```

如果将`int data[31]`内保存的数值如下:

| 0    | 1       | 2       | 3       | 4          | ...  | 29             | 30             |
| --- | ---- | ---- | ---- | ------ | ---- | ------ | ----- |
| $x$  | $$x^2$$ | $$x^4$$ | $$x^8$$ | $$x^{16}$$ | ...  | $$x^{2^{29}}$$ | $$x^{2^{30}}$$ |

随后我们只需要根据`n`的二进制码中为1的位所对应的值相乘即可得到最终结果, 即:

```cpp
double ret = 1;					// 用于存放我们最终返回的结果, 即pow()函数的返回值
unsigned temp = 1;					// 用于与n的"与"操作以检测某个特定的位是否1
for(int i = 0; i < 32; i++){	// 分别检测32个bit是否为1
    if(n & temp){
        ret *= data[i];
    }
    temp *= 2;					// temp左移1 bit
}
```

这时候我们得到的`ret`的值为对`n`取绝对值后得到的值, 需要进一步操作得到原始`n`对应的最终结果:

```cpp
if(is_min)
	ret *= x;			// ! we let n plus 1 before
if(is_neg)				//! if the exponent is negative
	ret = 1 / ret;
return ret;
```

最后得到的`ret`即所得的最终结果.

### 性能分析

Leetcode中的性能排名:

> Runtime: 12 ms, faster than 12.71% of C++ online submissions for Pow(x, n).
>
> Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Pow(x, n).

##### 空间复杂度

常数$O(1)$, 当然这道题也可以不使用`data[]`数组, 而是使用一个`int`来表示每个位代表的"weight", 但是没有用数组来的直观.

##### 空间复杂度

常数$O(1)$, 计算`data[]`数组需要约30次浮点运算, 计算最终结果需要约30次移位(对temp的修改)以及最多约30次的浮点运算(修改ret的值)



