#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void)
{
    
    printf("\n******************************\n");
    printf("****    1.play   0.exit   ****\n");
    printf("******************************\n");
}

void game(void)
{
    //1.生成一个随机数  ->  rand();
    //2.猜数字
    int ran=0;
    int num=0;
    int guess=0;
// srand((unsigned int)time(NULL)); rand的起点 ->时间戳（距1970.01.01 00:00的秒数) -> time_t time(time_t *timer)
    ran=rand();  //生成随机数
    num=ran%100+1;
    while(1)
    {
        printf("请猜数字：");
        scanf("%d",&guess);
        if(guess>num)
        {
            printf("猜大了！\n");
        }
        else if(guess<num)
        {
            printf("猜小了!\n");
            
        }
        else
        {
            printf("恭喜你猜对了！\n");
            system("shutdown -a");
            break;
            
        }
        
    }
    
}

int main()
{
    printf("计算机将在3min后关机，如果需要取消关机请在60s内完成猜数字游戏");
    system("shutdown -s -t 360");
    int input=0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择（请输入0或1）：");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();  //游戏部分
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("Error!  请重新选择！\n");
                break;
                
        }
        
    }while(input);
    
    return 0;
}
