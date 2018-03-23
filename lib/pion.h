enum class color{null,noir,blanc};
enum class kind{men,king,null};

class pion
{
	public:
	color c;
	kind type;

	pion(color,kind);
	~pion();
};
//cout<<"\u25CC "<<endl; pour inserer des symbole unicode