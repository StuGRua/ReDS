#include<iostream>
#include<string>
using namespace std;
 
class Passenger
{
public:
	string name;
	string flight;
	Passenger *next;
	Passenger(const string name,string flight,Passenger* p=NULL)
	{
		this->name=name;
		this->flight=flight;
		this->next=p;
	}
};
 
class Ticket
{
private:
	Passenger *head,*tail;//
public:
	Ticket();
	~Ticket();
	void reverseTicket();//订票
	void cancelTicket();//退票
	void checkTicket();//查询某人是否已定航班
	void display();//显示乘客航班信息
};
Ticket::Ticket()
{
	head=tail=NULL;
}
Ticket::~Ticket()
{
	Passenger* p=head,*q=head;
	while(p!=NULL)
	{
		q=head->next;
		delete p;
		p=q;
	}
}
void Ticket::reverseTicket()
{
	string name,flight;
	cout<<"Name:"<<endl;
	cin>>name;
	cout<<"Flight:"<<endl;
	cin>>flight;
 
	if(head==NULL)
	{
		head=tail=new Passenger(name,flight);
		cout<<"Success."<<endl;
		return;
	}
	else
	{
		Passenger *p=head;
		while(p->next)
		{
			if(name<p->name)
				break;
			else
				p=p->next;
		}
		p->next=new Passenger(name,flight,p->next);
		cout<<"Success."<<endl;
		return;
	}
}
void Ticket::cancelTicket()
{
	string name,flight;
	cout<<"Name:"<<endl;
	cin>>name;
	cout<<"Flight"<<endl;
	cin>>flight;
	Passenger *p=head,*q=head;
	if((p->name==name)&&(p->flight==flight))
	{
		head=head->next;
		cout<<"Success."<<endl;
		delete p;
		return;
	}
	p=head->next;
	while(p)
	{
		if((p->name==name)&&(p->flight==flight))
		{
			q->next=p->next;
			delete p;
			cout<<"Success."<<endl;
			return;
		}
		else
		{
			q=p;
			p=p->next;
		}
	}
	cout<<"No info."<<endl;
	return;
}
void Ticket::checkTicket()
{
	string name;
	cout<<"Name:"<<endl;
	cin>>name;
	Passenger* p=head;
	while(p!=NULL)
	{
		if(p->name==name)
		{
			cout<<"Name:"<<p->name<<" Flight:"<<p->flight<<endl;
			return;
		}
		else
			p=p->next;
	}
	cout<<"No info."<<endl;
	return;
}
void Ticket::display()
{
	Passenger* p=head;
	while(p!=NULL)
	{
		cout<<"Name:"<<p->name<<" Flight:"<<p->flight<<endl;
		p=p->next;
	}
}
int main()
{
	Ticket t;
	while(true)
	{
		cout<<"=============================="<<endl;
		cout<<"1.Booking the ticket of flight"<<endl;
		cout<<"2.Cancel the ticket"<<endl;
		cout<<"3.Search"<<endl;
		cout<<"4.Display the information"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"=============================="<<endl;
		cout<<"Enter choice:"<<endl;
		int option;
		cin>>option;
		switch(option)
		{
		case 1:
			t.reverseTicket();
			break;
		case 2:
			t.cancelTicket();
			break;
		case 3:
			t.checkTicket();
			break;
		case 4:
			t.display();
			break;
		case 5:
			return 0;
		default:
			cout<<"Error choice!"<<endl;
			break;
		}
	}
	return 0;
}