#ifndef __STDIO_H__
    #define __STDIO_H__
    # include <stdio.h>
#endif
#ifndef __STDLIB_H__
    #define __STDLIB_H__  
    # include <stdlib.h>
#endif

FILE *file_open_(){
    return fopen("books.db","a+");
}

int file_close(FILE *stream_db){
    if (fclose(stream_db)==0) return 0;
    else return 1;
}