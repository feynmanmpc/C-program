#include <stdio.h>
int count_one(int n);

int main (void)
{
    int num = 0;
    printf("请输入一个整数：");
    scanf("%d",&num);
    //统计num二进制1的个数
    int count1 = 0;
    int count2 = 0;//使用函数
    
   /*   不可以处理负数
    while(num)
    {
         if(num % 2 == 1)
         count ++;
        num = num / 2;
         
    }
    */
    
    int i = 0;
    for(i=0;i<32;i++)
    {
        if( 1 == ((num >> i)&1))
        count1 ++;
    }
    
    
    printf("%d\n",count1);
    
    count2 = count_one(num);
    printf("%d\n",count2);
    return 0;
}

//考虑n&(n-1);

int count_one(int n)
{
    int count =0;
    while(n)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}
