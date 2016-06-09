#include <windows.h>

//查询dll内第一个jmp esp指令的位置
int findJmp(const char *dll_name)
{
    char* handle = (char*)LoadLibraryA(dll_name);//获取dll加载地址
    for(int pos=0;;pos++)//遍历dll代码空间
    {
        if(handle[pos]==0xff && handle[pos+1]==0xe4)//寻找0xffe4 = jmp  esp
        {
            return (int)(handle+pos);
        }
    }
}