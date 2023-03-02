## Lab6 Learn from the past

PB20151793 宋玮

### 实验目的

用高级语言（C/C++）重现 lab1~lab4.



### 实验原理

可以根据每一条LC3机器码或者汇编指令，用相应 C/C++ 语句重现；

也可以根据整体逻辑，用 C/C++ 框架实现，比如 ”冒泡排序“ 等



### 实验过程

首先 lab1，lab2，lab3的 C++ 程序都是根据 LC3 每条指令来实现的；

例如 lab1：

定义变量 r1~r6，对应于 LC3 中的六个寄存器，result是最后结果；

初始化

```c++
// initialize	
	int16_t r0, r1, r2, r3, r4, r5, r6, result;
	r0 = 1;
    r1 = a;
    r2 = b;
    r3 = 0;
    r4 = 0;
    r5 = 0;
    r6 = 0;
```

接着根据 LC3 每条指令，利用相应简单 C++ 语句编写；

```c++
// calculation
    if(r2 <= 0){
        result = r6;
    }
    else{
        while(r2 > 0){
            r4 = r0;
            r3 = r2 - 1;
            while(r3 > 0){
                r4 = r4 + r4;
                r3 = r3 - 1;
            }
            r5 = r4 & r1;
            if(r5 != 0){
                r6 = r6 + 1;
            }
            r2 = r2 - 1;
        }
        result = r6;
    }
```

最后返回结果；

```c++
// return value
    return result;
```

lab2和lab3是类似思路编写；





但是对于lab4，涉及到经典的冒泡排序和筛选符合值，这里摒弃了 LC3 的实现逻辑；直接利用了高级语言中的实现思路；

冒泡排序；

```c++
	for(int i=15; i>0; i--){
        for(int j=0; j<i; j++){
            if(score[j] > score[j+1]){
                int16_t temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    }
```

筛选符合值，即：得A 和得B 的学生数；

```c++
	for(int i=12; i<16; i++){
        if(score[i] >= 85){
            result_a = result_a + 1;
        }
    }
    for(int i=8; i<16; i++){
        if(score[i] >= 75){
            result_ab = result_ab + 1;
        }
    }
    result_b = result_ab - result_a;
```

最后返回结果即可



### 实验结果

由于本次实验采用的是助教提供的框架，因此以下展示的是利用“test.txt”测试的结果：

![image-20221223210810253](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20221223210810253.png)





### 思考题答案

What is the difference between programming in a high-level language and programming in LC3 assembly language?

**LC3汇编语言指令少，而且实现的是最基础的功能，易于底层机器的实现；**

**高级语言，顾名思义，建立在这之上，拥有更多的使用方式以及功能，灵活，易于程序员编写。**

What instructions do you think need to be added to LC3? (Hint: You can think about the previous labs and what instructions could be added to greatly simplify the previous programming)

**乘法指令和取模运算指令**

Is there anything you need to learn from LC3 for the high-level language you use?

**使用高级语言的时候往往会忽略这些高级语言的底层实现，LC3相当于让我了解了最底层的，便于机器实现的语句构造**