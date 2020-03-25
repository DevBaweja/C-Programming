//Headers files standard C library//also putw() for integers//also getw() for intergers
stdio.h   (standard input/output)
1. scanf("%format specifiers",address of variable);
use to scanf char,int,float,string
in case of variales use (&variable) and in case of arrays(use array name) and pointers use their addresses
for string also use string name (as it is also array name)

2. printf("%format specifiers",variable name);
use to print onto output screen char %c,int %d,float %f,string %s

using %.2f to minimize the float expression to only 2 decimal place

3. getchar(void) and getch(void) // both are same as inside of both is empty
it read characters from keyboard
getchar() is included in standard function of stdio.h but getch() is not standard function of stdio.h(included in conio.h)
getch() takes one single input and dont display it on the screen 
misuseded as "holding" the output screen will be hold untill any key from keyboard is pressed
getchar() takes single character and  display it to the screen

4. putchar(character variable name)
it print single character to the screen which was stored in variable
/* getchar(void) and putchar(variable name) are like scanf and printf for single characters only
in which scanf store it in variable address getchar(void) store it as char ch;   ch=getchar();
and whenever we want to printf just putchar(ch) will do work of printf for single characters */

5. gets(string name) 
it read string from keyboard and store it to the string declared

6. puts(string name) 
it print saved string to output screen
/* gets(string name) and puts(string name) are scanf and printf for line gets will save the line written by keyboard in string name 
and puts will printf the line saved in string name */


9. fopen()
10. fclose()
11. fscanf()
12. fprintf()
13. getc() from file // getw() read intergers from file
14. putc() to file // putw() write interger to file
