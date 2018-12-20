#ifndef __STD_H__
    #define __STD_H__
    # include <stdio.h>
    # include <stdlib.h>
    # include <stdbool.h>
#endif

//#define __DEBUG_FILE__

#ifdef __DEBUG_FILE__
    #include "ui.c"
    #include "list.c"
#endif
extern int index;

FILE *file_open_read();//打开文件为读取状态
FILE *file_open_write();//打开文件为覆写状态
bool file_close(FILE *stream);//关闭文件
struct book *file_on_read(FILE *stream);//读取文件
bool file_on_write(struct book *begin,FILE *stream);//写入文件

FILE *file_open_read(){
    return fopen("books.dat","r+b");
}

FILE *file_open_write(){
    return fopen("books.dat","w+b");
}

bool file_close(FILE *stream){
    if (fclose(stream)==0) return true;
    else return false;
}

struct book *file_on_read(FILE *stream){
    struct book *begin=form_new();
    fread(&index,sizeof(int),1,stream);
    while (true){
        struct book *buffer=(struct book *)malloc(sizeof(struct book));
        if (fread(buffer,sizeof(struct book),1,stream)){
            push_back(buffer,begin);
        }
        else {
            free(buffer);
            break;
        }
    }
    return begin;
}

bool file_on_write(struct book *begin,FILE *stream){
    struct book *buffer=begin;
    fwrite(&index,sizeof(int),1,stream);
    while (buffer!=NULL){
        if (fwrite(buffer,sizeof(struct book),1,stream)==0) return false;
        buffer=buffer->back;
    }
    return true;
}

#ifdef __DEBUG_FILE__
int main(int argc, char const *argv[])
{
    FILE *book_db;
    book_db=file_open_read();
    return 0;
}
#endif