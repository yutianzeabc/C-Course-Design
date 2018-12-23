#include "ui.c"
#include "list.c"
#include "file.c"

int index=0;

int main(int argc, char const *argv[])
{   
    init_console();
    draw_load_ui();
    FILE* fp;
    struct book* start;
    fp=file_open_read();
    if (fp!=NULL){
        start=file_sync_read(fp);
        file_close(fp);
    }
    else{
        start=form_new();
    }
    draw_main_ui();
    while (true){
        struct book* temp;
        char s[20];
        int choice=-1;
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice){
            case 0: 
                file_close(fp);
                return 0;
            case 1:
                draw_input_ui();
                int num=-1;
                while (num==-1){
                    fflush(stdin);
                    draw_input_ui();
                    scanf("%d",&num);
                    fflush(stdin);
                }
                clear_console();
                for (int i=0;i<num;i++){
                    draw_input_promot_ui(i,num);
                    take_in(start);
                    clear_console();
                }
                draw_main_ui();
                break;
            case 2:
                draw_output_ui();
                show_list(start);
                draw_main_ui();
                break;
            case 3:
                draw_query_ui(); 
                choice=-1;
                fflush(stdin);
                scanf("%d",&choice);
                bool flag=false;
                while (true){
                    if (flag){
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
                            gets(s);
                            clear_console();
                            temp=search_name(start,s);
                            if (temp==NULL){
                                draw_exception_ui();
                            }
                            else {
                                show_unit(temp);
                                draw_wait_ui(2);
                            }
                            flag=true;
                            break;
                        case 2:
                            draw_query_sub_ui(1);
                            fflush(stdin);
                            gets(s);
                            clear_console();
                            temp=search_author(start,s);
                            if (temp==NULL){
                                draw_exception_ui();
                            }
                            else {
                                show_unit(temp);
                                draw_wait_ui(2);
                            }
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
                int m_target=-1;
                while(m_target==-1){
                    fflush(stdin);
                    draw_modify_ui();
                    scanf("%d",&m_target);
                    fflush(stdin);
                }
                clear_console();
                temp=search_num(start,m_target);
                if(temp==NULL){
                    draw_exception_ui();
                    draw_main_ui();
                    break;
                }
                for(int i=1;i<7;i++){
                    draw_input_sub_ui(i);
                    gets(s);
                    strcpy(temp->quality[i],s);
                }
                draw_modify_succeed_ui();
                draw_main_ui();
                break;
            case 5:
                draw_del_ui();
                int d_target=-1;
                while(d_target==-1){
                    fflush(stdin);
                    draw_del_ui();
                    scanf("%d",&d_target);
                    fflush(stdin);
                }
                clear_console();
                temp=search_num(start,d_target);
                if(temp==NULL){
                    draw_exception_ui();
                    draw_main_ui();
                    break;
                }
                printf("%s",temp->name);
                delete(temp);
                draw_del_succeed_ui();
                draw_main_ui();
                break;
            default:
                printf("\a");
                draw_main_ui();
        }
    }
}

