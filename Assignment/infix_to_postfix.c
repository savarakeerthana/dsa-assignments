#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
stack[++top] = ch;
}

char pop()
{
return stack[top--];
}

char peek()
{
return stack[top];
}

int precedence(char ch)
{
switch(ch)
{
case '^':
return 3;

case '*':  
    case '/':  
        return 2;  

    case '+':  
    case '-':  
        return 1;  

    default:  
        return 0;  
}

}

int main()
{
char infix[MAX], postfix[MAX];
int i, j = 0;
char ch;

printf("Enter infix expression: ");  
scanf("%s", infix);  

for(i = 0; infix[i] != '\0'; i++)  
{  
    ch = infix[i];  

    if(isalnum(ch))  
    {  
        postfix[j++] = ch;  
    }  
    else if(ch == '(')  
    {  
        push(ch);  
    }  
    else if(ch == ')')  
    {  
        while(top != -1 && peek() != '(')  
        {  
            postfix[j++] = pop();  
        }  

        if(top != -1)  
            pop();  
    }  
    else  
    {  
        while(top != -1 &&  
              peek() != '(' &&  
              precedence(peek()) >= precedence(ch))  
        {  
            postfix[j++] = pop();  
        }  

        push(ch);  
    }  
}  

while(top != -1)  
{  
    postfix[j++] = pop();  
}  

postfix[j] = '\0';  

printf("Postfix expression: %s\n", postfix);  

return 0;

}