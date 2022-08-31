#include <stdio.h>
#define N 5
int stack[N];
int top=-1;

void push()
    {
        int x;
        printf("Enter data:\n");
        scanf("%d",&x);
        if(top==N-1){
            printf("Overflow");
        }
        else{
            top++;
            stack[top]=x;
        }
    }

void pop()
        {
            int item;
            if(top==-1){
                printf("underflow");
            }
            else{
                item=stack[top];
                top--;
                printf("%d \t is poped",item);
            }
        }

 void peek()
            {
                if(top==-1){
                    printf("\n empty");
                }
                else{
                    printf("%d is in the top of stack",stack[top]);

                }
            }
 void  display()
            {
                int i;
                for(i=top;i>=0;i--)
                {
                    printf("%d\t",stack[i]);
                }
                if(top==-1){
                    printf("\n stack is empty");
                }
            }
void main()
                {
                    int ch;
                    do{
                        printf("\n \n Enter choice : 1.push 2.pop 3.peek 4.Display \t");
                        scanf("%d",&ch);
                        switch(ch)
                            {
                                case 1: push();
                                break;

                                case 2: pop();
                                break;

                                case 3: peek();
                                break;

                                case 4: display();
                                break;

                                case 0:
                                break;


                            }
                    }
                    while(ch!=0);
                }

