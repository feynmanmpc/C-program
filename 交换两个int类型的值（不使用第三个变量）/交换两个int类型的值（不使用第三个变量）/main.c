#include <stdio.h>

int main(void)
{
   int a=114,b=514;
   
    /*
    int temp = 0;
    printf("before: \na = %d\nb = %d\n",a,b);
    temp = a;
    a = b;
    b = temp;
    printf("after: \na = %d\nb = %d\n",a,b);
     */

    /*
    //加减法 ---可能会溢出
    a = a + b;
    b = a - b;
    a = a - b;
    */
    
    
    //异或的方法
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    printf("after: \na = %d\nb = %d\n",a,b);

   return 0;
}
