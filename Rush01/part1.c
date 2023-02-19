/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:20:25 by tcarciof          #+#    #+#             */
/*   Updated: 2020/12/07 09:49:03 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	phase_three(int *arr);
void	check(int l, int r, int *lim);
void	check1(int l, int r, int *lim);
void	fill_arr_ltr(int *arr, int l, int r, int pos);
void	fill_arr_utd(int *arr, int u, int d, int pos);
void	fill_start(int *arr, int *in);
void	check3_2ltr(int *arr, int pos);
void	check2_3ltr(int *arr, int pos);
void	check2_3utd(int *arr, int pos);
void	check3_2utd(int *arr, int pos);
void	check3_1ltr(int *arr, int pos);
void	check3_1utd(int *arr, int pos);
void	check1_3ltr(int *arr, int pos);
void	check1_3utd(int *arr, int pos);
void	check1_2ltr(int *arr, int pos);
void	check1_2utd(int *arr, int pos);
void	check2_1ltr(int *arr, int pos);
void	check2_1utd(int *arr, int pos);
void	phase_two(int *arr, int *in, int *i);
void	copy(int *n, int *n1);
int		add_row(int *arr, int pos);
int		add_col(int *arr, int pos);
void	find(int *arr, int *pos, int *ndir, int *found);
void	condi1(int *arr1, int *arr2, int *pos, int temp);
void	condi2(int *arr1, int *arr2, int *pos, int temp);
void	duplicator (int *arr1, int *arr2);
void	boss_mode(int *arr, int *in);
int		main(int argc, char **argv);

void	print_tab(int *tab)
/*Prende un array di dimensione 16 e lo stampa, ogni 4 caratteri l'if si attiva e manda a capo il testo*/
{
	char	c;
	int		i;

	i = -1;
	while (++i < 16)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
	}
}

void	print_found(int *tab)
{
	/* funzione inutilizzata era per il debug*/
	char	c;
	int		i;

	i = -1;
	while (++i < 2)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	input_in(int *arr, int temp, int pos)
/*Questa assegna il valore passatole in temp all'array iin posizione pos, usata per riempire l'array in degli input al posto che guardare argv*/
{
	arr[pos] = temp;
}

void	check_row(int *b)
/*Questa funzione controlla che tutti i valori delle 4 file siano diversi tra di loro*/
{
	int i[2];
	int a;

	i[0] = -1;
	i[1] = 0;
	while (++i[0] < 4)
	{
		a = i[0] * 4;
		if (b[a] != b[a + 1] && b[a] != b[a + 2]
				&& b[a] != b[a + 3] && b[a + 1] != b[a + 2]
				&& b[a + 1] != b[a + 3] && b[a + 2] != b[a + 3])
		{
			if (b[a] == 0 || b[a + 1] == 0 || b[a + 2] == 0 || b[a + 3] == 0)
			{
				if (b[a] == 0)
					b[a] = 10 - (b[a + 1] + b[a + 2] + b[a + 3]);
				if (b[a + 1] == 0)
					b[a + 1] = 10 - (b[a] + b[a + 2] + b[a + 3]);
				if (b[a + 2] == 0)
					b[a + 2] = 10 - (b[a + 1] + b[a] + b[a + 3]);
				if (b[a + 3] == 0)
					b[a + 3] = 10 - (b[a + 1] + b[a + 2] + b[a]);
			}
		}
	}
}

void	check_col(int *b)
/*Stessa cosa ma per le colonne*/
{
	int i[2];
	int a;

	i[0] = -1;
	i[1] = 0;
	while (++i[0] < 4)
	{
		a = i[0];
		if (b[a] != b[a + 4] && b[a] != b[a + 8] && b[a] != b[a + 12]
				&& b[a + 4] != b[a + 8]
				&& b[a + 4] != b[a + 12] && b[a + 8] != b[a + 12])
		{
			if (b[a] == 0 || b[a + 4] == 0 || b[a + 8] == 0 || b[a + 12] == 0)
			{
				if (b[a] == 0)
					b[a] = 10 - (b[a + 4] + b[a + 8] + b[a + 12]);
				if (b[a + 4] == 0)
					b[a + 4] = 10 - (b[a] + b[a + 8] + b[a + 12]);
				if (b[a + 8] == 0)
					b[a + 8] = 10 - (b[a + 4] + b[a] + b[a + 12]);
				if (b[a + 12] == 0)
					b[a + 12] = 10 - (b[a + 4] + b[a + 8] + b[a]);
			}
		}
	}
}
