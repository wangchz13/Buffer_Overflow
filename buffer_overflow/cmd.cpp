#include <windows.h>

#include <stdio.h>
int findJmp(const char* dll_name);
int main()
{
	//LoadLibrary("msvcrt.dll");
	printf("%d", findJmp("msvcrt.dll"));
	return 0;
}

//��ѯdll�ڵ�һ��jmp espָ���λ��
int findJmp(const char* dll_name)
{
    char* handle=(char*)LoadLibraryA(dll_name);//��ȡdll���ص�ַ
    for(int pos=0;;pos++)//����dll����ռ�
    {
        if(handle[pos]=='M'&&handle[pos+1]=='Z')//Ѱ��0xffe4 = jmp  esp
        {
            return (int)(handle+pos);
        }
    }
	return 0;
}