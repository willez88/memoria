#include <iostream>
#include <cstring>
using namespace std;
struct Memoria
{
	char tex[20];
};
bool verificar(Memoria *);
void mostrar(Memoria *);

int main()
{
	Memoria texto[4][4], memo[4][4];
	char jugador1[20], jugador2[20];
	int f, c, f1, c1, band1=0, band2=0, Q, R;
	bool continuar=true, continuar2=true, y=true;
	char a;

	strcpy(texto[0][0].tex, "Perro  ");
	strcpy(texto[0][1].tex, "Conejo ");
	strcpy(texto[0][2].tex, "Tortuga");
	strcpy(texto[0][3].tex, "Loro   ");
	strcpy(texto[1][0].tex, "Delfin ");
	strcpy(texto[1][1].tex, "Hormiga");
	strcpy(texto[1][2].tex, "Ballena");
	strcpy(texto[1][3].tex, "Morza  ");
	strcpy(texto[2][0].tex, "Loro   ");
	strcpy(texto[2][1].tex, "Tortuga");
	strcpy(texto[2][2].tex, "Ballena");
	strcpy(texto[2][3].tex, "Delfin ");
	strcpy(texto[3][0].tex, "Hormiga");
	strcpy(texto[3][1].tex, "Perro  ");
	strcpy(texto[3][2].tex, "Morza  ");
	strcpy(texto[3][3].tex, "Conejo ");

	strcpy(memo[0][0].tex, "-------");
	strcpy(memo[0][1].tex, "-------");
	strcpy(memo[0][2].tex, "-------");
	strcpy(memo[0][3].tex, "-------");
	strcpy(memo[1][0].tex, "-------");
	strcpy(memo[1][1].tex, "-------");
	strcpy(memo[1][2].tex, "-------");
	strcpy(memo[1][3].tex, "-------");
	strcpy(memo[2][0].tex, "-------");
	strcpy(memo[2][1].tex, "-------");
	strcpy(memo[2][2].tex, "-------");
	strcpy(memo[2][3].tex, "-------");
	strcpy(memo[3][0].tex, "-------");
	strcpy(memo[3][1].tex, "-------");
	strcpy(memo[3][2].tex, "-------");
	strcpy(memo[3][3].tex, "-------");

	cout<<"Juego Memoria Hecho por William Paez "<<endl;
	cout<<"Nombre del 1er jugador: ";
	cin>> jugador1;
	cout<<"Nombre del 2do jugador: ";
	cin>> jugador2;
	while(y==true)
	{
		while(continuar)
		{
			mostrar(&memo[0][0]);
			while(continuar2)
			{
				cout<<endl<<jugador1<<": Especifique la fila y la columna de la figura 1: ";
				cin>> f; cin>> c;
				f-=1;
				c-=1;
				Q=strcmp(memo[f][c].tex, "-------");
				if(Q==0)
					continuar2=false;
			}
			strcpy(memo[f][c].tex, texto[f][c].tex);
			mostrar(&memo[0][0]);
			continuar2=y;
			while(continuar2)
			{
				cout<<endl<<jugador1<<": Especifique la fila y la columna de la figura 2: ";
				cin>> f1; cin>> c1;
				f1-=1;
				c1-=1;
				Q=strcmp(memo[f1][c1].tex, "-------");
				if(Q==0)
					continuar2=false;
			}
			strcpy(memo[f1][c1].tex, texto[f1][c1].tex);
			mostrar(&memo[0][0]);
			cout<<endl<<jugador1<<": "<<band1<<" Aciertos "<<endl;
			cout<<endl<<jugador2<<": "<<band2<<" Aciertos "<<endl;
			//termina el juego
			Q=strcmp(texto[f][c].tex, texto[f1][c1].tex);
			R=strcmp(texto[f1][c1].tex, texto[f][c].tex);
			if((Q==0)||(R==0))
			{
				strcpy(memo[f][c].tex, texto[f][c].tex);
				strcpy(memo[f1][c1].tex, texto[f1][c1].tex);
				band1++;
				continuar=verificar(&memo[0][0]);
				cout<<"Presione una tecla para continuar: "<<endl<<endl;
			}
			else
			{
				strcpy(memo[f][c].tex, "-------");
				strcpy(memo[f1][c1].tex, "-------");
				continuar=false;
			}
			cout<<endl<<jugador1<<": "<<band1<<" Aciertos "<<endl;
			cout<<endl<<jugador2<<": "<<band2<<" Aciertos "<<endl;
			y=verificar(&memo[0][0]);
			continuar2=y;
		}
		cout<<endl<<"Presione una tecla para continuar "<<endl<<endl;
		continuar2=continuar=y;
		while(continuar)
		{
			mostrar(&memo[0][0]);
			while(continuar2)
			{
				cout<<endl<<jugador2<<": Especifique la fila y la columna de la figura 1: ";
				cin>> f; cin>> c;
				f-=1;
				c-=1;
				Q=strcmp(memo[f][c].tex, "-------");
				if(Q==0)
					continuar2=false;
			}
			strcpy(memo[f][c].tex, texto[0][0].tex);
			mostrar(&memo[0][0]);
			continuar2=y;
			while(continuar2)
			{
				cout<<endl<<jugador2<<": Especifique la fila y la columna de la figura 2: ";
				cin>> f1; cin>> c1;
				f1-=1;
				c1-=1;
				Q=strcmp(memo[f1][c1].tex, "-------");
				if(Q==0)
					continuar2=false;
			}
			strcpy(memo[f1][c1].tex, texto[f1][c1].tex);
			mostrar(&memo[0][0]);
			//termina el juego
			Q=strcmp(texto[f][c].tex, texto[f1][c1].tex);
			R=strcmp(texto[f1][c1].tex, texto[f][c].tex);
			if((Q==0)||(R==0))
			{
				strcpy(memo[f][c].tex, texto[f][c].tex);
				strcpy(memo[f1][c1].tex, texto[f1][c1].tex);
				band2++;
				continuar=verificar(&memo[0][0]);
				cout<<endl<<"Presione una tecla para continuar "<<endl<<endl;
			}
			else
			{
				strcpy(memo[f][c].tex, "-------");
				strcpy(memo[f1][c1].tex, "-------");
				continuar=false;
			}
			cout<<endl<<jugador1<<": "<<band1<<" Aciertos "<<endl;
			cout<<endl<<jugador2<<": "<<band2<<" Aciertos "<<endl;
			y=verificar(&memo[0][0]);
			continuar2=y;
		}
		continuar=y;
		cout<<endl<<"Presione una tecla para continuar "<<endl<<endl;
	}
	if(band1>4)
		cout<<"El Jugador: "<<jugador1<<" es el GANADOR "<<endl;
	else
		if(band1<4)
			cout<<"El jugador: "<<jugador2<<" es el GANADOR "<<endl;
		else
			if(band1==band2)
				cout<<"Los jugadores: "<<jugador1<<" y "<<jugador2<<" EMPATAN "<<endl;
	return 0;
}
void mostrar(Memoria *M)
{
	int a=0, b=0;
	cout<<"---------------------------------------------------"<<endl;
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			a++;
			cout<<"  "<<(M+i*4+j)->tex<<"  ";
			if(a==1)
			{
				cout<<"| ";
				a=0;
			}
		}
		cout<<endl;
		b++;
		if(b==1)
		{
			cout<<"---------------------------------------------------"<<endl;
			b=0;
		}
	}
}
bool verificar(Memoria *M)
{
	int x=0, q;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			q=strcmp((M+i*4+j)->tex, "-------");
			if(q!=0)
			x++;
		}
	}
	if(x==16)
		return (false);
	else
		return (true);
}
