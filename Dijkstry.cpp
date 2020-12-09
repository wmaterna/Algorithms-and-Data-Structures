#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <queue>
#define SIZE_OF_GRAPH 8

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
	
	
	void SortElements(int size){
		int change = 0;
		int tmp;
		do
		{
			change=0;
			for (int i=0; i<size-1; i++)
			{
				if (elements[i]>elements[i+1])
				{
					change=change+1;
					tmp=elements[i];
					elements[i]=elements[i+1];
					elements[i+1]=tmp;
				}
			}
		}while(change!=0);
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
	g.enter(0,1,20);
	g.enter(0,6,90);
	g.enter(0,3,80);
	g.enter(1,5,10);
	g.enter(2,5,50);
	g.enter(3,6,20);
	g.enter(4,6,30);
	g.enter(5,2,10);
	g.enter(5,3,40);
	g.enter(6,0,20);
	g.enter(2,7,20);
	g.enter(4,3,50);
	g.enter(2,3,10);
	g.enter(3,2,10);
	g.SortElements(8);
	return g;
	
}



int shortestDistanceVertex(int* distance,bool* known,int size, GrafSkierowanyTablica g){
	int minVertex = -1;
	for (int i=0; i<size; i++){
		if(!known[i] && (minVertex==-1 || distance[i] < distance[minVertex])){
			minVertex=i;
		}
		
}
	return minVertex;
}

void dijkstry(GrafSkierowanyTablica g, int size){
	int distance[8];
	bool known[8];
	int predecessor[8];
	for (int i=0; i<size; i++){
		distance[i]=1000;
		known[i]=false;
		predecessor[i]=-1;
	}
	distance[0]=0;
	predecessor[0]=0;
	for (int i=0; i<size-1; i++){
		int minVertex = shortestDistanceVertex(distance, known, size,g);
		known[minVertex]=true;
		for (int j=0; j< size; j++){
			if(g.neighbors[minVertex][j]!=0 && !known[j]){
				int dist = distance[minVertex]+ g.neighbors[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
					predecessor[j]=minVertex;
				}
			}
	}
}
	cout<<"Tabela pozakująca wagę drogi od wierzchołka 0 do każdego kolejnego "<<endl;
	for (int j=0; j< size; j++){
		cout<<j<<" "<<distance[j]<<endl;
	}
	cout <<endl;
	cout<<"Tabela pozakująca wierzchołki przejściowe "<<endl;
	for (int j=0; j< size; j++){
		cout<<j<<" "<<predecessor[j]<<endl;
	}
}

int main(int argc, const char * argv[]) {
	GrafSkierowanyTablica g = skierowanyTablica();
	dijkstry(g, 8);

	
	return 0;
}

