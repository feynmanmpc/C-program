#include <stdio.h>
#include <unistd.h>
#include "fileoperate.c"
#include "myfunctions.c"


/*主函数（管理函数）*/
int main() 
{
    printf("\t\t★         --欢迎进入学生自习打卡管理系统--         ★\n");
    // 1.首先创建数据文件夹（其中保存打卡数据）
    createFolder("data");
    // 2.输入要管理的班级
    Flag1:;
    char className[30];
    char judgeClassName[40];
    printf("请输入您的班级:");
    scanf("%s", className);
    // 根据路径创建文件夹名
    sprintf(judgeClassName, "data/%s", className);
    // 3.判断班级文件夹是否存在
    if (access(judgeClassName, 0) == -1) {
        // 班级不存在则请求是否根据班级名创建文件夹
        printf("抱歉，您输入的班级[%s]不存在\n是否创建文件夹?(1.是 0.否)", className);
        getchar();
        char choice;
        scanf("%c", &choice);
        // 是则创建文件夹
        if (choice == '1') 
        {
            char fileName[20];
            sprintf(fileName, "data/%s", className);
            createFolder(fileName);
            printf("文件夹%s创建成功!\n", fileName);
        } 
        else 
        {
            // 否 返回输入班级名
            goto Flag1;
        }
    } 
    else 
    {
        // 班级存在则读取班级文件数据
        printf("正在读取文件数据...\n");
        readData(judgeClassName);
    }

    // 选择要进行的操作
    int choice;
    char studentId[20];
    while (1) 
    {
        printMenu();
        printf("\t请选择您需要的操作:");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("添加学生打卡信息\n");
                addStudentData(judgeClassName);
                readData(judgeClassName);   // 每次添加完成后重新读取数据
                break;
            case 2:
                printf("按学号查询学生的打卡信息\n请输入学生学号:");
                scanf("%s", studentId);
                showDataById(judgeClassName, studentId);
                break;
            case 3:
                printf("按学号删除学生打卡记录\n请输入学生学号:");
                scanf("%s", studentId);
                deleteDataById(judgeClassName, studentId);
                readData(judgeClassName);   // 每次删除完成后重新读取数据
                break;
            case 4:
                printf("查询班级的打卡情况（缺卡人数及其缺卡次数）\n");
                printTotalData();
                break;
            case 0:
                printf("退出系统\n");
                return 0;
            default:
                printf("输入错误!");
                break;
        }
    }
}
