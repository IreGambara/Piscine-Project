/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igambara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:20:17 by igambara          #+#    #+#             */
/*   Updated: 2020/12/12 07:58:51 by igambara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_str(char *str)
{
	char *string;

	string = str;
	while (*string != 0)
	{
		write(1, string, 1);
		string++;
	}
	write(1, '\n', 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while(i < argc)
	{
		ft_str(argv[i]);
		i++;
	}
	return(0);
}
