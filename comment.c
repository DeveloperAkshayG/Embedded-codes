##THIS CODE HELPS IN UNDERSTANDING THE #if0 and #endif directive which helps to comment out multiple sections of code you can also use #if0 instead of #if(i>1)

#include <stdio.h>
int main()
{
    int i=5;
    #if(i>1) 
    printf("last\n");
    printf("pop\n");
    printf("push\n");
    #endif
    
    printf("Hello World");

    return 0;
}
