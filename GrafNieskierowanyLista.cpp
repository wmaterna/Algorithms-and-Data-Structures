/*
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int>measure;
struct element{
	vector<int>elements;
	element *next;
	element *prev;
	element();
};

element::element()
{
	next=0;
	prev=0;
}
struct smallList{
	element *first;
	void insert(int x, element *e);
	void print();
	smallList();
	void addelements();
};
smallList::smallList(){
	first=0;
}
void smallList::insert(int x, element *e){
	e->elements.push_back(x);

    if (first==0)
    {
        first = e;
    }
    else
    {
		element *temp = first;
		
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = e;
		temp->prev=temp;
		e->next = 0;
    }
	
}
void smallList::print(){
	int k=1;
	element *temp = first;
    while (temp)
    {
		cout<<"Dla elementu: ";
		cout<<temp->elements[0]<<" sąsiedzi to ";
		while(temp->elements.size()!=k){
			cout<<temp->elements[k]<<" ";
			k++;
		}
		cout<<endl;
        temp=temp->next;
		k=1;
    }
	
}
/*void mesurer(int x){
	int k=0;
	while(k!=measure.size())
	{
		if(measure[k]==x){
			return;
		}
		k++;
	}
	measure.push_back(x);
	
}

int main()
{
	int N;
	int k=1;
	smallList* l=new smallList;
	string x,y;
	int tmp1;
	cout<<"Ile wierzchołków? "<<endl;
	cin>>N;
	cout<<"Możesz zacząć wprowadzać wierzchołki, ktore sa ze sobą połączone, każdą linie zakończ literą 'q'"<<endl;
	while(k<=N){
	element* e=new element;
	while(1)
	{
		
		cin>>x;
		if(x=="q"){
				break;
		}
		tmp1=atoi(x.c_str());
		//mesurer(tmp1);
		l->insert(tmp1,e);
	}
		k++;
	}
	l->print();
	return 0;

}
*/
