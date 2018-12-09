#ifndef __STD_H__
    #define __STD_H__
    # include <stdio.h>
    # include <stdlib.h>
    # include <stdbool.h>
#endif

//#define __DEBUG_FILE__

FILE *file_open_read();//打开文件为读取状态
FILE *file_open_write();//打开文件为覆写状态
bool file_close(FILE *stream_db);//关闭文件

FILE *file_open_read(){
    return fopen("books.dat","a+");
}

FILE *file_open_write(){
    return fopen("books.dat","w+");
}

bool file_close(FILE *stream_db){
    if (fclose(stream_db)==0) return true;
    else return false;
}

#ifdef __DEBUG_FILE__
int main(int argc, char const *argv[])
{
    FILE *book_db;
    book_db=file_open("books.db","a+");
    return 0;
}

#endif