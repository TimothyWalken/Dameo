#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;

void plateau::deplacement(color col)
{
	int x,y=0;
	cout<<"coordonnées ? "<<endl;
	cout<<" x ? ";
	cin>>x;
	cout<<endl;
	cout<<" y ? ";
	cin>>y;
	cout<<endl;
	if (tab[y][x]->c==col)
	{
		move(x,y,col);
	}
	else
	{
		deplacement(col);
	}

}

void plateau::move(int x, int y, color col)
{
	//idée de andreas: déplacement avec les touches zqsd et a,e pour les diagonales 
	char d;
	cout<<"quel direction voulez vous prendre? ";
	cin>>d;
	switch(d)
	{
		case 'a':
			mdiagog(x,y,col);
			break;
		case 'e'://||'E' a tester:
			cout<<"alabama"<<endl;
			mdiagod(x,y,col);
			break;
		case 'z':
			mup(x,y,col);
			break;
		case 'q':
			mleft(x,y,col);
			break;
		case 'd':
			mright(x,y,col);
			break;
		case 's':
			mdown(x,y,col);
			break;
	}
}

void plateau::mdiagog(int x, int y,color col)
{
	cout<<"ohaio"<<endl;
	if(x-1>=0)
	{
		if(col==color::noir)
		{
			//doit mouv x-1 y+1
			if (isfree(x-1,y+1))
			{
				place(x-1,y+1,col);
				eat(x,y);
				return;
			}
			else
			{
				if (!isanenemy(x-1,y+1,col))
				{
					int a=x;
					int b=y;
					while(b<l && a>=0)
					{
						if(isfree(a,b))
						{
							eat(x,y);
							place(a,b,col);
							return;
						}
						a=a-1;
						b=b+1;
					}
				}
				cout<<"erreur"<<endl;
				move(x,y,col);
				return;
			}
		}
		if(col==color::blanc)
		{
			if (isfree(x-1,y-1))
			{
				place(x-1,y-1,col);
				eat(x,y);
				return;
			}
			else
			{
				if (!isanenemy(x-1,y-1,col))
				{
					int a=x;
					int b=y;
					while(b<l && a>=0)
					{
						if(isfree(a,b))
						{
							eat(x,y);
							place(a,b,col);
							return;
						}
						a=a-1;
						b=b-1;
					}
				}
			cout<<"erreur"<<endl;
			move(x,y,col);
			return;
			}
		}
	}
	else
	{
		cout<<"erreur"<<endl;
		move(x,y,col);
		return;
	}

}

void plateau::mdiagod(int x,int y,color col)
{
	if(x+1<l)
	{
		if(col==color::noir)
		{
			//doit mouv x+1 y+1
			if (isfree(x+1,y+1))
			{
				place(x+1,y+1,col);
				eat(x,y);
				return;
			}
			else
			{
				if (!isanenemy(x-1,y+1,col))
				{
					int a=x;
					int b=y;
					while(b<l && a>=0)
					{
						if(isfree(a,b))
						{
							eat(x,y);
							place(a,b,col);
							return;
						}
						a=a-1;
						b=b+1;
					}
				}
				cout<<"erreur"<<endl;
				move(x,y,col);
				return;
			}
		}
		if(col==color::blanc)
		{
			//doit mouv x+1 y-1
			if (isfree(x+1,y-1))
			{
				place(x+1,y-1,col);
				eat(x,y);
				return;
			}
			else
			{ //remettre le if isanenemy sur l'autre diagonal
				if(!isanenemy(x+1,y-1,col))
				{
					int a=x;
					int b=y;
					while(a<l && b>=0)
					{
						if(isfree(a,b))
						{
							eat(x,y);
							place(a,b,col);
							return;
						}
						a=a+1;
						b=b-1;
					}
					cout<<"erreur"<<endl;
					move(x,y,col);
					return;
				}
			}
		}	
	}
	else
	{
		cout<<"erreur"<<endl;
		move(x,y,col);
		return;
	}
}

void plateau::mup(int x,int y, color col)
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
				cout<<"erreur"<<endl;
				move(x,y,col);
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
			cout<<"erreur"<<endl;
			move(x,y,col);
			return;
		}
	}
}

void plateau::mdown(int x,int y, color col)
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
			cout<<"erreur1"<<endl;
			move(x,y,col);
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
				cout<<"je rentre la"<<endl;
				for(int i=y; i<l;i++)
				{
					cout<<"x= "<<x<<endl;
					cout<<"i= "<<i<<endl;
					color d=tab[i][x]->c;//tab[y][x]
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
					if(isfree(x,i))
					{
						eat(x,y);
						place(x,i,col);
						return;
					}
				}
			}
			cout<<"erreur2"<<endl;
			move(x,y,col);
			return;
		}
	}
}

void plateau::mleft(int x,int y, color col)
{
	if(isanenemy(x-1,y,col)&&isfree(x-2,y))
	{
		eat(x-1,y);//eat remet la case selectionné à null
		place(x-2,y,col);
		eat(x,y);
		return;
	}
	else
	{
		if(!isfree(x-1,y) && !isanenemy(x-1,y,col))
		{
			for(int i=x; x>=0;x--)
			{
				if(isfree(i,y))
				{
					eat(x,y);
					place(i,y,col);
				}
			}
		}
		cout<<"erreur"<<endl;
		move(x,y,col);
		return;
	}
}

void plateau::mright(int x,int y, color col)
{
	if (y+1<l)
	{	
		if(isanenemy(x+1,y,col)&&isfree(x+2,y))
		{
			eat(x+1,y);//eat remet la case selectionné à null
			place(x+2,y,col);
			eat(x,y);
			return;
		}
		else
		{
			if(!isfree(x+1,y) && !isanenemy(x+1,y,col))
			{
				for(int i=x; x<l;x++)
				{
					if(isfree(i,y))
					{
						eat(x,y);
						place(i,y,col);
					}
				}
			}
			else
			{
			cout<<"erreur"<<endl;
			move(x,y,col);
			return;
			}
		}

	}
	else
	{
		cout<<"erreur"<<endl;
		move(x,y,col);
		return;
	}
}

/*bool plateau::pasmieux(int x, int y, color col)// ca servait a quoi deja?
{
	if (y-2>=0)
	{
		if (isanenemy(x,y-1,col) && isfree(x,y-2))
		{
			return false;
		}
	}
	else if (y+2<l)
	{
		if (isanenemy(x,y+1,col) && isfree(x,y+2))
		{
			return false;
		}
	}
	else if (x-2>=0)
	{
		if (isanenemy(x-1,y,col) && isfree(x-2,y))
		{
			return false;
		}
	}
	else if (x+2>=0)
	{
		if (isanenemy(x+1,y,col) && isfree(x+2,y))
		{
			return false;
		}
	}
}*/
//dans les fonctions de mouvement,quand le coup est un simple deplacement, faire la verif qu'il n'y a pas possibilité de manger ailleurs