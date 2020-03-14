#include<iostream>
using namespace std;

/* This example was created on September 19, 2012*/
/* This is an example for the basic concept of OOP(Object-oriented programming) */

struct member{
	int no;
	char name[20];
	int age;
};

void add(struct member *A)
{
	cout<<"number. >";
	cin>>A->no;
	cout<<"name. >";
	cin>>A->name;
	cout<<"age. >";
	cin>>A->age;
}

void menu_print(){
        cout<<"\n====menu==="<<endl;
	cout<<"1. input new member"<<endl;
	cout<<"2. search"<<endl;
	cout<<"3. number of members"<<endl;
	cout<<"4. exit\n"<<endl;
}

int main()
{
	int i= 0; //menu number
	int l = 0;

	int c = 0;
	int f = 0;
	struct member A[10];


	while(1){
	    menu_print();
		cout<<"mode>";
		cin>>i;

		switch(i){
			case 1: 
				if(l<10)
				{
					add(&A[l]);
					l++;
				}
				break;


			case 2 : 
				cout<<"What is the number of the item you are looking for? : ";
				cin>>c;
				
				for(f=0;f<20;f++){
				
					if(A[f].no==c){
						cout<<"age : "<<A[f].age<<endl;
						cout<<"name : "<<A[f].name<<endl;
						cout<<"number : "<<A[f].no<<endl;
					}
				}

				break;
			case 3 :
				cout<<"("<<l<<")"<<"members"<<endl;
				break;
			case 4 : exit(0);
					};

	};


}
