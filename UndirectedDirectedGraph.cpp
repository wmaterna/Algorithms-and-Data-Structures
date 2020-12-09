#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;
class Node{
public:
	int nodeNumber;
};
class Edge{
public:
	Node node1;
	Node node2;
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

int DirectedGraph:: getIndegree(int nodeNumber){
	Node temp1=*new Node;
	int tempvalue1;
	int degree=0;
	for(int i=0; i<edges.size(); i++){
		temp1=edges[i].node1;
		tempvalue1=temp1.nodeNumber;
		if(tempvalue1==nodeNumber){
			degree++;
		}
		}
	return degree;
}
int DirectedGraph:: getOutdegree(int nodeNumber){
	Node temp=*new Node;
	int tempvalue;
	int degree=0;
	for(int i=0; i<edges.size(); i++){
		temp=edges[i].node2;
		tempvalue=temp.nodeNumber;
		if(tempvalue==nodeNumber){
			degree++;
		}
		}
	return degree;
}
vector<int> DirectedGraph::getIsNeighbour(int nodeNumber){
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
vector <int> DirectedGraph::getNeighbours(int nodeNumber){
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
void DirectedGraphOutput(){
	cout<<"GRAF SKIEROWNY: "<<endl;
	string x,y;
	int tmp1,tmp2,stopper=0;
	int nodes,edges;
	cout<<"Ile wierzchołków ma ten graf?: "<<endl;
	cin>>nodes;
	cout<<"Ile krawędzi ma ten graf?: "<<endl;
	cin>>edges;
	DirectedGraph dg1;
	while(stopper!=edges)
	{
		cout<<"Para: "<<endl;
		cin>>x;
		cin>>y;
		tmp1=atoi(x.c_str());
		tmp2=atoi(y.c_str());
		dg1.addNode(tmp1);
		dg1.addNode(tmp2);
		dg1.addEdge(tmp1, tmp2);
		stopper++;
	}
	Node tempnode=*new Node;
	int tempnodevalue;
	vector <int>returnedVector;
	vector <int>returnedVect2;
	for(int i=0; i<dg1.nodes.size(); i++){
		tempnode=dg1.nodes[i];
		tempnodevalue=tempnode.nodeNumber;
		cout<<"Dla wierzchołka "<<tempnodevalue<<endl;
		cout<<"Stopień wychodzących krawędzi: "<<dg1.getIndegree(tempnodevalue)<<endl;
		cout<<"Stopień wchodzących krawędzi: "<<dg1.getOutdegree(tempnodevalue)<<endl;
		returnedVector=dg1.getIsNeighbour(tempnodevalue);
		cout<<"Lista wychodzacych wierzchołków: "<<endl;
		dg1.printNeighbours(returnedVector);
		cout<<"Lista wchodząych wierzchołkow: "<<endl;
		returnedVect2=dg1.getNeighbours(tempnodevalue);
		dg1.printNeighbours(returnedVect2);
}
}
void UndirectedGraphOutput(){
	cout<<"GRAF NIESKIEROWNY: "<<endl;
		string x,y;
		int tmp1,tmp2,stopper=0;
		int nodes,edges;
		cout<<"Ile wierzchołków ma ten graf?: "<<endl;
		cin>>nodes;
		cout<<"Ile krawędzi ma ten graf?: "<<endl;
		cin>>edges;
		UndirectedGraph udg1;
		while(stopper!=edges)
		{
			cout<<"Para: "<<endl;
			cin>>x;
			cin>>y;
			tmp1=atoi(x.c_str());
			tmp2=atoi(y.c_str());
			udg1.addNode(tmp1);
			udg1.addNode(tmp2);
			udg1.addEdge(tmp1, tmp2);
			stopper++;
		}
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
}
int main(int argc, const char * argv[]) {
	
	int n;
	cout<<"Graf 1 - nieskierowany, graf 2 - skierowany"<<endl;
	cin>>n;
	switch(n){
		case 1:
			UndirectedGraphOutput();
			break;
		case 2:
			DirectedGraphOutput();
			break;
	}
		
	return 0;
}
