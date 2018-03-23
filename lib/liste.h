class liste
{
public:
	coup* tete;
	liste();
	~liste();
	
};

class coup
{
public:
	int x;
	int y;
	char c;
	coup* suiv;
	coup();
	~coup();
	
};