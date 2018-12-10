#ifndef __STD_H__
    #define __STD_H__
    # include <stdio.h>
    # include <stdlib.h>
    # include <stdbool.h>
#endif

//#define __DEBUG_LIST__

struct book{
    char regist[20],name[20],author[20],type[20],publish[20],publish_time[20],price[20];
    struct book *forward,*back;//链表
    char* quality[7];
};

void initialize(struct book* temp){
    temp->quality[0]=&(temp->regist);
    temp->quality[1]=&(temp->name);
    temp->quality[2]=&(temp->author);
    temp->quality[3]=&(temp->type);
    temp->quality[4]=&(temp->publish);
    temp->quality[5]=&(temp->publish_time);
    temp->quality[6]=&(temp->price);
    return;
}


struct book* form_new(){
    struct book* start,*end;
    start=(struct book *)malloc(sizeof(struct book));
    end=(struct book *)malloc(sizeof(struct book));
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

void push_back(struct book* new_book,struct book* start){
    struct book* temp;
    temp=get_end(start);
    combine(temp->back,temp,new_book);
    return;
}
//在末尾添加一个元素

void delete(struct book* target){
    (target->back)->forward=target->forward;
    (target->forward)->back=target->back;
    free(target);
    return;
}
//删除链表的一个元素

void take_in(struct book* start){
    struct book *t;
    t=(struct book *)malloc(sizeof(struct book));
    initialize(t);
    for(int i=0;i<7;i++){
        draw_input_sub_ui(i);
        gets(t->quality[i]);
    }
    push_back(t,start);
    return;
}
//添加元素
/*
void merge_sort(struct book* start,int q,int len){
    for(int i=2;i<=len;i*=2){
        for(int j=0;j<i;j+=1){

        }
    }
}
*/

#ifdef __DEBUG_LIST__
int main(int argc, char const *argv[])
{
    return 0;
}   
#endif