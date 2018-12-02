#include <ui.c>
#include <list.c>
#include <file.c>

int main(int argc, char const *argv[])
{   
    draw_load_ui();
    FILE *book_db;
    book_db=file_open();
    draw_main_ui();
    while (1){
        char c='x';
        scanf("%c",&c);
        switch(c){
            case 'x':
            case 'X':
                return 0;
            case '1':
                draw_input_ui();
                break;
            case '2':
                draw_output_ui();
                break;
            case '3':
                draw_query_ui();
                break;
            case '4':
                draw_modify_ui();
                break;
            case '5':
                draw_del_ui();
                break;
            default:
                printf("\a");
                draw_main_ui();
        }
    }
    return 0;
}

