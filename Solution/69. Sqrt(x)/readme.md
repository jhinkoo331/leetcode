## 69. Sqrt(x)

### 题意解析

实现 `int sqrt(int x)`.

计算并返回`x`的平方根, 其中保证`x`是非负整数.

函数的返回值类型为`int`, 因此舍弃平方根的小数部分, 只返回整数部分.

Example 1:

> Input: 4
>
> Output: 2

Example 2:

> Input: 8
>
> Output: 2

### 题中需要注意的一些坑(即特殊情况)

* 0的平方根为0
* 1的平方根为1
* 平方根的结果会被截断, 例如2的平方约为1.414, 所返回的结果为1
* `INT_MAT`的平方根约为46340.9, 即对数值类型为`int`的数求平方是, $46340^2$不会溢出, 但是$46341^2$会导致溢出而产生难以预测的bug

## 解题过程

#### 1.直接采用C标准库函数实现: 即:

```cpp
#include <cmath>
int mySqrt(int x){
    return (int)pow(x, 0.5);
}
```

*Performance:*

> *Runtime: 4 ms, faster than 57.00% of C++ online submissions for Sqrt(x).*
>
> *Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Sqrt(x).*

很明显这不是我们刷Leetcode的初心...并且这样的做法并没有得到最佳的性能.

#### 2.遍历: 从0, 1, 2, 3...开始逐个检测, 找到满足平方小于等于`x`的最大整数, 即:

```cpp
int mySqrt(int x){
    int i = 1;
    while(i * i <= x) i++;
    // now `i` is the first number that i^2 exceeds x
    return i - 1;
}
```

这个方案简单好理解, 然而会出现错误, 数学上有$46340^2=2147395600$, 当`x=2147395600`时, `while`中的最后一轮循环中有`i=46341`,由于$46341^2=2147488281>INT\_MAX$, 因此产生了溢出导致错误.

一种解决方案是, 在函数的入口处, 检查x的值是否大于等于2147395600, 若大于该值, 则直接返回46340, 代码如下:

```cpp
class Solution {
public:
    int mySqrt(int x){
		if(x >= this->max_root_square)		// 直接返回max_root
			return this->max_root;
		int result = 1;
		while(result * result <= x) result++;
        // 现在result的值是第一个满足其平方值超过x的数值
		return result - 1;
	}
private:
	int max_root = 46340;
	int max_root_square = 2147395600;
};
```

*Performance:*

>*Runtime: 24 ms, faster than 6.87% of C++ online submissions for Sqrt(x).*
>
>*Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Sqrt(x).*

#### 3.尝试通过减少乘法运算的方式提升遍历的效率, 提升方案2的性能

如果不使用乘法不断得到0, 1, 2, 3...的平方值? 思考以下公式:
$$
1+3+5+...+(2n-1)=\frac{[1+(2n-1)]\times n}{2}=n^2
$$
以及:
$$
(n+1)^2-n^2=2n+1
$$
可以知道, 我们给$n^2$加上一个整数$2n+1$即可得到$(n+1)^2$, 代码即:

```cpp
int mySqrt(int x){
	int root = 1;
	int step = 3;
	unsigned square = 1;		// 防止int的溢出, 能够省去检查x是否大于max_root_square的过程
	while(square <= x){
		root++;
		square += step;
		step += 2;
	}
	return root - 1;
}
```

*Performance*

>Runtime: 32 ms, faster than 5.43% of C++ online submissions for Sqrt(x).
>
>Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Sqrt(x).

性能似乎更差了...心累, 这些网站感觉不太准

#### 4.采用二分查找的方法

主要思路:

设置`left`与`right`, 表明最终结果落在`[left, right]`之间, 每次迭代过程中计算`mid`的平方与参数`x`的关系, 确定下一个区间:

* `mid`的计算方式为`mid = (left + right) / 2`, 当`left`与`right`相邻时, 有`mid = left`, 当`left == right`时, 有`left == mid == right`.
* 当`left == right`时, `left`即为最终结果
* 当`left == right - 1`时, 可能使得`while`循环在此处发生死循环, 因此在这种情况下需要跳出循环, 依次检查`right`与`left`是否满足要求, 若`right`满足要求, 直接返回`right`.(因为需要返回较大的结果)

`left`与`right`初值的确定:

* `left`可直接设置为0

* `right`不能直接设置为`x`, 否则可能导致`mid`的值过大使得计算平方时出现溢出的情况, 可通过以下方式设置`right1初值避免该问题

	```cpp
	right = x < max_root ? x : max_root;
	```

实现代码:

```cpp
int mySqrt_4(int x){
		int left = 0, right = x < max_root ? x : max_root;
		while(left != right - 1 && left != right){	// ther are two conditions that this loop should be breaked.
			int mid = (left + right) / 2;
			if(mid * mid > x){
				left = left;
				right = mid - 1;
			}else{
				left = mid;
				right = right;
			}
		}
		if(right * right <= x)
			return right;
		else
			return left;
	}
```

*Performance:*

>*Runtime: 4 ms, faster than 57.00% of C++ online submissions for Sqrt(x).*
>
>*Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Sqrt(x).*

可以看到, 二分查找时这道题的一个表现较好的solution.



## todo

* 4.中的代码可以进一步优化