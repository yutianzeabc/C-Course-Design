#include "base.h"

extern int index;

void init_console();//初始化控制台
void clear_console();//清除控制台
void set_console_rect();//设置控制台外观和位置
void set_console_cursor();//设置控制台光标状态
void draw_main_ui();//绘制主UI
void draw_load_ui();//绘制读取UI
void draw_wait_ui(int i);//绘制等待UI
void draw_exception_ui();//绘制异常UI
void draw_input_ui();//绘制录入UI
void draw_input_sub_ui(int i);//绘制录入子UI
void draw_input_promot_ui(int i,int sum);//绘制录入提示UI
void draw_output_ui();//绘制输出UI
void draw_output_sub_ui(int i);//绘制输出子UI
void draw_output_promot_ui(int i);//绘制输出提示UI
void draw_query_ui();//绘制查询UI
void draw_query_sub_ui(int i);//绘制查询子UI
void draw_modify_ui();//绘制修改UI
void draw_modify_sub_ui(int i);//绘制修改子UI
void draw_modify_succeed_ui();//绘制修改成功UI
void draw_del_ui();//绘制删除UI
void draw_del_comfirm_ui(struct book* target);//绘制删除确认UI
void draw_del_succeed_ui();//绘制删除成功UI
void draw_file_remove_ui();//绘制文件删除UI
void draw_file_error_ui();//绘制文件错误UI

void init_console(){
    system("mode con: cols=46 lines=21");
    system("title 图书信息管理系统");
    system("color f0");
    set_console_cursor();
    set_console_rect();
    return;
}

void clear_console(){
    system("cls");
    return;
}

void set_console_rect(){
    RECT rect;
    HWND hwnd=GetConsoleWindow();
    int scr_width=GetSystemMetrics(SM_CXSCREEN);
    int scr_height=GetSystemMetrics(SM_CYSCREEN);
    GetWindowRect(hwnd,&rect);
    SetWindowLongPtr(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
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
    printf("          Please enter your option : ");
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

void draw_wait_ui(int i){
    switch(i){
        case 0:
            printf("\n按任意键继续...");
            getch();
            clear_console();
            return;
        case 1:
            printf("按任意键退出...");
            getch();
            return;
        case 2:
            printf("\n按任意键退出...");
            getch();
            return;
        default:
            exit(1);
    }
}

void draw_exception_ui(){
    clear_console();
    printf("目标书籍不存在！\n");
    draw_wait_ui(2);
    return;
}

void draw_input_ui(){
    clear_console();
    printf("请输入数据条目数:\n");
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

void draw_input_promot_ui(int i,int sum){
    printf("---当前录入第%d本，共%d本---\n\n",i+1,sum);
    return;
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

void draw_output_promot_ui(int i){
    printf("---当前输出第%d本---\n\n",i+1);
    return;
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
    printf("          Please enter your option : ");
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

void draw_modify_succeed_ui(){
    clear_console();
    printf("目标书籍修改成功！\n");
    draw_wait_ui(2);
    return;
}

void draw_del_ui(){
    clear_console();
    printf("请输入图书登录号: \n");
    return;
}

void draw_del_comfirm_ui(struct book* target){
    printf("目标书籍登录号: %s\n目标书籍标题: %s\n\n确认删除(Y/N): ",target->regist,target->name);
    return;
}


void draw_del_succeed_ui(){
    clear_console();
    printf("目标书籍删除成功！\n");
    draw_wait_ui(2);
    return;
}

void draw_file_remove_ui(){
    clear_console();
    printf("数据文件已删除！\n");
    draw_wait_ui(2);
    return;
}

void draw_file_error_ui(){
    clear_console();
    printf("文件读写错误！\n");
    draw_wait_ui(2);
    return;
}

//#define __DEBUG_UI__
#ifdef __DEBUG_UI__
int main(int argc, char const *argv[])
{
    return 0;
}   
#endif
