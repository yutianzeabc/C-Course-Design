#pragma once

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

#ifndef __STR_H__
    #define __STR_H__
    #include <string.h>  
#endif

struct book{
    char regist[20],name[20],author[20],type[20],publish[20],publish_time[20],price[20];
    struct book *forward,*back;
    char* quality[7];
};