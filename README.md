# MeaningfulCode

I tossed about my antique computer again recently, I found the code written during the summer vacation of my freshman year by chancea, and I ran it with a boring mentality and found that it was quite interesting. Although the program design is relatively immature, it is because it was my first project to write. The thousands of lines of code that came out are quite commemorative, so I decided to put it in my github warehouse to make dust.
## Cause:
The next semester has just finished learning the C language, and then we have a curriculum design task, that is, a group uses the C language course completed this semester to write a decent thing, since none of my roommates seem to be very interested in programming, I took on the most important task.
## process
It was the summer vacation. I decided to make good use of this holiday. First of all, the overall program framework design, at that time, I designed the library management system model, after the code was written, I was decisive in order to prevent duplication with other groups, change the system in the library to a bank loan system (this is faster, only need to change the logic rules of the code), so you can see that the code comments I uploaded are still the comments of the system in the library (I was too lazy to change the comments at the time). The overall program framework design of the bank lending system is as follows:
![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/0.png)

Next, the function points on the code will be implemented programmatically. I still remember that the process of program implementation was not smooth, it is worth noting that I wrote all nearly a thousand lines of code in a C language file at that time, ( Now let’s look at the actions at that time, there are many unexpected bugs in nearly a thousand lines of code, thinking about it, my scalp is numb.) however, with extreme patience, I slowly sorted out the bugs in the thousand lines of code. The bank lending system that has to be done is finished.
## Simple instructions:
The code is implemented in pure C language, so you only need to clone the project code, and then open the bank.c file with the C meter editor, where the login name and password are in the 9_6.txt file, and 9_7.txt is stored a loan product of the bank, 9_8.txt stores the bank's user loan records, and 9_10.txt stores the literary game word solitaire text library.
The operation process is as follows:
1.	run bank.c

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/1.png)

2. Enter password and username

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/2.png)
 
3. Try the results of different options
   
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-1.png)
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-2.png)
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-3.png)
 ![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/3-4.png)

4. User management interface related options

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/4.png)

5. I personally feel that the logic game design inside is a bit interesting, you can design different calculation difficulties by changing the code, elementary school students can perform double-digit calculations, and middle and high school can adjust to five-digit or higher calculations, and the calculation is nested in the calculation (every time an answer is correctly calculated, the system will automatically assign an additional time or subtract time operation, and finally this reward and punishment time is counted as a comprehensive time, and finally a final time is given), I remember that I played this with my three younger siblings who were in elementary school and junior high school, they all played well, and there are their statistical records on it.

![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/5.png)

6. The literary game is also good, it can consolidate the children's ability of ancient Chinese poetry, but you need to add your own ancient poetry text library in the 9_10.txt file.
 
![image](https://github.com/GreenEli/MeaningfulCode/blob/main/Pic/6.png)
