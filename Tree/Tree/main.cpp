#include <cstdio>
#include <cstdlib>
#include <string>

#include "tree/listDirectory.h"

using namespace std;


int main ()
{
    string filePath = "E:/ProgramFile/C_CPP/dataStruct/Tree";

    listDirectory (filePath);

    //unsigned long l = sizeDirectory (filePath);
    //printf ("%ld\r\n", l);

    system ("pause");
    return 0;
}