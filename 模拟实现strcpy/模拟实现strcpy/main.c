#include <stdio.h>

/*
void my_strcpy(char* dest,char* src)
{
    if(dest != NULL && src != NULL)
    {
        while(*dest++ = *src++)
        {
              ;
        }
        
    }
          *dest = *src;
}  */

#include<assert.h>
/*
void my_strcpy(char* dest,char* src)
{
    assert(dest != NULL);//断言
    assert(src != NULL);//断言
    while(*dest++ = *src++)
    {
              ;
    }
        
          *dest = *src;
}
*/

/*
void my_strcpy(char* dest,const char* src)
{
    assert(dest != NULL);//断言
    assert(src != NULL);//断言
    while(*dest++ = *src++)
    {
              ;
    }
        
          *dest = *src;
}
*/

char* my_strcpy(char* dest,const char* src)
{
    char* ret = dest;
    assert(dest != NULL);//断言
    assert(src != NULL);//断言
    //把src指向的字符串拷贝到dest指向的空间，并且包含'\0' 
    while(*dest++ = *src++)
    {
              ;
    }
        
          *dest = *src;
    return ret;
}

int main(int argc, const char * argv[])
{
    char arr1[]="hello";
    char arr2[]="hi";
    //strcpy
    printf("%s\n",my_strcpy(arr1,arr2));
    return 0;
}
