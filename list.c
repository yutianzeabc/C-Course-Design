#ifndef __STDIO_H__
    #define __STDIO_H__
    # include <stdio.h>
#endif
#ifndef __STDLIB_H__
    #define __STDLIB_H__  
    # include <stdlib.h>
#endif

//#define __DEBUG_LIST__

struct book{
    char regist[20],author[20],type[20],publish[20],time[20],price[20];
    struct book *forward,*back;//链表
};
struct book* form(){
    struct book* start,*end;
    start=(struct book *)malloc(sizeof(struct book));
    start->forward=end;
    start->back=NULL;
    end->back=start;
    end->forward=NULL;
    return start;
}
//构建一个空链表，并返回入口
void combine(struct book *from,struct book *to,struct book *new_book){
    from->forward=new_book;
    to->back=new_book;
    new_book->back=from;
    new_book->forward=to;
    return;
}
//插入元素到链表
struct book* get_end(struct book* start){
    struct book* temp=start->forward;
    while(temp->forward!=NULL){
        temp=temp->forward;
    }
    return temp;
}
//获取链表的末端
void push_back(struct book new_book,struct book* start){
    struct book* temp,*n;
    n=(struct book *)malloc(sizeof(struct book));
    *n=new_book;
    temp=get_end(start);
    combine(temp->back,temp,n);
    return;
}
//在末尾添加一个元素
void del(struct book* target){
    (target->back)->forward=target->forward;
    (target->forward)->back=target->back;
    free(target);
    return;
}

#ifdef __DEBUG_LIST__
int main(int argc, char const *argv[])
{
    return 0;
}   
#endif