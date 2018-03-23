#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;
void plateau::partie()
{
	affichage();
	while(!win())
	{
		for (int i = 1; i; i++)
		{
			if (i%2!=0)
			{
				jouer(color::blanc);
				affichage();
				/*color d=tab[2][5]->c;//tab[y][x]
				if (d==color::blanc)
				{
					cout<<"blanc"<<endl;
				}
				else if (d==color::null)
				{
					cout<<"vide"<<endl;
				}
				else if (d==color::noir)
				{
					cout<<"noir"<<endl;
				}
				else
				{
					cout<<"erreur suspecte"<<endl;
				}
				bool t=isanenemy(2,5,color::blanc);
				cout<<t<<endl;*/
			}
			else
			{
				cout<<"je passe à l'adversaire"<<endl;
				jouer(color::noir);
				affichage();
			}
			char a;
			cin>>a;
		}
	}
}

int plateau::lecture(plateau* cp,color col)
{
	int cmp=0;
	for (int b = 0; b < cp->l; b++)
	{
		for (int a = 0; a < cp->l; a++)
		{
			if (cp->tab[b][a]->c==col)
			{
				cmp++;
			}
		}
	}
	return cmp;
}