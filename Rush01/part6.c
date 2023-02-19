/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:06:43 by tcarciof          #+#    #+#             */
/*   Updated: 2020/12/07 09:58:20 by tcarciof         ###   ########.fr       */
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

int		add_row(int *arr, int pos)
{
	/*fa la sommma di tutti i valori su una fila e la ritorna*/
	int sum;

	sum = arr[pos] + arr[pos + 1] + arr[pos + 2] + arr[pos + 3];
	return (sum);
}

int		add_col(int *arr, int pos)
{
	/* fa la somma di tutti i valori su una colonna e la ritorna*/
	int sum;

	sum = arr[pos] + arr[pos + 4] + arr[pos + 8] + arr[pos + 12];
	return (sum);
}

void	find(int *arr, int *pos, int *ndir, int *found)
{
	/*cerca gli 0 e inserisce la loro posizione in un array*/
	if (arr[ndir[0]] == 0)
	{
		pos[*found] = ndir[0];
		pos[2 + *found] = arr[ndir[0]];
		*found = *found + 1;
	}
	if (arr[ndir[0] + ndir[1]] == 0)
	{
		pos[*found] = (ndir[0] + ndir[1]);
		pos[2 + *found] = arr[ndir[0] + ndir[1]];
		*found = *found + 1;
	}
	if (arr[ndir[0] + (ndir[1] * 2)] == 0)
	{
		pos[*found] = (ndir[0] + ndir[1] * 2);
		pos[2 + *found] = arr[ndir[0] + (ndir[1] * 2)];
		*found = *found + 1;
	}
	if (arr[ndir[0] + (ndir[1] * 3)] == 0)
	{
		pos[*found] = (ndir[0] + ndir[1] * 3);
		pos[2 + *found] = arr[ndir[0] + (ndir[1] * 3)];
		*found = *found + 1;
	}
}

void	condi1(int *arr1, int *arr2, int *pos, int temp)
{
	/*una delle funzioni che dovrebbe duplicare i casi in 2 array diversi*/
	if (temp == 7)
	{
		arr1[pos[0]] = 1;
		arr1[pos[1]] = 2;
		arr2[pos[0]] = 2;
		arr2[pos[1]] = 1;
	}
	if (temp == 5 && (pos[2] == 1 || pos[2] == 4))
	{
		arr1[pos[0]] = 2;
		arr1[pos[1]] = 3;
		arr2[pos[0]] = 3;
		arr2[pos[1]] = 2;
	}
	if (temp == 5 && (pos[2] == 2 || pos[2] == 3))
	{
		arr1[pos[0]] = 1;
		arr1[pos[1]] = 4;
		arr2[pos[0]] = 4;
		arr2[pos[1]] = 1;
	}
}

void	condi2(int *arr1, int *arr2, int *pos, int temp)
{
	/* uguale a quella sopra con casi diversi per stare in 25 righe*/
	if (temp == 6)
	{
		arr1[pos[0]] = 3;
		arr1[pos[1]] = 1;
		arr2[pos[0]] = 1;
		arr2[pos[1]] = 3;
	}
	if (temp == 4)
	{
		arr1[pos[0]] = 2;
		arr1[pos[1]] = 4;
		arr2[pos[0]] = 4;
		arr2[pos[1]] = 2;
	}
	if (temp == 3)
	{
		arr1[pos[0]] = 2;
		arr1[pos[1]] = 3;
		arr2[pos[0]] = 3;
		arr2[pos[1]] = 2;
	}
}
