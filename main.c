#include <ui.c>
#include <list.c>

int main(int argc, char const *argv[])
{
    draw_main_ui();
    while (1){
        char c;
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
            case '4':
                draw_modify_ui();
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

