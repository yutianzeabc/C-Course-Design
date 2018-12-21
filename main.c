#include "ui.c"
#include "list.c"
#include "file.c"
int index=0;
int main(int argc, char const *argv[])
{   
    init_console();
    draw_load_ui();
    FILE *fp;
    struct book *start;
    fp=file_open_read();
    if(fp!=NULL){
        start=file_on_read(fp);
    }
    else{
        start=form_new();
    }
    draw_main_ui();
    while (true){
        struct book* ta,*ttt1,*ttt;
        char n[20],s[20];
        int choice=-1,nn;
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice){
            case 0: 
                file_close(fp);
                return 0;
            case 1:
                draw_input_ui();
                int tiao=-1;
                while(tiao==-1){
                    fflush(stdin);
                    scanf("%d",&tiao);
                    fflush(stdin);
                }
                for(int i=0;i<tiao;i++){
                    take_in(start);
                }
                draw_main_ui();
                break;
            case 2:
                draw_output_ui();
                show_list(start);
                printf("按任意键返回...");
                getch();
                draw_main_ui();
                break;
            case 3:
                draw_query_ui(); 
                choice=-1;
                fflush(stdin);
                scanf("%d",&choice);
                bool flag=false;
                while (1){
                    if (flag) {
                        draw_main_ui();
                        break;
                    }
                    switch (choice){
                        case 0:
                            flag=true;
                            break; 
                        case 1:
                            draw_query_sub_ui(0);
                            fflush(stdin);
                            gets(n);
                            ta=search_name(start,n);
                            if(ta==NULL){
                                printf("shit!\n");
                            }
                            else show_unit(ta);
                            getch();
                            flag=true;
                            break;
                        case 2:
                            draw_query_sub_ui(1);
                            fflush(stdin);
                            gets(n);
                            ta=search_author(start,n);
                            if(ta==NULL){
                                printf("shit!\n");
                            }
                            else show_unit(ta);
                            flag=true;
                            break;
                        default:
                            printf("\a");
                            draw_query_ui();
                    }
                }
                draw_main_ui();
                break;
            case 4:
                draw_modify_ui();
                gets(s);
                ttt=search_num_str(start,s);
                for(int i=1;i<7;i++){
                    draw_input_sub_ui(i);
                    char u[20];
                    gets(u);
                    strcpy(ttt->quality[i],u);
                }
                draw_main_ui();
                break;
            case 5:
                draw_del_ui();
                scanf("%d",&nn);
                ttt1=search_num(start,nn);
                if(ttt1==NULL){
                    printf("shit??");
                    break;
                }
                printf("%s",ttt1->name);
                delete(ttt1);
                draw_main_ui();
                break;
            default:
                printf("\a");
                draw_main_ui();
        }
    }
    file_close(fp);
    return 0;
}

