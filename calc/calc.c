#include "../lib/myaos.h"
#include <stdint.h>

static int parse_i64(const char* text, int64_t* out) {
    uint64_t value = 0;
    uint8_t negative = 0;
    size_t i = 0;

    if (!text || !text[0] || !out) {
        return -1;
    }

    if (text[i] == '-') {
        negative = 1;
        i++;
    } else if (text[i] == '+') {
        i++;
    }

    if (!text[i]) {
        return -1;
    }

    for (; text[i]; i++) {
        if (text[i] < '0' || text[i] > '9') {
            return -1;
        }
        value = value * 10u + (uint64_t)(text[i] - '0');
    }

    if (negative) {
        *out = -(int64_t)value;
    } else {
        *out = (int64_t)value;
    }
    return 0;
}

static void print_i64(int64_t value) {
    if (value < 0) {
        mya_puts("-");
        mya_put_u64((uint64_t)(-value));
        return;
    }
    mya_put_u64((uint64_t)value);
}

int main(){
  char a_c[64];
  char op_c[64];
  char b_c[64];
  mya_puts("Enter A:");
  mya_console_readline(a_c, sizeof(a_c), 1);
  int a = parse_i64(a_c)*1000000;
  mya_puts("Enter OPERATION:");
  mya_console_readline(op_c, sizeof(op_c), 1);
  mya_puts("Enter B:");
  mya_console_readline(op_c, sizeof(op_c), 1);
};
