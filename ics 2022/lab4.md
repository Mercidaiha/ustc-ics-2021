## Lab04 Sort and Count

### 实验目的

1. 对给定的16位学生的成绩进行排序，并将排序结果存储至以x5000为起始地址的内存空间.

2. (1) If a student scores 85 or above and is in top 25%, he/she will receive an A.

​		(2) If he/she does not get an A but scores 75 or above and is in top 50%, he/she will get a B.

​		将得A的学生数存储至x5100.

​		将得B的学生数存储至x5101.



### 实验思路

1. 排序算法采用冒泡排序，交换位置采用 load & store 指令

2. 将在原址排好序的16个数，利用 store 指令存储至以x5000为起始地址的内存空间

3. 遍历排好序的前 **4** 个学生，若其分数大于 85 分，则 NUM_A ++

4. 遍历排好序的前 **8** 个学生，若其分数大于 75 分，则 NUM_(A+B) ++

   遍历完成后，将 NUM_(A+B) 减去 NUM_A 即可得 NUM_B



### 实验过程

(1)

![image-20221211152151134](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211152151134.png)

NA和NB是用于判断分数是否大于85和75

STUDENT是表示学生数量，16



(2)

![image-20221211152346548](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211152346548.png)

初始



(3)

![image-20221211152457346](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211152457346.png)

①：利用冒泡排序进行sorting

​		每次冒泡，将一个最大值冒泡至末尾；

​		交换位置采用 STR 指令，直接在原址内存空间交换位置

②：存储排序结果



(4)

![image-20221211152837861](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211152837861.png)

![image-20221211152853794](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211152853794.png)

计算 NUM_A 和 NUM_(A+B)，并得到 NUM_B



### 实验结果

自测平台输出结果

![image-20221211153045911](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221211153045911.png)