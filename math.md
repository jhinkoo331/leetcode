## 数学基础
#### 1. gcd
* 给定正整数$x$, 返回二者的最大公因数

* 有人喜欢用递归方式, 但是那样效率很低

  ```go
  func gcd(i, ii int) int {
  	for i%ii != 0 {
  		i, ii = ii, i%ii
  	}
  	return ii
  }
  ```

#### 2. 裴蜀定理

* $a$, $b$互质的充要条件是存在整数$x$, $y$使得$ax+by=1$
* 来自leetcode 1250题
