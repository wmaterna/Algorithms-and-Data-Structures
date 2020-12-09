#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctype.h>
#define SIZE_OF_GRAPH 5

using namespace std;


class GrafSkierowanyTablica{
public:
	int actualsize=0;
	int edges=0;
	int elements[SIZE_OF_GRAPH]={0};
	int
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
	void AddEdge(int elem_1, int elem_2, int value){
		neighbors[elem_1][elem_2]=value;
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
	void enter(int x, int y, int value){
		AddElement(x);
		AddElement(y);
		AddEdge(x, y, value);
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
GrafSkierowanyTablica skierowanyTablica(){
	
	GrafSkierowanyTablica g;
	g.enter(0,1,5);
	g.enter(0,2,1000);
	g.enter(0,3,1000);
	g.enter(1,0,50);
	g.enter(1,2,15);
	g.enter(1,3,5);
	g.enter(2,0,30);
	g.enter(2,1,1000);
	g.enter(2,3,15);
	g.enter(3,0,15);
	g.enter(3,1,1000);
	g.enter(3,2,5);
	return g;
	
}
void floydAlgorytm(GrafSkierowanyTablica g, int nOfElements){
	int
	path[SIZE_OF_GRAPH][SIZE_OF_GRAPH]={0};
	for (int k=0; k<nOfElements; k++){
		for (int i=0; i<nOfElements; i++){
			for(int j=0; j<nOfElements; j++){
				if(g.neighbors[i][k] + g.neighbors[k][j] <g.neighbors[i][j]){
					g.neighbors[i][j] = g.neighbors[i][k] + g.neighbors[k][j];
					path[i][j] = k;
				}
			}
			
			
		}
	}
	cout<<"Tabela przedstawiająca wagi poszczególnych ścieżek wg algorytmu Floyda (wiersze - wierzchołek wyściowey kolumny wierzchołek docelowy) "<<endl;
	for (int k=0; k<nOfElements; k++){
		for (int i=0; i<nOfElements; i++){
			cout<<g.neighbors[k][i]<<"  ";
		}
		cout<<endl;
	}
	
	cout<<"Tabela obrazująca przejściowe wierzchołki:"<<endl;
	for (int k=0; k<nOfElements; k++){
		for (int i=0; i<nOfElements; i++){
			cout<<path[k][i]<<"  ";
		}
		cout<<endl;
	}
}

int main(int argc, const char * argv[]) {
	GrafSkierowanyTablica g = skierowanyTablica();
	floydAlgorytm(g, 4);
	
	return 0;
}

