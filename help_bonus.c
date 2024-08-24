/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:41:40 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/29 22:25:20 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	str_n_compare(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			return (0);
		if (*s1 == 0)
			return (0);
		n--;
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subbstr;
	size_t	i;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s + start);
	subbstr = malloc(len + 1);
	if (!subbstr)
		return (0);
	i = 0;
	while (len - i && start + i < ft_strlen(s))
	{
		*(subbstr + i) = *(s + (start + i));
		i++;
	}
	*(subbstr + i) = '\0';
	return (subbstr);
}

size_t	count_on_me(char const *s, char c)
{
	int	word;
	int	skip;

	skip = 0;
	word = 0;
	while (*s)
	{
		if (*s == c && skip == 1)
			skip = 0;
		if (*s != c && skip == 0)
		{
			word++;
			skip = 1;
		}
		s++;
	}
	return (word);
}

size_t	how_long(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			return (count);
		count++;
		s++;
	}
	return (count);
}
