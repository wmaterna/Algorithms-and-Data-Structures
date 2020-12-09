#include <iostream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <vector>


using namespace std;

const int maxlegth=20;
typedef int elementtype;
typedef int position;

class Node{
public:
	int nodeNumber;
};
class Edge{
public:
	Node node1;
	Node node2;
};

class Stos {
private:
    Node S[maxlegth];
    position Top;//szczyt stosu public:
public:
    Stos() {
        Top = -1;
    }
    void Push(Node x) {
        if(Top != maxlegth-1) {
            Top++;
            S[Top] = x;
        }
    }
    void Pop() {
        if(Top != -1) {
            Top--;
        }
    }
    bool Empty() {
        return Top == -1 ? true : false;
    }
    Node TopElem() {
        return S[Top];
    }
    void Makenull() {
        Top = -1;
	}
};


class Graph{
public:
	vector <Node> nodes; //lista wierzchołków
	vector <Edge> edges; //lista krawędzi
	void addNode(int nodeNumber); //dodaje wierzchołek (jezeli jeszcze nie istnieje)
	void addEdge(int nodeNumber1, int nodeNumber2); //dodaje krawędz pomiędzy krawędziami
	virtual vector <int> getNeighbours(int nodeNumber)=0;
};

class UndirectedGraph : public Graph {
public:
	int getDegree(int nodeNumber); //podaje stopien wierzchołka o podanym numerze
	vector <int> getNeighbours(int nodeNumber); //podaje numery sasiadów tego wierzchołka
	void printNeighbours(vector<int>neighbours);
};
class DirectedGraph: public Graph{
public:
	int getIndegree(int nodeNumber);
	int getOutdegree(int nodeNumber);
	vector<int> getIsNeighbour(int nodeNumber);
	vector <int> getNeighbours(int nodeNumber);
	void printNeighbours(vector<int>neighbours);
};

void Graph::addNode(int nodeNr){
	bool isTrue=true;
	for(int i=0; i<nodes.size(); i++){
		if(nodeNr==nodes[i].nodeNumber){
			isTrue=false;
			return;
		}
	}
	if(isTrue){
	Node newOne=*new Node;
	newOne.nodeNumber=nodeNr;
	nodes.push_back(newOne);
	}
	
}
void Graph::addEdge(int nodeNumber1, int nodeNumber2){
	Node temp1=*new Node;
	Node temp2=*new Node;
	int tempvalue1;
	int tempvalue2;
	bool isTrue=true;
	for(int i=0; i<edges.size(); i++){
		temp1=edges[i].node1;
		temp2=edges[i].node2;
		tempvalue1=temp1.nodeNumber;
		tempvalue2=temp2.nodeNumber;
		if((tempvalue1==nodeNumber1 && tempvalue2==nodeNumber2) || (tempvalue1==nodeNumber2 && tempvalue2==nodeNumber1)){
			isTrue=false;
			return;
		}
	}
	if(isTrue)
	{
		Edge newOne = *new Edge;
		newOne.node1.nodeNumber=nodeNumber1;
		newOne.node2.nodeNumber=nodeNumber2;
		edges.push_back(newOne);
	}
	
}
int UndirectedGraph::getDegree(int nodeNumber)
{
	Node temp1=*new Node;
	Node temp2=*new Node;
	int tempvalue1;
	int tempvalue2;
	int degree=0;
	for(int i=0; i<edges.size(); i++){
		temp1=edges[i].node1;
		temp2=edges[i].node2;
		tempvalue1=temp1.nodeNumber;
		tempvalue2=temp2.nodeNumber;
		if(tempvalue1==nodeNumber || tempvalue2==nodeNumber){
			degree++;
		}
		}
	return degree;
	
}
vector <int> UndirectedGraph:: getNeighbours(int nodeNumber){
	Node temp1=*new Node;
	Node temp2=*new Node;
	int tempvalue1;
	int tempvalue2;
	vector<int> neighburs;
	for(int i=0; i<edges.size(); i++){
		temp1=edges[i].node1;
		temp2=edges[i].node2;
		tempvalue1=temp1.nodeNumber;
		tempvalue2=temp2.nodeNumber;
		if(tempvalue1==nodeNumber){
			neighburs.push_back(tempvalue2);
		}
		else if(tempvalue2==nodeNumber){
			neighburs.push_back(tempvalue1);
		}
		}
	return neighburs;
}
void UndirectedGraph::printNeighbours(vector<int> neighbours){
	for(int i=0; i<neighbours.size(); i++){
		cout<<neighbours[i]<<" ";
	}
	cout<<endl;
}

