/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:26:48 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/11 02:12:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../swap.h"

static int	count_words(char const *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char const *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char **ft_split(char const *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}

// static int	counting_words(char const *s, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i])
// 		{
// 			count++;
// 			while (s[i] && s[i] != c)
// 				i++;
// 		}
// 	}
// 	return (count);
// }

// static void	allocating(char **arr, char const *s, char c)
// {
// 	char		**toarr;
// 	char const	*sptr;

// 	toarr = arr;
// 	sptr = s;
// 	if (toarr == 0)
// 		toarr++;
// 	while (*sptr)
// 	{
// 		while (*s == c)
// 			s++;
// 		sptr = s;
// 		while (*sptr && *sptr != c)
// 			sptr++;
// 		if (*sptr == c || sptr > s)
// 		{
// 			*toarr = ft_substr(s, 0, sptr - s);
// 			s = sptr;
// 			toarr++;
// 		}
// 	}
// 	*toarr = NULL;
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**arr;
// 	int		size;

// 	if (!s)
// 		return (NULL);
// 	size = counting_words(s, c);
// 	arr = malloc(sizeof(char *) * (size + 1));
// 	allocating(arr + 1, s, c);
// 	return (arr);
// }

