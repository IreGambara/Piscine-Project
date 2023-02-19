/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfashaj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:06:02 by mfashaj           #+#    #+#             */
/*   Updated: 2020/12/07 09:52:39 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_tab(int *tab);
void	print_found(int *tab);
void	input_in(int *arr, int temp, int pos);
void	check_row(int *arr);
void	check_col(int *arr);
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

void	phase_three(int *arr)
{
	/* funzione che laciava il check delle colonne e delle righe dsiverse volte ma e'inutile visto che le 2 funzioni non fanno nulla nei casi che trovano YES ITS MY FAULT*/
	int i[2];

	i[0] = 0;
	i[1] = -1;
	while (++i[0] < 16)
	{
		check_col(arr);
		check_row(arr);
	}
}

void	check(int l, int r, int *lim)
{
	/*funzione del vecchio programma qui non fa un cazzo*/
	if (l == 3 && r == 2)
	{
		lim[1] = 15;
		lim[0] = 4;
	}
	if (l == 3 && r == 1)
	{
		lim[1] = 27;
		lim[0] = 16;
	}
	if (l == 1 && r == 4)
	{
		lim[1] = 31;
		lim[0] = 28;
	}
	if (l == 1 && r == 3)
	{
		lim[1] = 43;
		lim[0] = 32;
	}
	if (l == 1 && r == 2)
	{
		lim[1] = 51;
		lim[0] = 44;
	}
}

void	check1(int l, int r, int *lim)
{
	/*funzione del vecchio programma qui non fa un cazzo*/
	if (l == 4 && r == 1)
	{
		lim[1] = 3;
		lim[0] = 0;
	}
	if (l == 2 && r == 1)
	{
		lim[1] = 59;
		lim[0] = 52;
	}
	if (l == 2 && r == 2)
	{
		lim[1] = 83;
		lim[0] = 60;
	}
	if (l == 2 && r == 3)
	{
		lim[1] = 95;
		lim[0] = 84;
	}
}

void	fill_arr_ltr(int *arr, int l, int r, int pos)
{
	/*riempie l'array da sinnistra a destra passando i valori esterni*/
	if (l == 4 && r == 1)
	{
		arr[pos] = 1;
		arr[pos + 1] = 2;
		arr[pos + 2] = 3;
	}
	if (l == 1)
		arr[pos] = 4;
	if (l == 1 && r == 2)
		arr[pos + 3] = 3;
	if (l == 3 && r == 2)
		arr[pos + 2] = 4;
	if (r == 1)
		arr[pos + 3] = 4;
	if (l == 2 && r == 1)
		arr[pos] = 3;
	if (l == 2 && r == 3)
		arr[pos + 1] = 4;
	if (l == 1 && r == 4)
	{
		arr[pos] = 4;
		arr[pos + 1] = 3;
		arr[pos + 2] = 2;
		arr[pos + 3] = 1;
	}
}

void	fill_arr_utd(int *arr, int u, int d, int pos)
{
	/*riempie l'array dallálto al basso guardando i valori esterni*/
	if (u == 4 && d == 1)
	{
		arr[pos] = 1;
		arr[pos + 4] = 2;
		arr[pos + 8] = 3;
	}
	if (u == 1)
		arr[pos] = 4;
	if (u == 1 && d == 2)
		arr[pos + 12] = 3;
	if (u == 3 && d == 2)
		arr[pos + 8] = 4;
	if (d == 1)
		arr[pos + 12] = 4;
	if (u == 2 && d == 1)
		arr[pos] = 3;
	if (u == 2 && d == 3)
		arr[pos + 4] = 4;
	if (u == 1 && d == 4)
	{
		arr[pos] = 4;
		arr[pos + 4] = 3;
		arr[pos + 8] = 2;
		arr[pos + 12] = 1;
	}
}
