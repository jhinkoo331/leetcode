# when we calculating the mid number of `left` and `right`, we need to avoid overflow.
In this way, `left` + `right` may fields a `int32` overflow.

```c
int left = x, right = y;
int mid = (left + right) / 1;
```

This method would avoid this hazard:
```
int mid = (right - left) / 2 + left;
```