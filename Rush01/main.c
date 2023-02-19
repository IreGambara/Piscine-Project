/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:49:06 by tcarciof          #+#    #+#             */
/*   Updated: 2020/12/07 10:03:52 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		main(int argc, char **argv)
{
	int i;
	int j[2];
	int arr[16];
	int in[16];

	i = -1;
	j[0] = 0;
	j[1] = 4;
	while (++i < 16)
		/* qui passiamo i valori in posizione pari dellárgv nellárray in con la funzione input_in*/
	{
		input_in(in, (int)argv[argc - 1][0 + 2 * i] - 48, i);
		arr[i] = 0;
	}
	fill_start(arr, in);//riempio l'array di 0
	phase_two(arr, in, j);//metto i primi valori in base ai valori esterni
	phase_three(arr);//check the pattern
	boss_mode(arr, in);//se non finito duplica i casi finche non worka idealmente
	print_tab(arr);// stampa la tabella
}
