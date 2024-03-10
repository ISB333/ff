/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:35 by isb3              #+#    #+#             */
/*   Updated: 2024/03/10 11:04:51 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	free_memory(char **array)
{
	int	j;

	j = 0;
	while (array[j])
		j++;
	while (j-- > 0)
		free(array[j]);
	free(array);
}

void	ff(char *str, ...)
{
	va_list	args;
	int		i;

	i = -1;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				perror(va_arg(args, char *));
			else if (str[i] == 'a')
				free_memory(va_arg(args, char **));
			else if (str[i] == 's')
				free(va_arg(args, char *));
			else if (str[i] == 'i')
				free(va_arg(args, int *));
		}
	}
	va_end(args);
}
