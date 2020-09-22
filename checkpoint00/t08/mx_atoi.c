#include <stdbool.h>

int mx_atoi(const char *str)
{
  	int sign = 0;
  	int digit = 0;
  	for (unsigned int i = 0; str[i]; ++i) {
    	if (!(str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')) {
      		if (str[i] >= 48 && str[i] <= 57)
        		digit = digit * 10 + (str[i] - '0');
      		else if ((str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == '\v' || str[i + 1] == '\f' || str[i + 1] == '\r' || str[i + 1] == ' ') && str[i] == '-')
        		return 0;
      		else {
        		if (str[i] == '-') {
          			if (sign == 0)
          				sign = 1;
          			else 
          				return sign == 1 ? -digit : digit;
        		}
        		else
        			return sign == 1 ? -digit : digit;
      		}
    	}
  	}
  	return sign == 1 ? -digit : digit;
}
