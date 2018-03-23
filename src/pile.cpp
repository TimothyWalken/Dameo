#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;

pile::pile()
{
	n=0;
	tete=NULL;
	fin=NULL;
	debut=NULL;
}

coor::coor(int a, int b, color c)
{
	x=a;
	y=b;
	col=c;
	suiv=NULL;
}

pile::~pile()
{}

coor::~coor()
{}

void pile::insercoo(int x, int y, color col)
{
	coor* nouv=new coor(x,y,col);
	if (tete)
	{
		coor* p=tete;
		while (p->suiv)
		{
			p=p->suiv;
		}
		p->suiv=nouv;
		n++;
	}
	else
	{
		tete=nouv;
		n++;
	}
}