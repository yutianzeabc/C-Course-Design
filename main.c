#include "ui.c"
#include "list.c"
#include "file.c"

int main(int argc, char const *argv[])
{   
    draw_load_ui();
    FILE *book_db;
    book_db=file_open();
    draw_main_ui();
    while (1){
        int c=0;
        scanf("%d",&c);
        switch (c){
            case 0:
                return 0;
            case 1:
                draw_input_ui();
                draw_main_ui();
                break;
            case 2:
                draw_output_ui();
                draw_main_ui();
                break;
            case 3:
                draw_query_ui();
                int c2;   
                scanf("%d",&c2);
                switch (c2){
                    case 0:
                        break; 
                    case 1:
                        break;
                    case 2:
                        break;
                    default:
                        printf("\a");
                        draw_query_ui();
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
    return 0;
}