UndirectedGraph buildExampleGraph(){
	cout<<"Wierzchołki grafu: 1,2,3,4,5,6,7,8"<<endl;
	cout<<"Krawedzie wystepuja: 1-2, 1-3, 1-4, 1-5, 2-7,3-4, 4-5, 4-8, 5-6,6-7,6-8 (11 krawedzi)"<<endl;
	UndirectedGraph udg1;
	for (int i=1; i<9; i++){
		udg1.addNode(i);
	}
	
	udg1.addEdge(1,2);
	udg1.addEdge(1,3);
	udg1.addEdge(1,4);
	udg1.addEdge(1,5);
	udg1.addEdge(2,7);
	udg1.addEdge(3,4);
	udg1.addEdge(4,5);
	udg1.addEdge(4,8);
	udg1.addEdge(5,6);
	udg1.addEdge(6,7);
	udg1.addEdge(6,8);
	Node tempnode=*new Node;
		int tempnodevalue;
		vector <int>returnedVector;
		for(int i=0; i<udg1.nodes.size(); i++){
			tempnode=udg1.nodes[i];
			tempnodevalue=tempnode.nodeNumber;
			cout<<"Dla wierzchołka "<<tempnodevalue<<endl;
			cout<<"Stopień wierzchołka: "<<udg1.getDegree(tempnodevalue)<<endl;
			returnedVector=udg1.getNeighbours(tempnodevalue);
			cout<<"Lista wierzchołków: "<<endl;
			udg1.printNeighbours(returnedVector);
	}
	return udg1;
}
elementtype const maxlength=50;

class Kolejka
{
protected :
     Node Queue[maxlength];
     position Front; // Indeks elementu czołowego
     position Rear; // Indeks ostatniego elementu
public:
     Kolejka(){
     	Makenul();
     }
     elementtype AddOne(elementtype i) {
	     if(Empty()) {
	     	return 0;
	     }
	     else if(i < maxlength - 1) {
	     	Rear = i + 1;
	     	return Rear;
	     } else {
	     	Rear = 0;
	     	return Rear;
	     }
     }
     void Enqueue(Node x) {
     	if(!Empty()) {
     		Queue[AddOne(Rear)] = x;
     	}
     	else {
     		Front = 0;
     		Rear = 0;
     		Queue[Front] = x;
     	}
     }
     void Dequeue() {
     	if(!Empty()) {
     		if(Front == Rear) {
	 			Makenul();
	 		}
     		else if(Front < maxlength - 1) {
     			Front++;
     		} else {
     			Front = 0;
     		}
     	}
     }
     Node FrontElem() {
     	return Queue[Front];
     }
     void Makenul() {
     	Front = -1;
     	Rear = -1;
     }
     bool Empty() {
     	return Front == -1;
     }
};
void DFS(){
	Stos stack =*new Stos();
	Node tempnode=*new Node;
	Node tempnode2=*new Node;
	UndirectedGraph udg1 = buildExampleGraph();
	cout<<endl<<"Wynik przeszukiwania DFS: "<<endl;
	vector<Node>seen;
	stack.Push(udg1.nodes[0]);
	while(!stack.Empty()){
		bool isThere=false;
		tempnode=stack.TopElem();
		stack.Pop();
		for (int i=0; i<seen.size(); i++){
			if(seen[i].nodeNumber==tempnode.nodeNumber)
				isThere=true;
		}
	if(!isThere){
		seen.push_back(tempnode);
		cout<<tempnode.nodeNumber<<endl;
	}
	vector<int>tmp;
	tmp=udg1.getNeighbours(tempnode.nodeNumber);
		for (int i=0; i<tmp.size(); i++){
			tempnode2.nodeNumber=tmp[i];
			isThere=false;
			for (int i=0; i<seen.size(); i++){
				if(seen[i].nodeNumber==tempnode2.nodeNumber)
					isThere=true;
			}
			if(!isThere){
				stack.Push(tempnode2);
			}
		}
	}
	
}

void BFS(){
	Kolejka queue = *new Kolejka();
	Node tempnode=*new Node;
	Node tempnode2=*new Node;
	UndirectedGraph udg1 = buildExampleGraph();
	cout<<endl<<"Wynik przeszukiwania BFS: "<<endl;
	vector<Node>seen;
	queue.Enqueue(udg1.nodes[0]);
	while(!queue.Empty()){
		bool isThere=false;
		tempnode=queue.FrontElem();
		queue.Dequeue();
		for (int i=0; i<seen.size(); i++){
			if(seen[i].nodeNumber==tempnode.nodeNumber)
				isThere=true;
		}
	if(!isThere){
		seen.push_back(tempnode);
		cout<<tempnode.nodeNumber<<endl;
	}
	vector<int>tmp;
	tmp=udg1.getNeighbours(tempnode.nodeNumber);
		for (int i=0; i<tmp.size(); i++){
			tempnode2.nodeNumber=tmp[i];
			isThere=false;
			for (int i=0; i<seen.size(); i++){
				if(seen[i].nodeNumber==tempnode2.nodeNumber)
					isThere=true;
			}
			if(!isThere){
				queue.Enqueue(tempnode2);
			}
		}
	}
	
}

int main() {
	DFS();
	BFS();
}

