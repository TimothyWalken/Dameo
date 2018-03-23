#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;

bool plateau::isfree(int x,int y)
{
	if (tab[y][x]->c==color::null)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool plateau::isanenemy(int x,int y, color col)
{
	if (tab[y][x]->c!=col)
	{
		if (tab[y][x]->c!=color::null)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
bool plateau::noeat(int x,int y, color col)
{
	int cmp=0;
	if (y+2<l)
	{
		if (isanenemy(x,y+1,col) && isfree(x,y+2))
		{
			cmp++;
		}
	}
	else if (x+2<l)
	{
		if (isanenemy(x+1,y,col) && isfree(x+2,y))
		{
			cmp++;
		}
	}
	else if (y-2>=0)
	{
		if (isanenemy(x,y-1,col) && isfree(x,y-2))
		{
			cmp++;
		}
	}
	else if (x-2>=0)
	{
		if (isanenemy(x-1,y,col) && isfree(x-2,y))
		{
			cmp++;
		}
	}
	if (cmp!=0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool plateau::win()
{
	int b=0;
	int n=0;
	for (int j = 0; j < l; j++)
	{
		for (int i = 0; i < l; i++)
		{
			pion* p=tab[j][i];
			if (p->c==color::noir)
			{
				n++;
			}
			else if (p->c==color::blanc)
			{
				b++;
			}
		}
	}
	if (n>0 && b>0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool plateau::upeat(int a,int b,color col)
{
	if (b-1>=0)
	{
		if (isanenemy(a,b,col))
		{
			if(isfree(a,b-1))
			{
				return true;
			}
		}	
	}
	return false;
}

bool plateau::downeat(int a,int b,color col)
{
	if (b+1<l)
	{
		if (isanenemy(a,b,col))
		{
			if(isfree(a,b+1))
			{
				return true;
			}
		}	
	}
	return false;
}
bool plateau::lefteat(int a,int b,color col)
{
	if (a-1>=0)
	{
		if (isanenemy(a,b,col))
		{
			if(isfree(a-1,b))
			{
				return true;
			}
		}	
	}
	return false;
}
bool plateau::righteat(int a,int b,color col)
{
	if (a+1<l)
	{
		if (isanenemy(a,b,col))
		{
			if(isfree(a+1,b))
			{
				return true;
			}
		}	
	}
	return false;
}

bool plateau::poss(int a,int b,pile* c)
{
	if (c->tete)
	{
		coor* tmp=c->tete;
		while(0)
		{
			if (tmp->x==a)
			{
				if (tmp->y==b)
				{
					return false;
				}
			}
			else
			{
				if (tmp->suiv)
				{
					tmp=tmp->suiv;
				}
				else
				{
					return true;
				}
			}
		}
	}
}