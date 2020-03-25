#stacks 
enter and exit form same corner
#stacks using arrays
top as int is maintained
#stacks using linked list 
head pointer is maintained
#queues
enter from rear and exit from front 
#queues using arrays
front and rear as int is maintained
#queues using linked list
head and rear as pointer is maintained
#circular queues

#postfix
(infix to postfix)
if operant the directly
if operator the push into stack using precedent of operator 
high or equal precedents can be directly pushed 
if lower precedents push untill equal or higher precedents operators comes and push it
in the end empty stack
(with brackets)
push opening brackets into the stack 
when closing brackets come push untill opening brackets is encountered
also closing brackets will stop precedents checking as it is encountered.

#prefix
(infix to prefix)
using same logics as infix to postfix
reverse string
apply same logic 
again reverse string will be postfix

#evaluate potfix 
numbers in the stacks and when symbols comes two numbers are pooped 
and symbol is performed between two numbwers and again pushed in the stack 
in the end empty stack.

#binary search tree
(using recurrsion)
P=parent L=left R=right
#inorder
L P R
#postorder
L R P
#preorder
P L R

code recurrively for inorder

function calling (current->left)
printf(current->data)
function calling(current->right)

change order for postorder and preorder
