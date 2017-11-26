#include "listDirectory.h"

void printName (string path, int depth)
{
    string s;
    for(int i = 0; i < depth; i++)
        s += "    ";
    printf ("%s%s\r\n", s.c_str (), path.c_str ());
}

bool is_dot (string path)
{
    // ���������ж�·�������ǲ���"."��".."
    if(path[0] == (char)'.' && path[1] == (char)'\0')
        return true;
    else if(path[0] == (char)'.' && path[1] == (char)'.' && path[2] == (char)'\0')
        return true;
    else
        return false;
}

void _ListDir (string path, int depth)
{
    long   hFile = 0;
    struct _finddata_t fileinfo;

    if((hFile = _findfirst ((path + "/*").c_str (), &fileinfo)) != -1)
    {
        do
        {
            if(is_dot (fileinfo.name))
                continue;

            if((fileinfo.attrib &  _A_SUBDIR))  //������ҵ������ļ���    
            {
                printName (fileinfo.name, depth);
                _ListDir (path + '/' + fileinfo.name, depth + 1);
            }
            else
                printName (fileinfo.name, depth);
        } while(_findnext (hFile, &fileinfo) == 0);
    }
}

void listDirectory (string path)
{
    _ListDir (path, 0);
}



void printName (string path, int depth, unsigned long size)
{
    string s;
    for(int i = 0; i < depth; i++)
        s += "  ";
    printf ("%s%s\t\t%ld\r\n", s.c_str (), path.c_str (), size);
}

unsigned long sizeDirectory (string path, int depth)
{
    long   hFile = 0;
    struct _finddata_t fileinfo;

    unsigned long totalSize = 0;

    if((hFile = _findfirst ((path + "/*").c_str (), &fileinfo)) != -1)
    {
        do
        {
            if(is_dot (fileinfo.name))
                continue;

            if((fileinfo.attrib &  _A_SUBDIR))  //������ҵ������ļ���    
            {
                // �˴�totalsize��ֱ�Ӽ��㣬���ǵݹ�Ŀ¼�µ������ļ��������ۻ���
                totalSize += sizeDirectory (path + '/' + fileinfo.name, depth + 1);

                // printName���ڼ����ļ���size�󣬷������ӡ��ʹ��������ʽ��Ϊ�������
                printName (fileinfo.name, depth, fileinfo.size);

            }
            else
            {
                // ���ļ�����size�ӵ�totalsize��
                totalSize += fileinfo.size;
                printName (fileinfo.name, depth, fileinfo.size);
            }

        } while(_findnext (hFile, &fileinfo) == 0);
    }
    return totalSize;
}