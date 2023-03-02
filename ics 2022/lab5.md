# Lab 5：Tower of Hanoi

PB20151793 宋玮

#### How do you work out the algorithm?（实验思路）

整个算法包括三部分，其中**The operating system enabling code**已经由助教写好；



因此只需完成两部分，一个是用户程序，包括：

1.持续输出“PB20151793”；

2.延迟算法；

3.Hanoi算法；

4.二进制转ascii码算法



另一个是中断程序，包括：

1.判断输入 N 是否满足要求，并输出相应提示结果；

2.将符合的 N 存入相应位置



#### How do you write the program？（实验过程）

##### 中断程序

![image-20221222201312775](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222201312775.png)

![image-20221222201439513](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222201439513.png)

.ORIG x1000

从 KBDR 中取出输入的 N，判断其ascii码数值是否处于 48~57 之间；

如果在此区间，则是一个十进制整数，符合输入要求，输出相应提示，并将 N 存储在 x3FFF 处

如果不在此区间，则不符合要求，输出相应提示



##### 用户程序

1.利用合适的延迟持续打印学号“PB20151793”，直至 N 有效，跳出打印循环；

（1）

![image-20221222202011150](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222202011150.png)

（2）

![image-20221222202305213](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222202305213.png)

（3）

![image-20221222202414431](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222202414431.png)





2.计算 Tower of honoi 的移动次数，采用递归程序：

（1）设置合理用户栈起始处，并调用 HANOI 函数

![image-20221222202658512](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222202658512.png)

（2）

![image-20221222202558215](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222202558215.png)





3.二进制数转十进制ascii码输出：

（1）调用

![image-20221222202812840](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222202812840.png)

（2）

![image-20221222202913121](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222202913121.png)

![image-20221222203129415](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222203129415.png)



 

#### How do you design your own test cases to ensure the program works fine?（实验结果）

（1）输入3

![image-20221222203542597](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222203542597.png)



（2）输入7

![image-20221222203416301](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222203416301.png)



（3）输入k，接着输入1

![image-20221222203659190](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221222203659190.png)