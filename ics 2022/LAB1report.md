# LAB1

PB20151793 宋玮



## 实验目的

给定数字$A$和$B$，求出$A$的低$B$位共有几个1.

> 初始，$A$存储在`x3100`，$B$存储在`x3101`；将结果存储在`x3102`.



## 实验思路

**1. 要验证$A$的某一位是否为`1`，可采用`AND`指令，将$A$与特定数进行与操作；利用结果来判断该位是否为`1`.**

​		**例如：**判读$A$的第0位是否为`1`，可将$A$与`x1`进行`AND`操作，若结果为0，则表示A的第0位为					`0`；否则，A的第一位为`1`.

​					同理，判断$A$的第2位是否为`1`，可将A与`x8`进行`AND`操作，若结果为0，则表示A的第					0位为`0`；否则，A的第一位为`1`.

**2. 用$B$的值来控制循环次数，每次循环判断1位；循环$B$次，得到结果.**



## 实验过程

该程序的机器码如下：

![image-20221104200117266](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221104200117266.png)

**程序开始于`x3000`；**

**从`x3100`处取得$A$值，存放在$R1$中；**

**从`x3101`处取得$B$值，存放在$R2$中；**

**每次循环利用$R4$和$R1(A)$进行`AND`操作，来判断该位是否为`1`；**

**共循环$R2(B)$次；**

**结果存储在$R6$中；**

**因此最后将$R6$的值`store`进`x3102`即可.**



## 实验结果

##### **（1）$A = 13 ; B=3$**

![image-20221104201802406](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221104201802406.png)



​		$Output = 2$

![image-20221104201926493](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221104201926493.png)





##### **（2）$A = 167 ; B=6$**

![image-20221104202049375](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221104202049375.png)



​		$Output = 4$

![image-20221104202307860](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221104202307860.png)





##### （3）$A = 32767 ; B=15$

![image-20221104202449931](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221104202449931.png)



​		$Output = 15$

![image-20221104202549434](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221104202549434.png)