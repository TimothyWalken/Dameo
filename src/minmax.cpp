#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;

void plateau::jouer (color col)
{
	cout<<"jouer"<<endl;
	int maxv=-6000;
	plateau* cp=copie(this);
	int xa=0;
	int xb=0;
	for (int b = 0; b < l; b++)
	{
		for (int a = 0; a < l; a++)
		{
			if (tab[b][a]->c==col)
			{
				cp->initmoveia(a,b,col);
//faut mettre une condition si jamais le coup est possible ou non, fait un !bool {if noeat() && cantmoveforward()}
//pourquoi ça s'arrete à la première valeur proche de l'origine? sinon c'est juste deux armée qui avance l'une face a l'autre 
// le prof prefere une liste de coup possible mais je vois vraiment pas comment faire
				int tmp=min(3,cp,col);

				if (tmp > maxv)
				{
					maxv=tmp;
					xa=a;
					xb=b;
				}

				cp=copie(this);
			}
		}
	}
	initmoveia(xa,xb,col);
}
int plateau::eval(plateau* cp,int profondeur,color col)
{
	int r;
	if (col==color::noir)
	{
		r=evaln(cp,profondeur,col);
	}
	else
	{
		r=evalb(cp,profondeur,col);
	}
	return r;
}
int plateau::evalb(plateau* cp,int profondeur,color col) 
{
	int n=lecture(cp,color::noir);
	int b=lecture(cp,color::blanc);
	if (n==0)
	{
		return -1000+profondeur;
	}
	else if (b==0)
	{
		return 1000-profondeur;
	}
	else
	{
		return b-n;
	}
}

int plateau::evaln(plateau* cp,int profondeur,color col) 
{
	int n=lecture(cp,color::noir);
	int b=lecture(cp,color::blanc);
	if (n==0)
	{
		return (1000-profondeur);
	}
	else if (b==0)
	{
		return (-1000+profondeur);
	}
	else
	{
		return n-b;
	}
}

int plateau::min(int profondeur,plateau* t,color col)
{
	if (profondeur==0 || win())
	{
		return eval(t,profondeur,col);
	}
	else
	{
		int minv= 6000;
		plateau* cp=copie(t);
		for (int b = 0; b < l; b++)
		{
			for (int a = 0; a < l; a++)
			{
				if (tab[b][a]->c==col)
				{
					cp->initmoveia(a,b,col);
					int tmp=max(profondeur-1,cp,col);

					if (tmp < minv)
					{
						minv=tmp;
					}

					cp=copie(t);
				}
			}
		}
		return minv;
	}
}

int plateau::max(int profondeur,plateau* t,color col)
{
	if (profondeur==0 || win())
	{
		return eval(t,profondeur,col);
	}
	else
	{
		int maxv= -6000;
		plateau* cp=copie(t);
		for (int b = 0; b < l; b++)
		{
			for (int a = 0; a < l; a++)
			{
				if (tab[b][a]->c==col)
				{
					cp->initmoveia(a,b,col);
					int tmp=min(profondeur-1,cp,col);

					if (tmp > maxv)
					{
						maxv=tmp;
					}

					cp=copie(t);
				}
			}
		}
		return maxv;
	}
}