#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include <windows.h>
using namespace std;
//   Creating a NODE Structure
struct logs
{
    string log;
    struct logs *next;
};

// Creating a class STACK
class stack
{
    struct logs *top;
    public:
    stack() // constructure
    {
        top=NULL;
    }
    void push(int,string,string); // to write a log
    logs* pop();  // to read the log
};
// PUSH Operation
void stack::push(int c,string nam1,string loge)
{
  if(c==1)
    {
    ofstream file;
    file.open(nam1.c_str(),ios::out|ios::app|ios::binary);
    string lg;
    cin.ignore();
    cout<<"Enter the log ";
    getline(cin,lg);
    file<<lg;
    struct logs *ptr=new logs;
    ptr->log=lg;
    ptr->next=NULL;
    if(top!=NULL)
    ptr->next=top;
    top=ptr;
    cout<<"\nNew item is inserted to the stack!!!";
    file<<endl;
    file.close();
}
    else
    {

    struct logs *ptr;
    ptr=new logs;
    ptr->log=loge;
    ptr->next=NULL;
    if(top!=NULL)
    ptr->next=top;
    top=ptr;
    }
	}

// POP Operation
 logs* stack::pop()
{
    struct logs *temp=top;
    if(top==NULL)
    {
        cout<<"\nThe log is empty!!!\n";
    }
    cout<<temp->log<<endl;
    temp=temp->next;
    delete temp;
}

struct node
{
    string name,regno,address,bloodgrp;
    int age;
	struct node *next;
};
class list
{
	struct node *head,*tail;
	public :
		list()
		{
			head=tail=0;
		}
		int insert(int ,string);
		node* search(string);
		string ret();
		void display(node *);
	};
