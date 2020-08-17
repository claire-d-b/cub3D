#include "cub3D.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (0);
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	return (ptr);
}

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return(0);
}

int	ft_atoi(const char *str)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	if (res == -2147483648)
		return (res);
	if (j < 0)
		res = res * j;
	return (res);
}

static int	len_int(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	else if (n <= 2147483647 && n > -2147483648)
	{
		if (n == 0)
			return (1);
		if (n < 0)
		{
			n = -n;
			i += 1;
		}
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

static int	ft_pow(int nb, int pow)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < pow)
	{
		res = res * nb;
		i++;
	}
	return (res);
}

const char		*ft_itoa(int n)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (n == -2147483648)
		return ((const char *)ft_strjoin("-2147483648", ""));
	i = -1;
	k = n;
	j = len_int(k);
	if (!(str = malloc(sizeof(char) * (len_int(n) + 1))))
		return (0);
	n = (n < 0) ? -n : n;
	while (j-- > 0)
		if (i++ <= len_int(k))
			str[j] = ((n / ft_pow(10, i)) % 10) + '0';
	str[len_int(k)] = '\0';
	str[0] = (k < 0) ? '-' : str[0];
	return ((const char *)str);
}

char	*revstr(char *str)
{
	size_t i;
	size_t j;
	char *newstr;

	j = 0;
	i = ft_strlen(str) + 1;
	if (!(newstr = malloc(sizeof(char) * i)))
		return (0);
	while (i - 1 > 0)
	{
		newstr[j] = str[--i - 1];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

char	*to_hex(unsigned long long n, char *base)
{
	int i;
	char *str;
	unsigned long long k;

	k = n;
	i = 0;
	while (k > 0)
	{
		k = k / ft_strlen(base);
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (n > 0)
	{
		str[i] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		i++;
	}
	str[i] = '\0';
	str = revstr(str);
//	printf("to hex %s\n", str);
	return (str);
}