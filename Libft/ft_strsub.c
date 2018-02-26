/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:19:48 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/20 14:19:49 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sup;

	i = 0;
	sup = ft_strnew(len);
	if (!s)
		return (NULL);
	if (!sup)
		return (NULL);
	while (i < len)
	{
		*(sup + i) = *(s + start + i);
		i++;
	}
	return (sup);
}
