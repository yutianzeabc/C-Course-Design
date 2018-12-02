#ifndef __STDIO_H__
    #define __STDIO_H__
    # include <stdio.h>
#endif

#ifndef __STDLIB_H__
    #define __STDLIB_H__  
    # include <stdlib.h>
#endif

#define __DEBUG_UI__

void draw_main_ui(){
    system("cls");
    printf("*========================================*\n");
    printf("#                                        #\n");
    printf("#            图书信息管理系统            #\n");
    printf("#                                        #\n");
    printf("*========================================*\n");
    printf("#                                        #\n");
    printf("#                [1] 录 入               #\n");
    printf("#                                        #\n");
    printf("#                [2] 输 出               #\n");
    printf("#                                        #\n");
    printf("#                [3] 查 询               #\n");
    printf("#                                        #\n");
    printf("#                [4] 修 改               #\n");
    printf("#                                        #\n");
    printf("#                [5] 删 除               #\n");
    printf("#                                        #\n");
    printf("#                [X] 退 出               #\n");
    printf("#                                        #\n");
    printf("*========================================*\n");
    printf("        Please enter your option:");
    return;
}
void draw_load_ui(){
    system("title 图书信息管理系统");
    system("color f0");
    printf("*========================================*\n");
    printf("#                                        #\n");
    printf("#            图书信息管理系统            #\n");
    printf("#                                        #\n");
    printf("*========================================*\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#               Loading...               #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("*========================================*\n");
}
void draw_input_ui(){
    system("cls");
    printf("Please input a new record with a line (input # to end):\n");
    printf("e.g:登录号#书名#作者名#分类号#出版单位#出版时间#价格\n");
    return;
}
void draw_output_ui(){
    system("cls");
    return;
}
void draw_query_ui(){
    system("cls");
    printf("*========================================*\n");
    printf("#                                        #\n");
    printf("#            图书信息管理系统            #\n");
    printf("#                                        #\n");
    printf("*========================================*\n");
    printf("#                                        #\n");
    printf("#                [1] 作者名              #\n");
    printf("#                                        #\n");
    printf("#                [2] 书目名              #\n");
    printf("#                                        #\n");
    printf("#                [X] 返 回               #\n");
    printf("#                                        #\n");
    printf("*========================================*\n");
    return;
}
void draw_modify_ui(){
    system("cls");
    printf("Please input a book ID:");
    return;
} 
void draw_del_ui(){
    system("cls");
    printf("Please input a book ID:");
    return;
} 

#ifdef __DEBUG_UI__
int main(int argc, char const *argv[])
{
    draw_load_ui();
    draw_main_ui();
    return 0;
}   
#endif
