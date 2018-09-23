/*************************************************************************
	> File Name: your_printf.c
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 六  9/22 20:25:59 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int64_t temp = va_arg(arg, int32_t), x = 0, time = 0;
    //3,int64_t保证位数足够。
                        if (temp < 0) {
                            putchar('-');
                            temp *= -1;
                        }
                        //2，va_arg(arg, int)的话(int类型)，读入负号会崩溃。
                        while (temp) {
                            x = x * 10 + temp % 10;
                            temp /= 10;
                            time ++;
                        }
                        while (time) {
                            putchar(x % 10 + '0');
                            x /= 10;
                            time --;
                        }    //1，改用次数记录读入读出，数字末端的0得以输出
                    } break;
                    default :
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]);
                        exit(1);
                }
            } break;
            default:
                putchar(frm[i]);
        }
    }
    return cnt;
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 1200);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
