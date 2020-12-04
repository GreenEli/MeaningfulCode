# MeaningfulCode

最近又折腾了一下我的古董级电脑，偶然找到大一暑假时写的代码，本着无聊的心态跑一下，发现还挺有意思的，虽然程序设计比较稚嫩，但由于毕竟是我第一个写出来的还有点样子的千行代码，还挺有纪念意义的，于是决定把它放在我的github仓库中生灰。
## 起因：
大一下学期刚刚学完C语言，然后我们有一个课程设计的任务，就是一个小组利用这学期学完的C语言课程写一个像点样的东西出来。由于我的室友们似乎都对编程都不大感兴趣，所以我就担负了这重中之重的攻坚任务。
## 经过
当时正值放暑假，我决定好好利用这个假期把这个东西搞出来，首先是整体的程序框架设计，当时设计的是图书管理系统模型，代码写完后，为防止与其他小组做的重复，果断将图书馆里系统改成银行借贷系统（这个比较快，只需要改变一下代码的逻辑规则即可），所以可以看到我上传的代码注释还是图书馆里系统的注释（当时懒得改注释）。银行借贷系统的程序总体框架设计如下所示：
![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/0.png)
接下来就对代码上的功能点进行程序化实现，我现在仍旧记得，程序实现的过程并不顺利，值得注意的是当时我把所有的近千行代码都写在一个c语言文件里，（现在看看当时的举动，在近千行代码里排很多预想不到的bug，想想真是头皮发麻），然而当时我凭着极其的耐性慢慢在千行代码里排bug，终于一个还看得过去的银行借贷系统做完了。
## 简单使用说明：
代码是采用纯C语言实现的，所以大家只需要将本项目代码clone下来，然后用C计编辑器打开bank.c文件即可，其中登录名和密码在9_6.txt文件中，9_7.txt存放的是银行的借贷产品，9_8.txt存放的是银行的用户借贷记录，9_10.txt存放的是文艺游戏词语接龙文本库。
运行过程如下：
1.	运行bank.c

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/1.png)

2.	输入密码和用户名

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/2.png)
 
3.	试试不同选项产生的结果
   
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-1.png)
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-2.png)
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-3.png)
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-4.png)

4.	用户管理界面相关选项

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/4.png)

5.	个人感觉里面的逻辑游戏设计的还有点意思，可以通过改动过代码设计不同的计算难度，小学生可以进行双位数运算、初高中可以调节到五位数或者更高位数之间的运算。且计算中嵌套计算（每正确计算出一个答案，系统会自动分配一个加时或减时的时间操作，最终把这种奖惩时间算上得到一个综合时间，最后给出一个最终时间），我记得当时我给我正在读小学和初中的三个弟妹玩这个，他们都玩的不错，上面还有他们的统计记录

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/5.png)
![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/5-1.png)

6.	文艺游戏也不错，可以巩固小朋友的语文古诗词能力，但需要自己在9_10.txt文件中添加自己的古诗词文本库。
 
![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/6.png)
