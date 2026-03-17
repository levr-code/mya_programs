#include "../lib/myaos.h"

char[] mya_normal_file_read(char[] name) {
    static uint8_t buf[2048 + 1];
    uint32_t size = 0;

    int c = mya_fs_read(name, buf, 2048, &size);
    if (c != 0) {
        return NULL;
    };
    buf[size] = '\0';
    return (const char*)buf
};
