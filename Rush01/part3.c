/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igambara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:01:13 by igambara          #+#    #+#             */
/*   Updated: 2020/12/07 09:54:38 by tcarciof         ###   ########.fr       */
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

void	fill_start(int *arr, int *in)
{
	/*riempie tutte le righe e le colonne con le 2 funzioni precedenti*/
	fill_arr_utd(arr, in[0], in[4], 0);
	fill_arr_utd(arr, in[1], in[5], 1);
	fill_arr_utd(arr, in[2], in[6], 2);
	fill_arr_utd(arr, in[3], in[7], 3);
	fill_arr_ltr(arr, in[8], in[12], 0);
	fill_arr_ltr(arr, in[9], in[13], 4);
	fill_arr_ltr(arr, in[10], in[14], 8);
	fill_arr_ltr(arr, in[11], in[15], 12);
}

void	check3_2ltr(int *arr, int pos)
{
	/* se trova come valori esterni 3 a sinistra e 2 a destra controlla il pattern*/
	if (arr[pos + 1] == 2 || arr[pos + 3] == 3)
	{
		arr[pos] = 1;
		arr[pos + 3] = 3;
		arr[pos + 1] = 2;
	}
	else if (arr[pos] == 2 || arr[pos + 3] == 1)
	{
		arr[pos] = 2;
		arr[pos + 1] = 3;
		arr[pos + 3] = 1;
	}
	else if (arr[pos + 3] == 2)
	{
		arr[pos] = 1;
		arr[pos + 1] = 3;
	}
}

void	check2_3ltr(int *arr, int pos)
{
	/*uguale ma con 2 a sinisra e 3 a destra*/
	if (arr[pos + 2] == 2 || arr[pos] == 3)
	{
		arr[pos] = 3;
		arr[pos + 3] = 1;
		arr[pos + 2] = 2;
	}
	else if (arr[pos + 3] == 2 || arr[pos] == 1)
	{
		arr[pos] = 1;
		arr[pos + 2] = 3;
		arr[pos + 3] = 2;
	}
	else if (arr[pos] == 2)
	{
		arr[pos + 3] = 1;
		arr[pos + 2] = 3;
	}
}

void	check2_3utd(int *arr, int pos)
{
	/*uguale ma con 2 in alto e 3 in basso*/
	if (arr[pos + 8] == 2 || arr[pos] == 3)
	{
		arr[pos] = 3;
		arr[pos + 12] = 1;
		arr[pos + 8] = 2;
	}
	else if (arr[pos + 12] == 2 || arr[pos] == 1)
	{
		arr[pos] = 1;
		arr[pos + 8] = 3;
		arr[pos + 12] = 2;
	}
	else if (arr[pos] == 2)
	{
		arr[pos + 12] = 1;
		arr[pos + 8] = 3;
	}
}

void	check3_2utd(int *arr, int pos)
{
	/*uguale ma con 3 in alto e 2 in basso*/
	if (arr[pos + 4] == 2 || arr[pos + 12] == 3)
	{
		arr[pos] = 1;
		arr[pos + 12] = 3;
		arr[pos + 4] = 2;
	}
	else if (arr[pos] == 2 || arr[pos + 12] == 1)
	{
		arr[pos] = 2;
		arr[pos + 4] = 3;
		arr[pos + 12] = 1;
	}
	else if (arr[pos + 12] == 2)
	{
		arr[pos] = 1;
		arr[pos + 4] = 3;
	}
}
