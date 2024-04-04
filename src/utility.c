#include "bsq.h"

// determine the lowest value surrounding bottom-right most value
int lowest_surrounding_value(size_t num1, size_t num2, size_t num3) {
  size_t min = num1;

  if (min > num2) {
    min = num2;
  }
  if (min > num3) {
    min = num3;
  }
  return min;
}

int	ft_atoi(char *str) {
	int sign;
	int val;
	int index;

	sign = 1;
	val = 0;
	index = 0;
	if (!str[index])
		return (0);
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
		val = (10 * val) + ((str[index++]) - '0');
	return (sign * val);
}

size_t ft_strlen(const char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}