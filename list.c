# include <stdio.h>
# include <stdlib.h>
struct book{
    char regist[20],regist[20],author[20],type[20],publish[20],time[20],price[20];
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
void combine(struct book *from,struct book *to,struct book *new){
    from->forward=new;
    to->back=new;
    new->back=from;
    new->forward=to;
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
void push_back(struct book new,struct book* start){
    struct book* temp,*n;
    n=(struct book *)malloc(sizeof(struct book));
    *n=new;
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