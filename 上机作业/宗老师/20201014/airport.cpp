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
	cout<<"请输入您的姓名："<<endl;
	cin>>name;
	cout<<"请输入您要订的航班号："<<endl;
	cin>>flight;
 
	if(head==NULL)
	{
		head=tail=new Passenger(name,flight);
		cout<<"订票成功"<<endl;
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
		cout<<"订票成功"<<endl;
		return;
	}
}
void Ticket::cancelTicket()
{
	string name,flight;
	cout<<"请输入您的姓名："<<endl;
	cin>>name;
	cout<<"请输入您要退订的航班："<<endl;
	cin>>flight;
	Passenger *p=head,*q=head;
	if((p->name==name)&&(p->flight==flight))
	{
		head=head->next;
		cout<<"退票成功！"<<endl;
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
			cout<<"退票成功！"<<endl;
			return;
		}
		else
		{
			q=p;
			p=p->next;
		}
	}
	cout<<"系统没有到您的订票信息"<<endl;
	return;
}
void Ticket::checkTicket()
{
	string name;
	cout<<"输入您要查找的姓名"<<endl;
	cin>>name;
	Passenger* p=head;
	while(p!=NULL)
	{
		if(p->name==name)
		{
			cout<<"乘客姓名："<<p->name<<" 已定航班"<<p->flight<<endl;
			return;
		}
		else
			p=p->next;
	}
	cout<<"没有该乘客的订票信息"<<endl;
	return;
}
void Ticket::display()
{
	Passenger* p=head;
	while(p!=NULL)
	{
		cout<<"乘客姓名："<<p->name<<" 已定航班："<<p->flight<<endl;
		p=p->next;
	}
}
int main()
{
	Ticket t;
	while(true)
	{
		cout<<"=============================="<<endl;
		cout<<"欢迎使用DUT飞机订票系统"<<endl;
		cout<<"1.预订机票"<<endl;
		cout<<"2.退票"<<endl;
		cout<<"3.查询某人是否已定某航班"<<endl;
		cout<<"4.显示乘客航班信息"<<endl;
		cout<<"5.退出订票系统"<<endl;
		cout<<"=============================="<<endl;
		cout<<"请输入您的选择："<<endl;
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
			cout<<"选择有误，请再次输入"<<endl;
			break;
		}
	}
	return 0;
}