#include "base.h"

extern int index;

int ipow(int a,int b);//����׳�
void init_book(struct book* target);//��ʼ���ṹ������ָ������
struct book* form_new();//�����������������
void combine(struct book *from,struct book *to,struct book *new_book);//���ӽڵ㵽����
struct book* get_end(struct book* start);//��ȡ����ĩ��
void push_back(struct book* new_book,struct book* start);//׷�ӽڵ㵽����β��
void delete(struct book* target);//ɾ������Ŀ��ڵ�
void take_in(struct book* start);//��ȡ������һ���½ڵ㣬׷�ӵ�����β��
void show_unit(struct book* target);//���Ŀ��ڵ���Ϣ
void show_list(struct book* start);//��������������нڵ���Ϣ
void swap(struct book* p,struct book* q);//���������е������ڵ�
int cmp(char a[],char b[]);//���ݱȽϺ���
int cal(char a[]);//��������ת������
void quick_sort(struct book *start,struct book *end,int i);//���������������
struct book* search_name(struct book* start,char in[]);//��ѯƥ��Ŀ���������нڵ�
struct book* search_author(struct book* start,char in[]);//��ѯƥ��Ŀ�����ߵ����нڵ�
struct book* search_num(struct book* start,int n);//��ѯƥ��ע���(����)�Ľڵ�
struct book* search_num_str(struct book* start,char in[]);//��ѯƥ��ע���(�ַ���)�Ľڵ�

int ipow(int a,int b){
    int out=1;
    while(b--){
        out*=a;
    }
    return out;
}

void init_book(struct book* target){
    target->quality[0]=(target->regist);
    target->quality[1]=(target->name);
    target->quality[2]=(target->author);
    target->quality[3]=(target->type);
    target->quality[4]=(target->publish);
    target->quality[5]=(target->publish_time);
    target->quality[6]=(target->price);
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

void combine(struct book *from,struct book *to,struct book *new_book){
    from->forward=new_book;
    to->back=new_book;
    new_book->back=from;
    new_book->forward=to;
    return;
}

struct book* get_end(struct book* start){
    struct book* target=start->forward;
    while(target->forward!=NULL){
        target=target->forward;
    }
    return target;
}

void push_back(struct book* new_book,struct book* start){
    struct book* target;
    target=get_end(start);
    combine(target->back,target,new_book);
    return;
}

void delete(struct book* target){
    (target->back)->forward=target->forward;
    (target->forward)->back=target->back;
    free(target);
    return;
}

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
            int tnum,j=0;
            tnum=index;
            while(tnum!=0){
                t->regist[18-j]=tnum%10+'0';
                tnum/=10;
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

void show_unit(struct book* target){
    for(int i=0;i<7;i++){
        draw_output_sub_ui(i);
        printf("%s\n",target->quality[i]);
    }
    return;
}

void show_list(struct book* start){
    int num=0;
    start=start->forward;
    while(start->forward!=NULL){
        int j=0;
        draw_output_promot_ui(num);
        num++;
        for(j=0;j<7;j++){
            draw_output_sub_ui(j);
            printf("%s\n",start->quality[j]);
        }
        start=start->forward;
        draw_wait_ui(0);
    }
    draw_wait_ui(1);
    return;
}

void swap(struct book* p,struct book* q){
    struct book target;
    memcpy(&target,p,sizeof(struct book));
    init_book(&target);
    target.forward = q->forward;
    target.back = q->back;
    q->forward = p->forward;
    q->back = p->back;
    memcpy(p,q,sizeof(struct book));//*p = *q;
    init_book(p);
    memcpy(q,&target,sizeof(struct book));//*q = target;
    init_book(q);
    return;
}

int cmp(char a[],char b[]){
    int an=0,bn=0;
    for(int i=19;i>=5;i--){
        an+=(a[i]-'0')*ipow(10,19-i);
        bn+=(b[i]-'0')*ipow(10,19-i);
    }
    return an<bn;
}

int cal(char a[]){
    int ans=0;
    for(int i=18;i>=0;i--){
        ans+=(a[i]-'0')*ipow(10,18-i);
    }
    return ans;
}

void quick_sort(struct book *start,struct book *end,int i){
    if(start->back!=end && start!=end){
        struct book *target=end,*p=start->back,*q=start;
        while(q!=end){
            if(strcmp(q->quality[i],target->quality[i])<=0 && i!=0){
                p=p->forward;
                swap(p,q);
            }
            else if(i==0 && cmp(q->quality[i],target->quality[i])<=0){
                p=p->forward;
                swap(p,q);
            }
            q=q->forward;
        }
        p=p->forward;
        swap(p,target);
        quick_sort(start,p->back,i);
        quick_sort(p->forward,end,i);
    }
    return;
}

struct book* search_name(struct book* start,char in[]){
    struct book* t;
    t=start->forward;
    while(strcmp(t->name,in)!=0){
        if(t->forward==NULL){
            t=t->forward;
            break;
        }
        t=t->forward;
    }
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

//#define __DEBUG_OPT__
#ifdef __DEBUG_OPT__
int main(int argc, char const *argv[])
{
    return 0;
}   
#endif