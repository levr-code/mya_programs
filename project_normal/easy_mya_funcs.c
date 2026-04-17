#include "../lib/myaos.h"

const char* mya_file_read_new(char[] name, uint32_t size) {
    uint8_t * buf = malloc(size*sizeof(uint8_t));
    uint32_t size = 0;

    int c = mya_fs_read(name, buf, size, &size);
    if (c != 0) {
        return NULL;
    };
    buf[size] = '\0';
    return (const char*)buf
};

const char* mya_input_new(char[] prompt){
    mya_puts(prompt);
    char * buf = malloc(100 * sizeof(char));
    int n = mya_console_readline(buf, sizeof(buf), 1);
    if (n != 0){
        return NULL;
    };
    return (const char*)buf;
};
