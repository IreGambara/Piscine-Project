/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:25:43 by tcarciof          #+#    #+#             */
/*   Updated: 2020/12/07 10:02:01 by tcarciof         ###   ########.fr       */
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

void	duplicator(int *arr1, int *arr2)
{
	/* funzione che dati 2 array dovrebbe trovare 1 e riempire quella casella con un valore possibile in arr1 e in arr2 láltro valore possibile e poi lavorare sui 2 array per motivi di tempo non funziona del tutto e fa solo alcuni casi*/
	int temp;
	int pos[4];
	int ndir[2];
	int found;

	found = 0;
	ndir[0] = 0;
	ndir[1] = 4;
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
	pos[3] = 0;
	temp = add_row(arr1, 0);
	temp = add_col(arr1, 0);
	find(arr1, pos, ndir, &found);
	condi1(arr1, arr2, pos, temp);
	condi2(arr1, arr2, pos, temp);
}

void	boss_mode(int *arr, int *in)
{
	/*questa funzione crea 2 array sostitutivi su cui operare e li passa a duplicator problema dovrei ripetere questo procedimento fino a che la tabella non e'piena ma non sono riuscito a implementarlo per tempo*/
	int arr1[16];
	int arr2[16];
	int j[2];

	j[0] = 0;
	j[1] = 4;
	copy(arr, arr1);
	copy(arr, arr2);
	duplicator(arr1, arr2);
	phase_two(arr1, in, j);
	phase_three(arr1);
	phase_two(arr2, in, j);
	phase_three(arr2);
}
