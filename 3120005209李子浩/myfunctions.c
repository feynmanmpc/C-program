#include <stdio.h>
// 打卡系统用到的其它函数

/*打印菜单*/
void printMenu() 
{
    printf("\t\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
    printf("\t\t★     --欢迎进入学生自习打卡管理系统--     ★\n");
    printf("\t\t★         1.添加学生打卡信息               ★\n");
    printf("\t\t★         2.按学号查询学生打卡信息         ★\n");
    printf("\t\t★         3.按学号删除学生打卡记录         ★\n");
    printf("\t\t★         4.本班级打卡信息统计             ★\n");
    printf("\t\t★         0.退出系统                       ★\n");
    printf("\t\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
}



/*打印学生打卡信息*/
void printData(struct clockData student) 
{
    printf("学号:%s 姓名:%s 班级:%s 打卡日期:%s\n",
           student.id, student.name, student.className, student.clockInDate);
}


/*打印班级学生所有打卡统计*/
void printTotalData() {
    for (int i = 0; i < classClockTotalCount; i++) 
    {
        printf("学号:%s  姓名:%s  打卡次数:%d\n",classClockTotal[i].id,classClockTotal[i].name,classClockTotal[i].clockCount);
    }
}


/*根据学生id查询学生打卡信息*/
void showDataById(char *fileName, char *studentId) 
{
    char name[40];
    sprintf(name, "%s/%s.txt", fileName, studentId);
    // 若信息不存在
    if (access(name, 0) == -1) 
    {
        printf("该学号信息不存在!(按任意键继续)");
        getchar();
    } 
    else 
    {
        FILE *pFile;
        pFile = fopen(name, "r");
        if (pFile == NULL) perror("Error opening file");
        else 
        {
            int dataCount = 0;
            char mystring[100];
            while (fgets(mystring, 100, pFile) != NULL) 
            {
                char *p;
                p = strtok(mystring, " ");
                sscanf(p, "%s", cData.id);
                p = strtok(NULL, " ");
                sscanf(p, "%s", cData.name);
                p = strtok(NULL, " ");
                sscanf(p, "%s", cData.className);
                p = strtok(NULL, " ");
                sscanf(p, "%s", cData.clockInDate);
                printData(cData);
                dataCount++;
            }
            printf("统计：学生%s共打卡%d次\n",cData.name,dataCount);
            fclose(pFile);
        }
    }
}


/*根据学生id删除学生打卡信息*/
void deleteDataById(char *fileName, char *studentId) 
{
    char name[40];
    sprintf(name, "%s/%s.txt", fileName, studentId);
    // 若信息不存在
    if (access(name, 0) == -1) 
    {
        printf("该学号信息不存在!(按任意键继续)");
        getchar();
    } 
    else 
    {
        remove(name);
        printf("删除学生打卡信息成功!(按任意键继续)");
        getchar();
    }
}
