#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;

void plateau::initmoveia(int x, int y, color col)
{
	if (tab[y][x]->c==col)
	{
		if(noeat(x,y,col))//marche pas
		{
			if (col==color::noir)
			{
				mdownia(x,y,col);
			}
			else
			{
				mupia(x,y,col);
			}
		}
		else
		{
			pile* b=new pile;
			b->debut=new coor (x,y,col);
			eatia(x,y,col,b);
		}
	}
}
pile* plateau::eatia(int x, int y ,color col, pile* backtrack)
{
	pile* u=backtrack;
	pile* d=backtrack;
	pile* l=backtrack;
	pile* r=backtrack;
	if(noeat(x,y,col))
	{
		backtrack->fin=new coor(x,y,col);
		return (backtrack);// retourne la pile sans changement pour relacher l'effet ressort
	}
	else 
	{
		if (upeat(x,y-1,col) && poss(x,y-1,backtrack))
		{
			u->insercoo(x,y-1,col);//insere les coordonnées a la suite de la pile avant de l'envoyer à la suite
			u->tete+=1;// on augmente l'indice de possibilité
			u=eatia(x,y-2,col,u);
		}
		else if (downeat(x,y+1,col) && poss(x,y+1,backtrack))//exemple avec le cas "haut"
		{
			d->insercoo(x,y+1,col);//insere les coordonnées a la suite de la pile avant de l'envoyer à la suite
			d->tete+=1;// on augmente l'indice de possibilité
			d=eatia(x,y+2,col,d);
		}
		else if (lefteat(x-1,y,col) && poss(x-1,y,backtrack))//exemple avec le cas "haut"
		{
			l->insercoo(x-1,y,col);//insere les coordonnées a la suite de la pile avant de l'envoyer à la suite
			l->tete+=1;// on augmente l'indice de possibilité
			l=eatia(x-2,y,col,l);
		}
		else if (righteat(x+1,y,col) && poss(x+1,y,backtrack))//exemple avec le cas "haut"
		{
			r->insercoo(x+1,y,col);//insere les coordonnées a la suite de la pile avant de l'envoyer à la suite
			r->tete+=1;// on augmente l'indice de possibilité
			r=eatia(x+2,y,col,r);
		}
	}
	return (maxia(u,d,l,r));//determine quel pile sera la plus grande
}

void plateau::lectureia(pile* backtrack)
{
	coor* p= backtrack->tete;
	coor* f= backtrack->fin;
	coor* d= backtrack->debut;

	while (p !=NULL)
		{
			eat(p->x,p->y);
			p=p->suiv;
		}
		eat(d->x,d->y);
	place(f->x,f->y,f->col);
}

pile* plateau::maxia(pile* u,pile* d, pile* l,pile* r)
{
	pile* res=u;
	if (res->tete < d->tete)
	{
		res=d;	
	}
	if (res->tete < l->tete)
	{
		res=l;	
	}
	if (res->tete < r->tete)
	{
		res=r;	
	}
	return res;
}
void plateau::mdownia(int x,int y, color col)
{
	if(col==color::blanc)
	{
		if (y+1<l)
		{
			if(isanenemy(x,y+1,col) && isfree(x,y+2))
			{
				eat(x,y+1);//eat remet la case selectionné à null
				place(x,y+2,col);
				eat(x,y);
			}
		}
		else
		{
			return;
		}
	}
	if(col==color::noir)
	{
		if (isanenemy(x,y+1,col) && isfree(x,y+2))
		{
			eat(x,y+1);//eat remet la case selectionné à null
			place(x,y+2,col);
			eat(x,y);
			return;
		}
		else if (isfree(x,y+1))
		{
			place(x,y+1,col);
			eat(x,y);
			return;
		}
		else
		{
			if(!isfree(x,y+1) && !isanenemy(x,y+1,col))
			{
				for(int i=y; i<l;i++)
				{
					if (isanenemy(x,i,col))
					{
						return;
					}
					if(isfree(x,i))
					{
						eat(x,y);
						place(x,i,col);
						return;
					}
				}
			}
			return;
		}
	}
}
void plateau::mupia(int x,int y, color col)
{
	if(col==color::noir)
	{
		if (y-2>=0)
		{
			if(isanenemy(x,y-1,col) && isfree(x,y-2))
			{
				eat(x,y-1);//eat remet la case selectionné à null
				place(x,y-2,col);
				eat(x,y);
			}
			else
			{
				return;
			}
		}
	}
	if(col==color::blanc)
	{
		if (isanenemy(x,y-1,col) && isfree(x,y-2))
		{
			eat(x,y-1);//eat remet la case selectionné à null
			place(x,y-2,col);
			eat(x,y);
			return;
		}
		else if (isfree(x,y-1))
		{
			//faire la verif si y a pas un meilleur coup ici.
			place(x,y-1,col);
			eat(x,y);
			return;
		}
		else
		{
			if(!isfree(x,y-1) && !isanenemy(x,y-1,col))
			{
				for(int i=y; y>=0;y--)
				{
					if(isfree(x,i))
					{
						eat(x,y);
						place(x,i,col);
					}
				}
			}
			return;
		}
	}
}