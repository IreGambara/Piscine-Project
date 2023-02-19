/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igambara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:09:57 by igambara          #+#    #+#             */
/*   Updated: 2020/11/29 19:45:26 by igambara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int r;
	int c;

	if (x > 0 && y > 0)
	{
		r = 0;
		while (r++ <= y)
		{
			c = 0;
			while (c++ <= x)
			{
				if ((r == 1 && c == 1) || (r == 1 && c == x))
					ft_putchar('A');
				else if ((r == y && c == 1) || (r == y && c == x))
					ft_putchar('C');
				else if ((c > 1 && c < x) && (r == 1 || r == y))
					ft_putchar('B');
				else if ((c == 1 || c == x) && (r > 1 && r < y))
					ft_putchar('B');
				else
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
	}
}
