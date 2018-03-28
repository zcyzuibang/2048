# 2048
 1.0
作者：张长宇
时间：2018-03-24
版本：1.0
代码功能：实现一个控制台操作的2048小游戏。（其中w、s、a、d分别操控向上、向下、向左、向右合并操作）
收获：a是系统关键字，不能做函数名；
算法：w、s、a、d操作对应的函数为www、sss、aaa、ddd；其中其实上下操作实现比较相似，区别为www将a[i][]向a[i][0]靠拢，sss将a[i][]向a[i][3]靠拢，所以实际代码中www和sss知识将0、1、2、3对应替换为3、2、1、0；aaa操作则是将www操作的行列坐标交换；ddd与aaa的关系操作与www与sss的关系相似。
改进思路：将a、s、d操作用w操作来实现。具体做法为将数组整体旋转之后执行w操作，再将数组旋转回去即可，只需新建一个数组c，添加一个将数组中的a[i][j]一一赋值给c[j][i]的函数即可实现大量代码重用。