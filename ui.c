#ifndef __STD_H__
    #define __STD_H__
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
#endif

#ifndef __WIN_H__
    #define __WIN_H__  
    #include <windows.h>
    #include <winuser.h>
    #include <conio.h>
#endif
extern int index;
//#define __DEBUG_UI__

void init_console();//初始化控制台
void clear_console();//清除控制台
void set_console_pos();//设置控制台位置
void set_console_cursor();//设置控制台光标状态
void draw_main_ui();//绘制主UI
void draw_load_ui();//绘制读取UI
void draw_input_ui();//绘制输入UI
void draw_input_sub_ui(int i);//绘制输入子UI
void draw_output_ui();//绘制输出UI
void draw_output_sub_ui(int i);//绘制输出子UI
void draw_query_ui();//绘制查询UI
void draw_query_sub_ui(int i);//绘制查询子UI
void draw_modify_ui();//绘制修改UI
void draw_modify_sub_ui(int i);//绘制修改子UI
void draw_del_ui();//绘制删除UI
void draw_del_sub_ui();//绘制删除子UI

void init_console(){
    system("mode con: cols=46 lines=21");
    system("title 图书信息管理系统");
    system("color f0");
    set_console_pos();
    set_console_cursor();
    return;
}

void clear_console(){
    system("cls");
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
    clear_console();
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*               图书信息管理系统             *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*                  [1] 录 入                 *\n");
    printf("*                                            *\n");
    printf("*                  [2] 输 出                 *\n");
    printf("*                                            *\n");
    printf("*                  [3] 查 询                 *\n");
    printf("*                                            *\n");
    printf("*                  [4] 修 改                 *\n");
    printf("*                                            *\n");
    printf("*                  [5] 删 除                 *\n");
    printf("*                                            *\n");
    printf("*                  [0] 退 出                 *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("         Please enter your option : ");
    return;
}

void draw_load_ui(){
    clear_console();
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*               图书信息管理系统             *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                 Loading ...                *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
}

void draw_input_ui(){
    clear_console();
    printf("请输入数据条目数: \n");
    return;
}

void draw_input_sub_ui(int i){
    switch (i){
        case 0:
            printf("登录号: ");
            return;
        case 1:
            printf("书名: ");
            return;
        case 2:
            printf("作者名: ");
            return;
        case 3:
            printf("分类号: ");
            return;
        case 4:
            printf("出版单位: ");
            return;
        case 5:
            printf("出版时间: ");
            return;
        case 6:
            printf("价格: ");
            return;
        default:
            exit(1);
    }
}

void draw_output_ui(){
    clear_console();
    return;
}

void draw_output_sub_ui(int i){
    switch (i){
        case 0:
            printf("登录号: ");
            return;
        case 1:
            printf("书名：");
            return;
        case 2:
            printf("作者名: ");
            return;
        case 3:
            printf("分类号: ");
            return;
        case 4:
            printf("出版单位: ");
            return;
        case 5:
            printf("出版时间: ");
            return;
        case 6:
            printf("价格: ");
            return;
        default:
            exit(1);
    }
}

void draw_query_ui(){
    clear_console();
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*               图书信息管理系统             *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*                  [1] 标 题                 *\n");
    printf("*                                            *\n");
    printf("*                  [2] 作 者                 *\n");
    printf("*                                            *\n");
    printf("*                  [0] 返 回                 *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("         Please enter your option : ");
    return;
}

void draw_query_sub_ui(int i){
    clear_console();
    switch (i){
        case 0:
            printf("请输入图书标题: \n");
            return;
        case 1:
            printf("请输入图书作者: \n");
            return;
        default:
            exit(1);
    }
    
    return;
}

void draw_modify_ui(){
    clear_console();
    printf("请输入图书登录号: \n");
    return;
} 

void draw_modify_sub_ui(int i){
    switch (i){
        case 0:
            printf("登录号: ");
            return;
        case 1:
            printf("书名: ");
            return;
        case 2:
            printf("作者名: ");
            return;
        case 3:
            printf("分类号: ");
            return;
        case 4:
            printf("出版单位: ");
            return;
        case 5:
            printf("出版时间: ");
            return;
        case 6:
            printf("价格: ");
            return;
        default:
            exit(1);
    }
}

void draw_del_ui(){
    clear_console();
    printf("请输入图书登录号: \n");
    return;
}

void draw_del_sub_ui(){
    printf("确认删除(Y/N): ");
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
