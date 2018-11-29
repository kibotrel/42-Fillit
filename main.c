#include <stdio.h>

int main(int ac, char **av)
{
	char *tab[4];
	int i;
	int neighboor;
	int x;
	int y;

	i = -1;
	x = -1;
	neighboor = 0;
	if (ac != 5)
		return (0);
	tab[0] = av[1];
	tab[1] = av[2];
	tab[2] = av[3];
	tab[3] = av[4];
	printf("Voici la piece entrée\n====================\n");
	while (++i <=3)
		printf("%s\n", tab[i]);
	printf("====================\n");
	while (++x < 4)
	{
		printf("%s\n", tab[x]);
		y = -1;
		while(++y < 4)
		{		
			printf("\t%c : position [%d][%d]\n", tab[x][y], x, y);
			if(tab[x][y] == '#')
			{
				if (x == 0 && y == 0 && (tab[x][y+1] == '#' && tab[x+1][y] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}	
				else if (x == 0 && y < 3 && (tab[x][y+1] == '#' && tab[x][y-1] == '#')
				|| (tab[x+1][y] == '#' && tab[x+1][y+1] == '#')
				|| (tab[x+1][y] == '#' && tab[x+1][y-1] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}	
				else if (x == 0 && y == 3 && (tab[x][y-1] == '#' && tab[x+1][y] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}
				else if (x < 3 && y == 0 && (tab[x][y+1] == '#' && tab[x-1][y] == '#')
				|| (tab[x+1][y] == '#' && tab[x][y+1] == '#')
				|| (tab[x+1][y] == '#' && tab[x-1][y] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}
				else if (x < 3 && y < 3 && (tab[x-1][y] == '#' && tab[x][y-1] == '#')
				|| (tab[x-1][y] == '#' && tab[x][y+1] == '#')
				|| (tab[x-1][y] == '#' && tab[x+1][y] == '#')
				|| (tab[x+1][y] == '#' && tab[x][y-1] == '#')
				|| (tab[x+1][y] == '#' && tab[x][y+1] == '#')
				|| (tab[x][y-1] == '#' && tab[x][y+1] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}
				else if (x < 3 && y == 3 && (tab[x-1][y] == '#' && tab[x+1][y] == '#')
				|| (tab[x-1][y] == '#' && tab[x][y-1] == '#')
				|| (tab[x+1][y] == '#' && tab[x][y-1] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}
				else if (x == 3 && y == 0 && (tab[x-1][y] == '#' && tab[x][y+1] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}
				else if (x == 3 && y < 3 && (tab[x][y-1] == '#' && tab[x][y+1] == '#')
				|| (tab[x-1][y] == '#' && tab[x][y+1] == '#')
				|| (tab[x-1][y] == '#' && tab[x][y-1] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}
				else if (x == 3 && y == 3 && (tab[x][y-1] == '#' && tab[x-1][y] == '#'))
				{
					neighboor++;
					printf("\t\t\t+1 voisin, total voisin actuel : %d\n",neighboor);
				}
			}
		}
	}
	printf("Il y a %d voisins\n===================\n", neighboor);
	printf("D'après les calculs précédents, la pièce envoyée est un carré de 2x2\n");	
	return (0);
}
