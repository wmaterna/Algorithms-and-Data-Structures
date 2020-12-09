
#include <iostream>
#include <vector>
#define SIZE 100
using namespace std;

struct cell{
	char e;
	int p;
};
int count1;
int count2;
struct cell tabofElements[SIZE];
int last=-1;
void Enqueue(char element, int priority){
	last++; //wskzuje na ostatni element kolejki
	cell c;
	tabofElements[last]=c;
	c.e=element;
	c.p=priority;
}
char DequeueMax()
{
	int i=0;
	int maxprio;
	char returnelement;
	maxprio=tabofElements[0].p;
	returnelement=tabofElements[0].e;
	int index=0;
	while(last>=i)
	{
		if(maxprio<tabofElements[i].p){
			maxprio=tabofElements[i].p;
			returnelement=tabofElements[i].e;
			index=i;
			
		}
		count1++;
		i++;
	}
	i=index;
	while(last>i){
		tabofElements[i].p=tabofElements[i+1].p; //przepisuje kolejke od dolu zeby usunac ostatni element
		tabofElements[i].e=tabofElements[i+1].e;
		i++;
	}
	last=last-1;
	return returnelement;
}
char FindMax()
{
	int i=0;
	int maxprio;
	char returnelement;
	maxprio=tabofElements[0].p;
	returnelement=tabofElements[0].e;
	while(last>=i)
	{
		if(maxprio<tabofElements[i].p)
			maxprio=tabofElements[i].p;
			returnelement=tabofElements[i].e;
		i++;
		count1++;
	}
	return returnelement;
}

class Heap
{
public:
	vector<int>nodes;
	void add(int n){
		nodes.push_back(n);
		upHeap();
	}
	void upHeap(){
		int k,p;
		k=nodes.size()-1;
		while (k>0){
			p=(k-1)/2;
			count2++;
			if(nodes[p]<nodes[k]){
				swap(nodes[p],nodes[k]);
				k=p;
				
			}
			else
				break;
			
		}
	}
	//zaimplementowac findmax
	int DequeueMax(){
		int max=nodes[0];
		int last=nodes.size()-1;
		swap(nodes[0],nodes[last]);
		nodes.pop_back();
		downHeap();
		return max;
	}
	
	void downHeap(){
		int k=0;
		int l=2*k+1; //lewe dziecko k (2i+1)
		int r=l+1;	//prawe dziecko k (2i+2)
		int max=l;
		while(l<nodes.size()-1)
		{
			max=l;
			r=l+1;
			count2++;
			if(r<nodes.size()){ //sprawdzam czy jest prawe poddrzewo
				if(nodes[r]>nodes[l]){
					max++;}
			}
			count2++;
			if(nodes[k]<nodes[max])
			{
				swap(nodes[k],nodes[max]);
				k=max;
				l=2*k+1;
			}
			else{
				break;
			}
		}
	}
	int FindMax()
	{
		return nodes[0];
	}
	void print()
	{
		for(int i=0; i<nodes.size(); i++){
			cout<<nodes[i]<<endl;
		}
	}
};



int main(int argc, const char * argv[]) {
	
	Heap h1;
	cout<<"IMPLEMENTACJA KOLEJKI ZA POMOCĄ KOPCA"<<endl;
	cout<<"Dodaje elementy 9,7,8,1,2,3,5,10 do drzewa"<<endl;
	cout<<"Drzewo wyglada tak: "<<endl;
	h1.add(9);
	h1.add(7);
	h1.add(8);
	h1.add(1);
	h1.add(2);
	h1.add(3);
	h1.add(5);
	h1.add(10);
	h1.print();
	cout<<"Maksymalny element: "<<h1.FindMax()<<endl<<endl;
	cout<<"Usuwam element o najwyzszym priorytecie (korzen) "<<endl;
	cout<<"Drzewo wyglada tak: "<<endl;
	h1.DequeueMax();
	h1.print();
	cout<<endl<<"Maksymalny element: "<<h1.FindMax()<<endl;
	cout<<"Wartość licznika: "<<count2<<endl<<endl;
	cout<<endl<<endl<<"IMPLEMENTACJA KOLEJKI ZA POMOCA TABLICY PRZECHOWUJACEJ STRUKTURE"<<endl;
	cout<<"Dodaje elementy K,K,L,O,A,E,J we wskazanej kolejnosci. "<<endl;
	Enqueue('K', 9);
	Enqueue('K', 4);
	Enqueue('L', 7);
	Enqueue('O', 8);
	Enqueue('A', 2);
	Enqueue('E', 6);
	Enqueue('J', 5);
	Enqueue('\n', 0);
	char returned;
	int tmp=last;
	cout<<"Wykonuje operacje DequeueMax, tyle razy jak duza jest wielkosc koeljki: "<<endl;
	for(int i=0; i<tmp; i++){
	returned=DequeueMax();
	cout<<returned<<" ";
	}
	cout<<endl;
	cout<<"Wartość licznika: "<<count1<<endl<<endl;
	return 0;
}

