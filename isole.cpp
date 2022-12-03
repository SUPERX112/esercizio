#include <iostream>

class isola
{
public:

	explicit isola( int spazio[5][11]){for(int x=0; x!=5; ++x) for(int j=0; j!=11; ++j) k[x][j]=spazio[x][j];}
	void stampa(){for(int x=0; x!=5; ++x){std::cout<<std::endl; for(int j=0; j!=11; ++j) std::cout<<k[x][j]<<" ";}}
	inline int get_val(int indice1, int indice2){return k[indice1][indice2];}
	void set_val(int indice1, int indice2, int val){k[indice1][indice2]=val;}

	bool controllo_2(int indice1, int indice2);
	void controllo_1(int indice1, int indice2);
	void setta(int indice1, int indice2);
	void setta2(int indice1,int indice2);
	void conta_1();
	friend std::ostream& operator<<(std::ostream& os,const isola& a);


	void trova(int zona[5][11]);

private:

	int isole=0;
	int k[5][11];

};
std::ostream& operator << (std::ostream& os,const isola& a){os<<a.isole; return os;}


bool isola::controllo_2(int x, int j)
{
	if(get_val(x,j)==2){return true;}
	return false;
}

void isola::controllo_1(int x, int j)
{
	for(int x=0; x!=5; ++x)
		for(int u=0; u!=11; ++u)
			if(get_val(x,j)==1)
				if(get_val(x,j+1)==3 && get_val(x-1,j+1)==1) set_val(x-1, j+1,0);
}

void isola::setta(int x, int j)
{
	if(get_val(x,j+1)==1) set_val(x,j+1, 2);
	if(get_val(x,j-1)==1) set_val(x,j-1, 2);
	if(get_val(x+1,j)==1) set_val(x+1,j, 2);
	if(get_val(x-1,j)==1)  set_val(x-1,j, 2);
}

void isola::setta2(int x, int j)
{
	set_val(x,j+1,3);
	set_val(x,j,3);
	set_val(x+1,j,3);
}

void isola::conta_1()
{
	for(int x=0; x!=5; ++x)
		for(int u=0; u!=11; ++u)
			if(get_val(x,u)==1)
				++isole;
}

void isola::trova(int zona[5][11])
{
	for(int x=0; x!=5; ++x)
		for(int u=0; u!=11; ++u)
		{
			if(zona[x][u]==1)
			{
				if (!(controllo_2(x,u)))
				{
					setta(x,u);

				}
			}

		}
	for(int x=0; x!=5; ++x)
		for(int u=0; u!=11; ++u)
		{
				if (controllo_2(x,u))
				{
					setta2(x,u);

				}
		}
	for(int x=0; x!=5; ++x)
		for(int u=0; u!=11; ++u)
		{
			controllo_1(x,u);
		}
	conta_1();

}



int main()
{
	int a[5][11]{{0,0,0,0,0,0,0,0,0,1,1},
				 {0,1,0,0,0,0,0,0,0,0,0},
				 {1,0,0,0,0,0,0,1,1,0,0},
				 {0,1,1,1,1,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,1,1,0,1}};

	isola kl(a);
	kl.stampa();
	kl.trova(a);
	std::cout<<"\n\n";
	std::cout<<"le isole in totale sono: "<<kl;

}

