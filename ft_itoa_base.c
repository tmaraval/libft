/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 08:14:11 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/11 10:17:17 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cnt_digit(int nb, int base)
{
	int cnt;

	cnt = 0;
	while (nb != 0)
	{
		nb = nb / base;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa_cpy(int nb, int base, int sign)
{
	int		i;
	char	*ret;
	char	basestr[17];
	int		cnt;

	i = 1;
	cnt = ft_cnt_digit(nb, base);
	ft_strcpy(basestr, "0123456789ABCDEF");
	if (!(ret = (char *)malloc(sizeof(char) * (cnt + sign + 1))))
		return (NULL);
	while (nb != 0)
	{
		ret[cnt + sign - i] = basestr[nb % base];
		nb = nb / base;
		i++;
	}
	if (sign == 1 && base == 10)
		ret[0] = '-';
	ret[cnt + sign] = '\0';
	return (ret);
}

char	*ft_itoa_base(int nb, int base)
{
	int		sign;
	char	*ret;

	sign = (nb < 0);
	if (sign == 1 && base == 10)
		nb = nb * -1;
	if (nb == 0)
	{
		ret = ft_memalloc(2);
		ret[0] = '0';
		return (ret);
	}
	ret = ft_itoa_cpy(nb, base, sign);
	return (ret);
}
