/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:45:39 by nsimonov          #+#    #+#             */
/*   Updated: 2016/12/05 22:10:41 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	char	*str;

	str = (char *)big;
	i = 0;
	if (*little == '\0')
		return (str);
	while (str[i])
	{
		if (!(ft_strncmp(&str[i], little, ft_strlen(little))))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