int list::insert(int x,string line)
{
    if(x==1)
    {
      node *temp=new node;
      ofstream fout;
      fout.open("patient.txt",ios::out|ios::app|ios::binary);
	  cout<<"Enter the details \nNAME:";
      cin>>temp->name;
      fout<<endl<<temp->name<<" ";
      cout<<"\nREGISTRATION NO:";
      cin>>temp->regno;
      fout<<temp->regno<<" ";
      cout<<"\nADDRESS:";
      cin>>temp->address;
      fout<<temp->address<<" ";
      cout<<"\nAGE:";
      cin>>temp->age;
      fout<<temp->age<<" ";
      cout<<"\nBLOOD GROUP:";
      cin>>temp->bloodgrp;
      fout<<temp->bloodgrp<<endl;
      fout.close();
	  temp->next=0;
	  if(temp==0)
	  	return -1;
	  if(head==0)
		head=tail=temp;
      else
	   {
	   	tail->next=temp;
	   	tail=temp;
	   }
    }
    else
    {node *temp=new node;
     istringstream iss(line);
     iss>>temp->name;
     iss>>temp->regno;
     iss>>temp->address;
     iss>>temp->age;
     iss>>temp->bloodgrp;
     if(temp==0)
	  	return -1;
	 else
        if(head==0)
		head=tail=temp;
      else
	   {
	   	tail->next=temp;
	   	tail=temp;
	   }
     }
return 1;
}
node* list::search(string sch)
{	node *temp;
	temp=head;
	if(temp==0)
		return 0;
 else
 	if(temp->name==sch)
	{
		cout<<"\nitem found at first node";
		return temp;
	}

	for( ;temp!=0;temp=temp->next)
	{
    if(temp->next->name==sch)
	     {
	     	cout<<"\nitem found\n";
	      return temp->next;
	  }
}
}
string list::ret()
{
    return(tail->name);
}
void list::display(node *temp)
{

	cout<<"\t\t PATIENT DETAILS \nNAME:"<<temp->name<<endl;
    cout<<"\nREGISTRATION NO:"<<temp->regno<<endl;
    cout<<"\nADDRESS:"<<temp->address<<endl;
    cout<<"\nAGE:"<<temp->age<<endl;
    cout<<"\nBLOOD GROUP:"<<temp->bloodgrp<<endl;
}
void bmi()
{
   float height,bmi,weight;
    cout<<"Enter your height(cm)\n";
        cin>>height;
        height/=100;
        cout<<"Enter your weight\n";
        cin>>weight;
        bmi=weight/(height*height);
        if(bmi<18.5)
            cout<<"NOT HEALTHY UNDER WEIGHT\nBMI="<<bmi<<endl;
        else
            if(bmi>18.5&&bmi<24.9)
            cout<<"HEALTHy NORMAL WEIGHT\nBMI-"<<bmi<<endl;
        else
            if(bmi>24.9&&bmi<29.9)
            cout<<"NOT HEALTHY OVER WEIGHT\nBMI="<<bmi<<endl;
        else
            cout<<"NOT HEALTHY OBESE\nBMI="<<bmi<<endl;
}
int main()
{   l:
     list obj;
     stack st;
     string s,nam,loger;
     char op;

     int choice;
    /* ofstream fout;
     fout.open("patient.txt",ios::out|ios::app|ios::binary);

     fout.close();*/

	 ifstream fin;
     fin.open("patient.txt",ios::in|ios::binary);
     while(!(getline(fin,s).eof()))
     {
	  obj.insert(0,s);

     }
     fin.close();
     cout<<"\t\t\tVIT-HEALTH CARE DBMS\n";
     cout<<"\t\t\t--------------------\n";
cout<<"CAPSLOCK SHOULD BE ON\n\n";
cout<<"Is this your first visit to health center?(Y/N)\n";
cin>>op;
if(op=='Y')
{  obj.insert(1,s);
   s=obj.ret();
    string nam=s+".txt";
    cout<<"\n1.HEALTH STATUS\n2.LOGS\n3.NEW APPOINMENT\n";
    cin>>choice;
    if(choice==1)
    {
       bmi();

    }
    else
    if(choice==2)
    { int i=1;
    do//logs
    {
    if(i==1)
    {
        ++i;
        st.push(1,nam,nam);
    }

    else
        if(i>1)
        {
        cout<<"1:new log\n2:read log\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                st.push(choice,nam,nam);
                break;
            case 2:
                st.pop();
                --i;
                break;
            default:
                cout<<"Please enter correct choice!!";
                break;
        }
    }
    cout<<"\nwould you like to do again\n";
    cin>>op;
    }while(op=='Y');
    }
    else
        if(choice==3)
    {
        ShellExecute(NULL, "open", "http://symptomchecker.isabelhealthcare.com/suggest_diagnoses_advanced/landing_page",NULL, NULL, SW_SHOWNORMAL);
    }

}
else
if(op=='N')
{
    node *ptr;
    cout<<"Enter your name\n";
    cin>>nam;
    ptr=obj.search(nam);
    obj.display(ptr);
    nam=nam+".txt";
    do
    {
    cout<<"\n1.HEALTH STATUS\n2.LOGS\n3.NEW APPOINMENT\n";
    cin>>choice;
    if(choice==1)
    {
       bmi();

    }
    else
    if(choice==2)
    {
    ifstream file;
	file.open(nam.c_str(),ios::in|ios::binary);
	while(!(getline(file,loger)).eof())
    {

        st.push(choice,loger,loger);
    }
    fin.close();
    do//logs
    {
        cout<<"1:new log\n2:read log\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                st.push(choice,nam,nam);
                break;
            case 2:
                st.pop();
                break;
            default:
                cout<<"Please enter correct choice!!";
                break;
        }
        cout<<"\nwould you like to check your logs again?\n";
        cin>>op;
    }while(op=='Y');
    }
    else
        if(choice==3)
    {
        ShellExecute(NULL, "open", "http://symptomchecker.isabelhealthcare.com/suggest_diagnoses_advanced/landing_page",NULL, NULL, SW_SHOWNORMAL);
    }
    cout<<"would like to go back to options\n";
    cin>>op;
    }while(op=='Y');
    }
cout<<"Would like to reuse the app\n";
cin>>op;
if(op=='Y')
goto l;

}
