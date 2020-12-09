//
//  main.cpp
//  Set
//
//  Created by Weronika Materna on 04/03/2020.
//  Copyright © 2020 Weronika Materna. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;

class Set{
public:
	vector<int> set_elements;
	void add_element(int n){
		for (int i=0; i<set_elements.size(); i++){
			if(n==set_elements[i])
				return;
		}
		set_elements.push_back(n);
	}
	void delete_element(int n){
		for (int i=0; i<set_elements.size(); i++){
			if(n==set_elements[i])
				set_elements.erase(set_elements.begin() + i);
		}
	}
	void print_set(){
		for (int i=0; i<set_elements.size(); i++){
			cout<<"Element "<<i+1<<" :"<<endl<<set_elements[i]<<endl;
		}
	}
	bool include(int n){
		for (int i=0; i<set_elements.size(); i++){
			if(n==set_elements[i])
				return true;
		}
		return false;
	}
	
	void setSum(vector<int> second_set_elements){
		for (int i=0; i<second_set_elements.size(); i++){
			add_element(second_set_elements[i]);
		}
	}
	void setDiff(vector<int> second_set_elements){
		int sizeSet1=set_elements.size();
		int sizeSet2=second_set_elements.size();
		int biggerSize;
		if(sizeSet1>sizeSet2)
			biggerSize = sizeSet1;
		else biggerSize = sizeSet2;
		for (int i=0; i<second_set_elements.size(); i++){
			if(include(second_set_elements[i]))
				for (int j=0; j<biggerSize; j++){
					if(set_elements[j]==second_set_elements[i])
						delete_element(set_elements[j]);
				}
			
		}
	}
	void setIntersection(vector<int> second_set_elements){
		
	vector<int> same_elements;
	int sizeSet1=set_elements.size();
	int sizeSet2=second_set_elements.size();
	int biggerSize;
	for (int j=0; j<biggerSize; j++){
		for (int i=0; i<biggerSize; i++){
			if(set_elements[j]==second_set_elements[i])
				same_elements.push_back(second_set_elements[i]);
				break;
		}
		for (int i=0; i<same_elements.size(); i++){
			cout<<"Elements"<<same_elements[i]<<endl;
			
		}
		
		   }
	}
};


int main(int argc, const char * argv[]) {
	Set s1;
	s1.add_element(2);
	s1.add_element(2);
	s1.add_element(4);
	s1.add_element(23);
	//s1.print_set();
	s1.delete_element(4);
	cout<<endl;
	//s1.print_set();
	Set s2;
	s2.add_element(2);
	s2.add_element(100);
	s2.add_element(200);
	//s1.setSum(s2.set_elements);
	//s1.print_set();
	s2.setDiff(s1.set_elements);
	s2.print_set();
	return 0;
}
