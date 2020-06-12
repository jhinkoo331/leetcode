

### Maximum Subarray

#### 方法1: 暴力求解

令`vector<int> nums`的长度为`sz=n`, 取两个整形变量`left`与`right`分别表示子串的最左和最右元素, 则一共需要check的情况为:
$$
n+(n-1)+(n-2)...+1=\frac{n\times (n+1)}{2}=O(n^2)
$$
即时间复杂度为$O(n^2)$ ? 实际上未必, 因为我们对于长度不同的子串, 所需要执行的操作步数不一致, 对于长度为$k$的子串, 需要执行约$k$次相加与比较操作, 即实际的时间复杂度计算公式为:
$$
n\times 1+(n-1)\times 2+(n-2)\times 3...+1\times n=[n+2n+3n+...n\times n]-[0\times 1+1\times2+2\times 3+...+(n-1)\times n]
$$


### 性能

>Runtime: 8 ms, faster than 50.22% of C++ online submissions for Maximum Subarray.
>
>Memory Usage: 13.2 MB, less than 5.88% of C++ online submissions for Maximum Subarray.