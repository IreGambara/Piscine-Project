/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:53:18 by tcarciof          #+#    #+#             */
/*   Updated: 2020/12/07 09:56:00 by tcarciof         ###   ########.fr       */
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
void	find(int *arr, int *pos, int n, int dir);
void	condi1(int *arr1, int *arr2, int *pos, int temp);
void	condi2(int *arr1, int *arr2, int *pos, int temp);
void	duplicator (int *arr1, int *arr2);
void	boss_mode(int *arr, int *in);
int		main(int argc, char **argv);

void	check1_2utd(int *arr, int pos)
{
	if (arr[pos + 4] == 1 || arr[pos + 8] == 2)
	{
		arr[pos + 4] = 1;
		arr[pos + 8] = 2;
	}
	if (arr[pos + 4] == 2 || arr[pos + 8] == 1)
	{
		arr[pos + 4] = 2;
		arr[pos + 8] = 1;
	}
}

void	check2_1ltr(int *arr, int pos)
{
	if (arr[pos + 2] == 1 || arr[pos + 1] == 2)
	{
		arr[pos + 2] = 1;
		arr[pos + 1] = 2;
	}
	if (arr[pos + 2] == 2 || arr[pos + 1] == 1)
	{
		arr[pos + 2] = 2;
		arr[pos + 1] = 1;
	}
}

void	check2_1utd(int *arr, int pos)
{
	if (arr[pos + 8] == 1 || arr[pos + 4] == 2)
	{
		arr[pos + 8] = 1;
		arr[pos + 4] = 2;
	}
	if (arr[pos + 8] == 2 || arr[pos + 4] == 1)
	{
		arr[pos + 8] = 2;
		arr[pos + 4] = 1;
	}
}

void	phase_two(int *arr, int *in, int *i)
{
	/* chima le funzioni precedenti 20 volte in totale*/
	i[1] = -1;
	while (++i[1] < 20)
	{
		i[0] = -1;
		while (++i[0] < 4)
		{
			if (in[8 + i[0]] == 3 && in[12 + i[0]] == 2)
				check3_2ltr(arr, i[0] * 4);
			if (in[0 + i[0]] == 3 && in[4 + i[0]] == 2)
				check3_2utd(arr, i[0]);
			if (in[8 + i[0]] == 2 && in[12 + i[0]] == 3)
				check2_3ltr(arr, i[0] * 4);
			if (in[0 + i[0]] == 2 && in[4 + i[0]] == 3)
				check2_3utd(arr, i[0]);
			if (in[8 + i[0]] == 3 && in[12 + i[0]] == 1)
				check3_1ltr(arr, i[0] * 4);
			if (in[0 + i[0]] == 3 && in[4 + i[0]] == 1)
				check3_1utd(arr, i[0]);
			if (in[8 + i[0]] == 1 && in[12 + i[0]] == 3)
				check1_3ltr(arr, i[0] * 4);
			if (in[0 + i[0]] == 1 && in[4 + i[0]] == 3)
				check1_3utd(arr, i[0]);
		}
	}
}

void	copy(int *n, int *n1)
{i
	/*copia i primi 16 valori di un array in un altro*/
	int i;

	i = -1;
	while (++i < 16)
	{
		n1[i] = n[i];
	}
}
