/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igambara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:58:25 by igambara          #+#    #+#             */
/*   Updated: 2020/11/29 19:20:21 by igambara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	function(int r, int c, int x, int y)
{
	if ((r == 1 && c == 1) || (r == y && c == x && x != 1 && y != 1))
		ft_putchar('/');
	else if ((r == 1 && c == x) || (r == y && c == 1))
		ft_putchar(92);
	else if ((r == 1 || r == y) && (c > 1 && c < x))
		ft_putchar('*');
	else if ((r > 1 && r < y) && (c == 1 || c == x))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	r;
	int c;

	if (x > 0 && y > 0)
	{
		r = 1;
		while (r <= y)
		{
			c = 1;
			while (c <= x)
			{
				function(r, c, x, y);
				c++;
			}
			ft_putchar('\n');
			r++;
		}
	}
}
