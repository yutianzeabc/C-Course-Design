#ifndef __STDIO_H__
    #define __STDIO_H__
    # include <stdio.h>
#endif
#ifndef __STDLIB_H__
    #define __STDLIB_H__  
    # include <stdlib.h>
#endif

FILE *file_open(){
    FILE *stream_db;
    stream_db=fopen("books.db","r+");
    return stream_db;
}

void file_close(FILE *stream_db){
    fclose(stream_db);
    return;
}