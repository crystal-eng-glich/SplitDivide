#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

char **devide(char* str, int size) {
    char** a = NULL;
    char* temp = NULL;
    int i = 0;
    int j = 0;
    int l = 0;
    int flag = 0;
    a = (char**)malloc(sizeof(char*) * 5);
    for (i = 0; i < size;) {
        if (str[i] == '_'&&!flag) {    //分隔符
            temp = (char*)malloc(i + 1 - l);    //加结束符
            memset(temp, 0, i + 1 - l);
            memcpy(temp, str + l, i - l);
            a[j] = temp;
            j++;
            if (j >= 5) {
                break;
            }
            i++;
            l = i;
            continue;
        }else if (str[i] == '\"') {
            if (flag) {
                temp = (char*)malloc(i + 1 - l);    //加结束符
                memset(temp, 0, i + 1 - l);
                memcpy(temp, str + l, i - l);
                a[j] = temp;
                j++;
                if (j >= 5) {
                    break;
                }
                l = i + 2;
                i++;
            }
            else {
                l++;
            }
            flag = !flag;
        }
        i++;
    }
    return a;
}

void main() {
    int i = 0;
    char* str = "ab_c_\"abc_adadfasd\"_def_\"dddd\"";
    int size = strlen(str);
    char** a = devide(str, size);
    for (i = 0; i < 5; i++) {
        printf("%s\n", a[i]);
    }

    /*内存释放*/
    for (i = 0; i < 5; i++) {
        free(a[i]);
        a[i] = NULL;
    }
    free(a);
    a = NULL;
}
