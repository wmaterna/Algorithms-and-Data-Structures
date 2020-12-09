#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctype.h>
#define SIZE_OF_GRAPH 10
 
using namespace std;

class GrafNieskierowanyTablica{
public:
	int actualsize=0;
	int edges=0;
	int elements[SIZE_OF_GRAPH]={0};
	bool
	neighbors[SIZE_OF_GRAPH][SIZE_OF_GRAPH]={0};

void AddElement(int element_1){
	bool thereIs=false;
	for(int i=0; i<=actualsize; i++)
	{
		if(elements[i]==element_1){
		   thereIs=true;
			break;
			
		}
	}
		   if(thereIs==false){
			elements[actualsize]=element_1;
			actualsize++;
			
		}
}
void AddEdge(int elem_1, int elem_2){
	int i=0;
	while(i<actualsize){
		if(elem_1==elements[i])
			break;
		i++;
	}
	int j=0;
	while(j<actualsize){
		if(elem_2==elements[j])
			break;
		j++;
	}
	edges++;
	neighbors[i][j]=1;
	neighbors[j][i]=1;
}
void DeleteEdge(int elem_1, int elem_2){
	int i=0;
	while(i<actualsize){
		if(elem_1==elements[i])
			break;
		i++;
	}
	int j=0;
	while(j<actualsize){
		if(elem_2==elements[j])
			break;
		j++;
	}
	
	neighbors[i][j]=0;
	neighbors[j][i]=0;
}
void DeleteElement(){
	actualsize--;
}
void enter(int x, int y){
	AddElement(x);
	AddElement(y);
	AddEdge(x, y);
}
void print()
{
	int k;
	int degreeCounter;
	for(int j=0; j<actualsize; j++)
	{	k=0;
		degreeCounter=0;
		cout<<"Wierzchołek o wartości "<<elements[j]<<endl;
		cout<<"jest połączony z wierzchołkami o wartości: ";
		while(k<actualsize)
		{
			if(neighbors[j][k]){
				cout<<elements[k]<<" ";
				degreeCounter++;
				
			}
			k++;
		}
		cout<<"Stopień wierzchołka: "<<degreeCounter<<endl;
		cout<<endl<<endl;
		
	}
}
};
void nieskierowanyTablica(){
	string x,y;
	int tmp1,tmp2;
	int N,K;
	cout<<"Ile wierzchołków ma ten graf?: "<<endl;
	cin>>N;
	cout<<"Ile krawędzi ma ten graf?: "<<endl;
	cin>>K;
	GrafNieskierowanyTablica g;
	cout<<"Proszę wprowadzać liczby tak, jak są połączone ze sobą krawędzią. Jeżeli wystepuje krawędz między np 13--12--2, wprowadzamy 13 12 [enter] 12 2 itd. jeżeli chcemy zakończyć wpisywanie wprowadzamy 'q'. Wielkość grafu ustawiona jest na 10, tyle maksymalnie różnych wierzchołków można wprowadzić, mozna mniej "<<endl;
	while(N!=g.actualsize && K!=g.edges)
	{
		cout<<"Para: "<<endl;
		cin>>x;
		cin>>y;
		tmp1=atoi(x.c_str());
		tmp2=atoi(y.c_str());
		g.enter(tmp1,tmp2);
	}
	g.print();
	
}
 int main(int argc, const char * argv[]) {
	
	nieskierowanyTablica();
	return 0;
 }

