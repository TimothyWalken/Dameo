#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;
plateau::plateau()
{
	l=8;
	tab=new pion **[l];
	for (int i = 0; i < l; i++)
	{
		tab[i]=new pion *[l];
		for (int j = 0; j < l; j++)
		{
		//pion noir
			if (i==0)
			{
				tab[i][j]=new pion(color::noir,kind::men);
			}
			else if (i==1)
			{
				if (j>0 && j<l-1)
				{
					tab[i][j]=new pion(color::noir,kind::men);
				}
				else
				{
					tab[i][j]=new pion(color::null,kind::null);
				}
			}
			else if (i==2)
			{
				if (j>1 && j<l-2)
				{
					tab[i][j]=new pion(color::noir,kind::men);
				}
				else
				{
					tab[i][j]=new pion(color::null,kind::null);
				}
			}
		//pion blanc			
			else if (i==l-3)
			{
				if (j>1 && j<l-2)
				{
					tab[i][j]=new pion(color::blanc,kind::men);
				}
				else
				{
					tab[i][j]=new pion(color::null,kind::null);
				}
			}
			else if (i==l-2)
			{
				if (j>0 && j<l-1)
				{
					tab[i][j]=new pion(color::blanc,kind::men);
				}
				else
				{
					tab[i][j]=new pion(color::null,kind::null);
				}
			}

			else if (i==l-1)
			{
				tab[i][j]=new pion(color::blanc,kind::men);
			}
			else
			{
				tab[i][j]=new pion(color::null,kind::null);
			}
		}
	}

}

pion::pion(color x,kind y)
{
	c=x;
	type=y;
}

void plateau::affichage()
{
	cout<<endl;
	for (int i = 0; i <= l; i++)
	{
		for (int j = 0; j <= l; j++)
		{
			if (i<l&& j<l)
			{
				if (tab[i][j]->c==color::blanc)
				{
					cout<<"\u25CF ";
				}
				else if (tab[i][j]->c==color::noir)
				{
					cout<<"\u25CB ";
				}
				else
				{
					cout<<"\u25CC ";
				}
			}
			else if (i==l)
			{
				cout<<j<<" ";
			}

		}
		if (i<l)
		{
			cout<<i<<endl;
		}
	}
	cout<<endl;	
}

void plateau::eat(int x,int y)
{
	tab[y][x]=new pion(color::null,kind::null);
}
void plateau::place(int x,int y, color col)
{
	tab[y][x]=new pion(col,kind::men);
}

plateau* plateau::copie(plateau* t)
{
	plateau* cp=new plateau();
	for (int b = 0; b < 8; b++)
	{
		for (int a = 0; a < 8; a++)
		{
			cp->tab[b][a]=t->tab[b][a];
			cp->l=t->l;
		}
	}
	return (cp);
}