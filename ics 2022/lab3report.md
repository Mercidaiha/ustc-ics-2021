## Lab3 Longest-duplicate-substring

PB20151793 宋玮

### 实验目的

输出给定string S中最长重复子串的长度：

例如 "aabbbc" 中最长子串长度为3.



### 实验思路

用 R2 存储 max 值（最长重复子串的长度）；

遍历一遍 string S，每次找到一个重复子串，将其长度与 max 比较；如果比 max 值大，则用该重复子串的长度替换 R2 中存储的 max 值.



### 实验过程

![image-20221211145941976](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211145941976.png)

①：初始化

②：主要循环体，遍历string S

③：找重复子串，每次将当前字符与前一个字符比较

④：将当前重复子串的长度与存储在 R2 的 max 值比较，大于则替换

⑤：存储最长重复子串的长度

 

### 实验结果

实验自测平台测评结果：

![image-20221211150434170](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211150434170.png)