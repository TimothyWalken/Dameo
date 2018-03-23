#include "../lib/pion.h"
#include "../lib/plateau.h"
#include "../lib/pile.h"
#include <iostream>

using namespace std;
int main()
{
	system("sl");
	system("clear");
	plateau *game=new plateau();
	game->partie();
	cout<<endl;
	return(0);
}