/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanasser <nanasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:26:48 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/04 20:56:22 by nanasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freemem(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	*arr = NULL;
}

static int	counting_words(const char *s, char c, const char **last_pos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	*last_pos = s + i;
	return (count);
}

static void	allocating(char **arr, char const *s, char c)
{
	char		**toarr;
	char const	*sptr;

	toarr = arr;
	sptr = s;
	while (*sptr)
	{
		while (*s == c)
			s++;
		sptr = s;
		while (*sptr && *sptr != c)
			sptr++;
		if (*sptr == c || sptr > s)
		{
			*toarr = ft_substr(s, 0, sptr - s);
			if (!toarr)
			{
				freemem(arr, toarr - arr);
				return ;
			}
			s = sptr;
			toarr++;
		}
	}
	*toarr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	int			size;
	const char	*last_pos;

	if (!s)
		return (NULL);
	size = counting_words(s, c, &last_pos);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	allocating(arr, s, c);
	return (arr);
}
