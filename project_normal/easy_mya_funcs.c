#include "../lib/myaos.h"

const char* mya_normal_file_read(char[] name) {
    uint8_t buf[2048 + 1];
    uint32_t size = 0;

    int c = mya_fs_read(name, buf, 2048, &size);
    if (c != 0) {
        return NULL;
    };
    buf[size] = '\0';
    return (const char*)buf
};

const char* mya_normal_input(chat[] prompt){
    mya_puts(prompt);
    buf[100];
    int n = mya_console_readline(buf, sizeof(buf), 1);
    if (n != 0){
        return NULL;
    };
    return (const char*)buf;
};
