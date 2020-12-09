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

vector<int> DirectedGraph::getIsNeighbour(int nodeNumber){ //do jakich wierzcholkow wchodzi
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
		}
	return neighburs;
}
vector <int> DirectedGraph::getNeighbours(int nodeNumber){ //do jaki wierzcholkow wychodzi
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
		if(tempvalue2==nodeNumber){
			neighburs.push_back(tempvalue1);
		}
		}
	return neighburs;
}
void DirectedGraph::printNeighbours(vector<int> neighbours){
	for(int i=0; i<neighbours.size(); i++){
		cout<<neighbours[i]<<" ";
	}
	cout<<endl;
}
UndirectedGraph buildExampleUndirectedGraph(){
	
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
	return udg1;
}
DirectedGraph buildExampleDirectedGraph(){
	DirectedGraph dg;
	for (int i=1; i<5; i++){
		dg.addNode(i);
	}
	dg.addEdge(1,2);
	dg.addEdge(1,3);
	dg.addEdge(3,2);

	
	return dg;
}
UndirectedGraph makeDirectedGraphUndirected(DirectedGraph dg){
	UndirectedGraph udg;
	for (int i=0; i<dg.nodes.size(); i++){
		udg.addNode(dg.nodes[i].nodeNumber);
	}
	udg.edges=dg.edges;
	return udg;
}


void printInfoAboutDirectedGraph(DirectedGraph dg){

	Node tempnode=*new Node;
	int tempnodevalue;
	vector <int>returnedVector;
	for(int i=0; i<dg.nodes.size(); i++){
		tempnode=dg.nodes[i];
		tempnodevalue=tempnode.nodeNumber;
		cout<<"Dla wierzchołka "<<tempnodevalue<<endl;
		returnedVector=dg.getNeighbours(tempnodevalue);
		cout<<"Wierzchołki, ktore prowadza do tego wierzcholka: "<<endl;
		dg.printNeighbours(returnedVector);
	}
}


void printInfoAboutUndirectedGraph(UndirectedGraph udg){
	
	Node tempnode=*new Node;
	int tempnodevalue;
	vector <int>returnedVector;
	for(int i=0; i<udg.nodes.size(); i++){
		tempnode=udg.nodes[i];
		tempnodevalue=tempnode.nodeNumber;
		cout<<"Dla wierzchołka "<<tempnodevalue<<endl;
		returnedVector=udg.getNeighbours(tempnodevalue);
		cout<<"Lista wierzchołków: "<<endl;
		udg.printNeighbours(returnedVector);
	}
}

bool isThere(vector <int> seen, int number){
	for(int i=0; i<seen.size(); i++){
		if(seen[i]==number){
			return true;
		}
	}
	return false;
}

void dfsRecursion(int start,vector<int>seen, UndirectedGraph udg1){

	seen.push_back(start);
	cout<<start;
	vector <int> returnedValue = udg1.getNeighbours(start);
	for(int i=0; i<returnedValue.size(); i++){
		int destination = returnedValue[i];
		if(!isThere(seen,destination)){
			dfsRecursion(destination, seen, udg1);
		}
	}
}

void recursion(int start){
	vector<int>seen;
	UndirectedGraph udg1 = buildExampleUndirectedGraph();
	dfsRecursion(start, seen, udg1);
}

bool connectedUndirectedGraph(UndirectedGraph udg1){
	Stos stack =*new Stos();
	Node tempnode=*new Node;
	Node tempnode2=*new Node;
	vector<Node>seen;
	vector<Node>currentGraphSize=udg1.nodes;
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
	if (currentGraphSize.size() == seen.size())
	{
		return true;
	} else return false;
}


int main() {

	cout<<"Wynik DFS rekurencyjnego: ";
	recursion(1);
	cout<<endl;
	DirectedGraph dg = buildExampleDirectedGraph();
	UndirectedGraph udg = makeDirectedGraphUndirected(dg);
	bool t=connectedUndirectedGraph(udg);
	cout<<"Czy przykładowy skierowny graf jest spójny?  "<<t<<endl;
	UndirectedGraph udg2 = buildExampleUndirectedGraph();
	t=connectedUndirectedGraph(udg2);
	cout<<"Czy przykładowy nieskierowny graf jest spójny?  "<<t<<endl;
}

