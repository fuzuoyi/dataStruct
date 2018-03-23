#pragma once

/***    
    *   list Directory
    *   get Directory Size
    *
    */



#include <cstdio>
#include <cstdlib>
#include <string>
#include <io.h> 

#include <filesystem>

using namespace std;

// ��ӡĿ¼���ļ�������������ʾ���depth
void printName (string dir, int depth);

// ��ӡĿ¼���ļ��������С����������ʾ���depth
void printName (string path, int depth, unsigned long size);

// ʶ���"." ".." ����������ʹ���������ѭ��
bool is_dot (string path);

// list Ŀ¼�� �������
void listDirectory (string path);

void _ListDir (string path, int depth);

// ����Ŀ¼��С���������
unsigned long sizeDirectory (string path, int depth=0);

