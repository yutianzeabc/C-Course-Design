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

void init_console();//��ʼ������̨
void clear_console();//�������̨
void set_console_pos();//���ÿ���̨λ��
void set_console_cursor();//���ÿ���̨���״̬
void draw_main_ui();//������UI
void draw_load_ui();//���ƶ�ȡUI
void draw_input_ui();//��������UI
void draw_input_sub_ui(int i);//����������UI
void draw_output_ui();//�������UI
void draw_output_sub_ui(int i);//���������UI
void draw_query_ui();//���Ʋ�ѯUI
void draw_query_sub_ui(int i);//���Ʋ�ѯ��UI
void draw_modify_ui();//�����޸�UI
void draw_modify_sub_ui(int i);//�����޸���UI
void draw_del_ui();//����ɾ��UI
void draw_del_sub_ui();//����ɾ����UI

void init_console(){
    system("mode con: cols=46 lines=21");
    system("title ͼ����Ϣ����ϵͳ");
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
    printf("*               ͼ����Ϣ����ϵͳ             *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*                  [1] ¼ ��                 *\n");
    printf("*                                            *\n");
    printf("*                  [2] �� ��                 *\n");
    printf("*                                            *\n");
    printf("*                  [3] �� ѯ                 *\n");
    printf("*                                            *\n");
    printf("*                  [4] �� ��                 *\n");
    printf("*                                            *\n");
    printf("*                  [5] ɾ ��                 *\n");
    printf("*                                            *\n");
    printf("*                  [0] �� ��                 *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("         Please enter your option : ");
    return;
}

void draw_load_ui(){
    clear_console();
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*               ͼ����Ϣ����ϵͳ             *\n");
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
    printf("������������Ŀ��: \n");
    return;
}

void draw_input_sub_ui(int i){
    switch (i){
        case 0:
            printf("��¼��: ");
            return;
        case 1:
            printf("����: ");
            return;
        case 2:
            printf("������: ");
            return;
        case 3:
            printf("�����: ");
            return;
        case 4:
            printf("���浥λ: ");
            return;
        case 5:
            printf("����ʱ��: ");
            return;
        case 6:
            printf("�۸�: ");
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
            printf("��¼��: ");
            return;
        case 1:
            printf("������");
            return;
        case 2:
            printf("������: ");
            return;
        case 3:
            printf("�����: ");
            return;
        case 4:
            printf("���浥λ: ");
            return;
        case 5:
            printf("����ʱ��: ");
            return;
        case 6:
            printf("�۸�: ");
            return;
        default:
            exit(1);
    }
}

void draw_query_ui(){
    clear_console();
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*               ͼ����Ϣ����ϵͳ             *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("*                                            *\n");
    printf("*                  [1] �� ��                 *\n");
    printf("*                                            *\n");
    printf("*                  [2] �� ��                 *\n");
    printf("*                                            *\n");
    printf("*                  [0] �� ��                 *\n");
    printf("*                                            *\n");
    printf("*============================================*\n");
    printf("         Please enter your option : ");
    return;
}

void draw_query_sub_ui(int i){
    clear_console();
    switch (i){
        case 0:
            printf("������ͼ�����: \n");
            return;
        case 1:
            printf("������ͼ������: \n");
            return;
        default:
            exit(1);
    }
    
    return;
}

void draw_modify_ui(){
    clear_console();
    printf("������ͼ���¼��: \n");
    return;
} 

void draw_modify_sub_ui(int i){
    switch (i){
        case 0:
            printf("��¼��: ");
            return;
        case 1:
            printf("����: ");
            return;
        case 2:
            printf("������: ");
            return;
        case 3:
            printf("�����: ");
            return;
        case 4:
            printf("���浥λ: ");
            return;
        case 5:
            printf("����ʱ��: ");
            return;
        case 6:
            printf("�۸�: ");
            return;
        default:
            exit(1);
    }
}

void draw_del_ui(){
    clear_console();
    printf("������ͼ���¼��: \n");
    return;
}

void draw_del_sub_ui(){
    printf("ȷ��ɾ��(Y/N): ");
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
