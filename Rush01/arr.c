#include <stdio.h>
#include <unistd.h>

void fill(int *tab)
{
	int tab1[96]= {1, 2, 3, 4, 1, 2, 4, 3, 1,3,4,2 ,  2,3,4,1 , 2,3,1,4 , 2,1,3,4 , 1,3,2,4 , 4,3,2,1 , 4,1,3,2 , 4,2,3,1 , 4,3,1,2 , 4,1,2,3 , 4,2,1,3 , 3,1,2,4 , 3,2,1,4 , 1,4,2,3 , 2,4,1,3 , 3,4,1,2 , 2,1,4,3 , 3,1,4,2 , 3,2,4,1 , 1,4,3,2 , 2,4,3,1 , 3,4,2,1};
	int i=0;
	while (i<96)
	{	//printf("%d, ",tab1[i][j]);
	tab[i] = tab1[i];
	//tab++;
	//printf("\n");
	i++;
	}
}

void check(int l,int r,int *lim)
{
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

void check1(int l,int r,int *lim)
{
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

void	input_in(int *arr,int temp, int pos, int *lim)
{
	int i;

	arr[pos] = temp;
	i = 0;
	while (++i < 7-1)
		lim[i] = 0;
}

void man_array(int *tab, int flag, int *src, int *lim)
{
	int i;

	i = -1;
	lim[3] = lim[0] - 1;
	lim[4] = lim[3] + 4;
	lim[5] = lim[2] * 4;
	lim[6] = ((lim[2] + 1) * 4) - 1;
	if( flag == 0)
	{
		while (++i < 16)
			tab[i] = 0;
	}
	else 
	{
		while (++i < 16)
			src[i] = tab[i];
	}
	return ;
}

void rec(int *tab, int *lim, int *in, int *yikes)
{
	int act[16];
	int i;
	char c;
	if (lim[2]==5)
		return;
	check(in[8 + lim[2]], in[12 + lim[2]], lim);
	check1(in[8 + lim[2]], in[12 + lim[2]], lim);
	i = 1;
	man_array(act, 0, act, lim);

	while ((i + lim[3]) < lim[4] + 1)
	{
		act[lim[5] + i] = tab[lim[3] + i];
		c = act[lim[5] + i] + '0';
		write(1,&c,1);
		i++;
	}
	write(1,"\n",1);	
	lim[2]++;
	rec(tab,lim,in,act);
}

int main (int argc, char **argv)

{

	int tab[96];
	int i =0;
	int lim[7];
	int in[16];

	fill(tab);
	while (i < 15)
	{
		input_in(in,(int) argv[1][0 + 2 * i]-48,i,lim);
		i++;	
	}
	rec (tab,lim,in,tab);
	return 0;
}
