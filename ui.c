#ifndef __STD_H__
    #define __STD_H__
    # include <stdio.h>
    # include <stdlib.h>
    # include <stdbool.h>
#endif

#ifndef __WIN_H__
    #define __WIN_H__  
    # include <windows.h>
    # include <winuser.h>
#endif

//#define __DEBUG_UI__

void init_console();
void set_console_pos();
void set_console_cursor();
void draw_main_ui();
void draw_load_ui();
void draw_input_ui();
void draw_output_ui();
void draw_query_ui();
void draw_query_author_ui();
void draw_query_title_ui();
void draw_modify_ui();
void draw_del_ui();

void init_console(){
    system("mode con: cols=46 lines=21");
    system("title 图书信息管理系统");
    system("color f0");
    set_console_pos();
    set_console_cursor();
    return;
}

void set_console_pos(){
    RECT rect;
    HWND hwnd=FindWindow("ConsoleWindowClass",NULL);
    int scr_width=GetSystemMetrics(SM_CXSCREEN);
    int scr_height=GetSystemMetrics(SM_CYSCREEN);
    GetWindowRect(hwnd,&rect);
    SetWindowPos(hwnd,HWND_TOPMOST,(scr_width-rect.right)/2,(scr_height-rect.bottom)/2,rect.right-rect.left,rect.bottom-rect.top,SWP_SHOWWINDOW);
}

void set_console_cursor(){
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    cursor_info.bVisible = 0;
    cursor_info.dwSize = 1;
    SetConsoleCursorInfo(console_handle,&cursor_info);
}

void draw_main_ui(){
    system("cls");
    printf("*============================================*\n");
    printf("#                                            #\n");
    printf("#              图书信息管理系统              #\n");
    printf("#                                            #\n");
    printf("*============================================*\n");
    printf("#                                            #\n");
    printf("#                  [1] 录 入                 #\n");
    printf("#                                            #\n");
    printf("#                  [2] 输 出                 #\n");
    printf("#                                            #\n");
    printf("#                  [3] 查 询                 #\n");
    printf("#                                            #\n");
    printf("#                  [4] 修 改                 #\n");
    printf("#                                            #\n");
    printf("#                  [5] 删 除                 #\n");
    printf("#                                            #\n");
    printf("#                  [0] 退 出                 #\n");
    printf("#                                            #\n");
    printf("*============================================*\n");
    printf("         Please enter your option : ");
    return;
}

void draw_load_ui(){
    system("cls");
    printf("*============================================*\n");
    printf("#                                            #\n");
    printf("#              图书信息管理系统              #\n");
    printf("#                                            #\n");
    printf("*============================================*\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                 Loading ...                #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("#                                            #\n");
    printf("*============================================*\n");
}

void draw_input_ui(){
    system("cls");
    printf("Please input one new record with one line (Input # to end): \n");
    printf("e.g:登录号#书名#作者名#分类号#出版单位#出版时间#价格\n");
    return;
}

void draw_output_ui(){
    system("cls");
    return;
}

void draw_query_ui(){
    system("cls");
    printf("*============================================*\n");
    printf("#                                            #\n");
    printf("#              图书信息管理系统              #\n");
    printf("#                                            #\n");
    printf("*============================================*\n");
    printf("#                                            #\n");
    printf("#                  [1] 书目名                #\n");
    printf("#                                            #\n");
    printf("#                  [2] 作者名                #\n");
    printf("#                                            #\n");
    printf("#                  [0] 返 回                 #\n");
    printf("#                                            #\n");
    printf("*============================================*\n");
    printf("         Please enter your option : ");
    return;
}

void draw_query_author_ui(){
    system("cls");
    printf("Please input the author name: \n");
    return;
}

void draw_query_title_ui(){
    system("cls");
    printf("Please input the book title: \n");
    return;
}

void draw_modify_ui(){
    system("cls");
    printf("Please input a book ID: \n");
    return;
} 

void draw_del_ui(){
    system("cls");
    printf("Please input a book ID: \n");
    return;
} 

#ifdef __DEBUG_UI__
int main(int argc, char const *argv[])
{
    init_console();
    draw_main_ui();
    getchar();
    return 0;
}   
#endif
