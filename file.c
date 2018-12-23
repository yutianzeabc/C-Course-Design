#ifndef __STD_H__
    #define __STD_H__
    # include <stdio.h>
    # include <stdlib.h>
    # include <stdbool.h>
#endif


#ifndef __WIN_H__
    #define __WIN_H__  
    #include <windows.h>
    #include <winuser.h>
    #include <conio.h>
#endif

extern int index;

#include "type.h"

//#define __DEBUG_FILE__

#ifdef __DEBUG_FILE__
    #include "ui.c"
    #include "opt.c"
#endif

FILE *file_open_read();//���ļ�Ϊ��ȡ״̬
FILE *file_open_write();//���ļ�Ϊ��д״̬
bool file_close(FILE *stream);//�ر��ļ�
struct book *file_sync_read(FILE *stream);//��ȡ�ļ�
bool file_sync_write(struct book *begin,FILE *stream);//д���ļ�

FILE *file_open_read(){
    return fopen("books.dat","rb");
}

FILE *file_open_write(){
    return fopen("books.dat","wb");
}

bool file_close(FILE *stream){
    if (fclose(stream)==0) return true;
    else return false;
}

struct book *file_sync_read(FILE *stream){
    struct book *begin=form_new();
    fread(&index,sizeof(index),1,stream);
    while (true){
        struct book *buffer=(struct book *)malloc(sizeof(struct book));
        if (fread(buffer,sizeof(struct book),1,stream)) push_back(buffer,begin);
        else {
            free(buffer);
            break;
        }
    }
    return begin;
}
//FIXME:�ļ���д����
bool file_sync_write(struct book *begin,FILE *stream){
    struct book *buffer=begin;
    fwrite(&index,sizeof(index),1,stream);
    while (buffer!=NULL){
        if (fwrite(buffer,sizeof(struct book),1,stream)!=1) return false; 
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