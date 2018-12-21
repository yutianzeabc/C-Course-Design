#ifndef __STD_H__
    #define __STD_H__
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>   
#endif

#ifndef __STR_H__
    #define __STR_H__
    #include <string.h>  
#endif

//#define __DEBUG_LIST__

#ifdef __DEBUG_LIST__
    #include "ui.c"
#endif
extern int index;
struct book{
    char regist[20],name[20],author[20],type[20],publish[20],publish_time[20],price[20];
    struct book *forward,*back;//链表
    char* quality[7];
};
int pow(int a,int b){
    int out=1;
    while(b--){
        out*=a;
    }
    return out;
}
void init_book(struct book* temp){
    temp->quality[0]=(temp->regist);
    temp->quality[1]=(temp->name);
    temp->quality[2]=(temp->author);
    temp->quality[3]=(temp->type);
    temp->quality[4]=(temp->publish);
    temp->quality[5]=(temp->publish_time);
    temp->quality[6]=(temp->price);
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
    init_book(t);
    int i;
    for(i=0;i<7;i++){
        if(i==0){
            t->regist[19]='\0';
            for(int i=0;i<19;i++){
                t->regist[i]='0';
            }
            int ttt,j=0;
            ttt=index;
            while(ttt!=0){
                t->regist[18-j]=ttt%10+'0';
                ttt/=10;
            }
            index++;
            continue;
        }
        draw_input_sub_ui(i);
        gets(t->quality[i]);
    }
    push_back(t,start);
    return;
}
//添加元素
void show_list(struct book* start){
    start=start->forward;
    while(start->forward!=NULL){
        int j=0;
        for(j=0;j<7;j++){
            draw_output_sub_ui(j);
            printf("%s\n",start->quality[j]);
        }
        printf("\n");
        start=start->forward;
    }
    return;
}
//
void swap(struct book* p,struct book *q){
    struct book temp;
    memcpy(&temp,p,sizeof(struct book));
    init_book(&temp);
    temp.forward = q->forward;
    temp.back = q->back;
    q->forward = p->forward;
    q->back = p->back;
    memcpy(p,q,sizeof(struct book));//*p = *q;
    init_book(p);
    memcpy(q,&temp,sizeof(struct book));//*q = temp;
    init_book(q);
    return;
}
int cmp(char a[],char b[]){
    int an=0,bn=0;
    for(int i=19;i>=5;i--){
        an+=(a[i]-'0')*pow(10,19-i);
        bn+=(b[i]-'0')*pow(10,19-i);
    }
    return an<bn;
}
int cal(char a[]){
    int an=0;
    for(int i=18;i>=0;i--){
        an+=(a[i]-'0')*pow(10,18-i);
    }
    return an;
}
void quick_sort(struct book *start,struct book *end,int i){
    if(start->back!=end && start!=end){
        struct book *temp=end,*p=start->back,*q=start;
        while(q!=end){
            if(strcmp(q->quality[i],temp->quality[i])<=0 && i!=0){
                p=p->forward;
                swap(p,q);
            }
            else if(i==0 && cmp(q->quality[i],temp->quality[i])<=0){
                p=p->forward;
                swap(p,q);
            }
            q=q->forward;
        }
        p=p->forward;
        swap(p,temp);
        quick_sort(start,p->back,i);
        quick_sort(p->forward,end,i);
    }
    return;
}

struct book* search_name(struct book* start,char in[]){
    struct book* t;
    //printf("1");
    t=start->forward;
    while(strcmp(t->name,in)!=0){
        //printf("2");
        if(t->forward==NULL){
            t=t->forward;
            break;
        }
        t=t->forward;
    }
    //printf("done");
    return t;
}
struct book* search_author(struct book* start,char in[]){
    start=start->forward;
    while(strcmp(start->author,in)!=0){
        if(start->forward==NULL){
            start=start->forward;
            break;
        }
        start=start->forward;
    }
    return start;
}
struct book* search_num_str(struct book* start,char in[]){
    start=start->forward;
    while(strcmp(start->regist,in)!=0){
        if(start->forward==NULL){
            start=start->forward;
            break;
        }
        start=start->forward;
    }
    return start;
}
struct book* search_num(struct book* start,int n){
    start=start->forward;
    while(cal(start->regist)!=n){
        if(start->forward==NULL){
            start=start->forward;
            break;
        }
        start=start->forward;
    }
    return start;
}
void show_unit(struct book* t){
    for(int i=0;i<7;i++){
        draw_output_sub_ui(i);
        printf("%s\n",t->quality[i]);
        //printf("yeah!");
    }
    return;
}
#ifdef __DEBUG_LIST__
int main(int argc, char const *argv[])
{
    struct book *start,*end,*t,*t1;
    start=form_new();
    int i=0;
    for(i=0;i<10;i++){
        take_in(start);
    }
    end=get_end(start);
    t=start->forward;t1=end->back;
    quick_sort(t,t1,0);
    show_list(start);
    getchar();
    return 0;
}   
#endif