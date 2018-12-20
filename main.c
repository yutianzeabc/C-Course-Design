#include "ui.c"
#include "list.c"
#include "file.c"

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
        int choice=-1;
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
                            
                            break;
                        case 2:
                            draw_query_sub_ui(1);
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
                draw_main_ui();
                break;
            case 5:
                draw_del_ui();
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

