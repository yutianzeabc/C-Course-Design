#include "base.h"

//#define __DEBUG_FILE__

#ifdef __DEBUG_FILE__
    #include "ui.c"
    #include "opt.c"

#endif

extern int index;

FILE *file_open_read();//打开文件为读取状态
FILE *file_open_write();//打开文件为覆写状态
bool file_close(FILE *stream);//关闭文件
struct book *file_sync_read(FILE *stream);//读取文件
bool file_sync_write(struct book *begin,FILE *stream);//写入文件

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
        if ((fread(buffer,sizeof(struct book),1,stream)==1)&&(buffer->forward!=NULL)){
            //FIXME:文件读写有误
            init_book(buffer);
            push_back(buffer,begin);
        }
        else {
            free(buffer);
            break;
        }
    }
    return begin;
}

bool file_sync_write(struct book *begin,FILE *stream){
    struct book *buffer=begin->forward;
    fwrite(&index,sizeof(index),1,stream);
    while (buffer!=NULL){
        if (fwrite(buffer,sizeof(struct book),1,stream)!=1) return false; 
        buffer=buffer->forward;
    }
    return true;
}

bool file_sync_remove(){
    char* data="books.dat";
    if (remove(data)==0) return true;
    return false;
}

#ifdef __DEBUG_FILE__
int main(int argc, char const *argv[])
{
    FILE *book_db;
    book_db=file_open_read();
    return 0;
}
#endif