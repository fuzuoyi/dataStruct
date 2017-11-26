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

// 打印目录或文件名，用缩进表示深度depth
void printName (string dir, int depth);

// 打印目录或文件名及其大小，用缩进表示深度depth
void printName (string path, int depth, unsigned long size);

// 识别出"." ".." ，二者容易使程序进入死循环
bool is_dot (string path);

// list 目录， 先序遍历
void listDirectory (string path);

void _ListDir (string path, int depth);

// 计算目录大小，后序遍历
unsigned long sizeDirectory (string path, int depth=0);

