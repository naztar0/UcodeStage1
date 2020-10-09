#include <stdbool.h>

bool mx_isspace(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == 'r')
        return true;
    return false;
}

bool mx_isdigit(int c) {
    if (c > 47 && c < 59)
        return true;
    return false;
}

int mx_atoi(const char *str) {
    int result = 0;
    bool sign = false;
    if(*str) {
        while(mx_isspace(*str))
            str++;
        if (*str == '-') {
            sign = true;
            str++;   
        }
        else if (*str == '+')
            str++; 
        while (mx_isdigit(*str)) {
            result *= 10;
            if (sign)
                result -= *str - 48;
            else
                result += *str - 48;
            str++;
        }
    }
    return result;
}
