#include "base.h"

extern int index;

FILE *file_open_read();//���ļ�Ϊ��ȡ״̬
FILE *file_open_write();//���ļ�Ϊ��д״̬
bool file_close(FILE *stream);//�ر��ļ�
bool file_remove();//ɾ���ļ�
struct book *file_sync_read(FILE *stream);//��ȡ�ļ�
bool file_sync_write(struct book *begin,FILE *stream);//д���ļ�

FILE *file_open_read(){
    return fopen(FILENAME,"rb");
}

FILE *file_open_write(){
    return fopen(FILENAME,"wb");
}

bool file_close(FILE *stream){
    if (fclose(stream)==0) return true;
    else return false;
}

bool file_remove(){
    char* data=FILENAME;
    if (remove(data)==0) return true;
    return false;
}

struct book *file_sync_read(FILE *stream){
    struct book *begin=form_new();
    fread(&index,sizeof(index),1,stream);
    while (true){
        struct book *buffer=(struct book *)malloc(sizeof(struct book));
        if ((fread(buffer,sizeof(struct book),1,stream)==1)&&(buffer->forward!=NULL)){
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

//#define __DEBUG_FILE__
#ifdef __DEBUG_FILE__
int main(int argc, char const *argv[])
{
    return 0;
}
#endif