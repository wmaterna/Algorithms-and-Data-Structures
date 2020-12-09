#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctype.h>
#define SIZE_OF_GRAPH 100

using namespace std;


class GrafSkierowanyTablica{
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
	
	neighbors[i][j]=1;
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
	edges++;
	neighbors[i][j]=0;
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
		cout<<"wchodzi do wierzchołków o wartości: ";
		while(k<actualsize)
		{
			if(neighbors[j][k]){
				cout<<elements[k]<<" ";
				degreeCounter++;

			}
			k++;
		}
		cout<<endl;
		cout<<"Ilosc (stopień) krawędzi wychodzących z wierzchołka "<<degreeCounter<<endl;
		cout<<"Do wierzchołka wchodzą: ";
		
		k=0;
		degreeCounter=0;
		while(k<actualsize)
		{
			if(neighbors[k][j]){
				cout<<elements[k]<<" ";
				degreeCounter++;

			}
			k++;
		}
		cout<<endl;
		cout<<"Ilośc krawędzi (stopień) wchodzących do wierzchołka: "<<degreeCounter<<endl;
		cout<<endl<<endl;
		
	}
}
};
GrafSkierowanyTablica skierowanyTablica(int edges){
	string x,y;
	int tmp1,tmp2;
	
	GrafSkierowanyTablica g;
	cout<<"Proszę wprowadzać liczby tak, jak są połączone ze sobą krawędzią. Jeżeli wystepuje krawędz między np 13--12--2, wprowadzamy 13 12 [enter] 12 2 itd.  Wielkość grafu ustawiona jest na 100, tyle maksymalnie różnych wierzchołków można wprowadzić, mozna mniej "<<endl;
	while(edges>0)
	{
		cout<<"Para: "<<endl;
		cin>>x;
		cin>>y;
		tmp1=atoi(x.c_str());
		tmp2=atoi(y.c_str());
		g.enter(tmp1,tmp2);
		edges--;
		
	}
	g.print();
	return g;
}


int noIntoNeighbours(bool tab[SIZE_OF_GRAPH][SIZE_OF_GRAPH], int vertexes){
	
	int j=0;
	for (int i=0;i<vertexes; i++) {
			for (j=0; j<vertexes; j++) {
				if (tab[j][i]==true){
					break;
				}
			} if(j==vertexes){
				return i;
			}
			
		
	}
	return -1000;
}
			
void topologicalSort(GrafSkierowanyTablica g1, int edges, int vertexes){
	int currentIndex = 0;
	int K=vertexes;
	while(vertexes!=0){
		currentIndex = noIntoNeighbours(g1.neighbors, K);
		cout<<g1.elements[currentIndex]<<" ";
		for(int i=0; i<K; i++){
			g1.neighbors[currentIndex][i]=false;
			g1.neighbors[currentIndex][currentIndex]=true;
		}
		vertexes--;
		
		
	}
	
}


int main(int argc, const char * argv[]) {
	
	int N,K;
	cout<<"Ile wierzchołków ma ten graf?: "<<endl;
	cin>>N;
	cout<<"Ile krawędzi ma ten graf?: "<<endl;
	cin>>K;
	GrafSkierowanyTablica g1 = skierowanyTablica(K);
	cout<<"Wynik sortowanie topologicznego: "<<endl;
	topologicalSort(g1, K ,N);
	
	return 0;
}

