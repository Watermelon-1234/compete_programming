【模板】計算幾何
===

## Default Code
```cpp=
typedef pair<int,int> vec;
vec operator - (vec p){ return {-p.ff, -p.ss}; }
vec operator + (vec p, vec q){ return {p.ff+q.ff, p.ss+q.ss}; }
vec operator - (vec p, vec q){ return {p.ff+q.ff, p.ss+q.ss}; }
vec operator * (vec p, int q){ return {p.ff*q, p.ss*q}; }
vec operator / (vec p, int q){ return {p.ff/q, p.ss/q}; }
int cross (vec p, vec q){ return p.ff*q.ss - p.ss*q.ff; }
int dot   (vec p, vec q){ return p.ff*q.ff + p.ss*q.ss; }
int abs2 (vec p){ return dot(p,p); }
double abs (vec p){ return hypot(p.ff,p.ss); }
```

## 常用

### 內積定義、正弦定理、夾角
```
cross(v1,v2) = abs(v1)*abs(v2)*sinθ
dot(v1,v2) = abs(v1)*abs(v2)*cosθ
```
* 用 `asin` 可以 `acos` 算出弳度

```
dot(v1,v2) < 0, θ < 90
dot(v1,v2) = 0, θ = 90
dot(v1,v2)  > 0, θ > 90

cross(v1,v2) > 0, v1 到 v2 逆時針
cross(v1,v2) = 0, v1 平行 v2
cross(v1,v2) < 0, v1 到 v2 順時針
```
* 粗估順逆時針、夾角大小

### 點到直線距離

![](https://i.imgur.com/HCmJ9Xb.png)
```
點到直線距離 = cross(v1,v2)/abs(v2)
```

###### tags: `競程` `模板` `數學`