#ifndef F
#define F
#include<iostream>
#include<cstdlib>
#include<sstream>
using std::string;
using std::cout;
using std::istringstream;
using std::cerr;
template<typename T>
T stringtonum(const string &s)
{
	istringstream fromstr(s);
	T num;
	fromstr>>num;
	return num;
}
template<typename T>
class Stack
{
private:
	int max;
	int size;
	T *st;
public:
	Stack(int n=1)
	{
		if(n<1)
		{
			cerr<<"error:栈最大长度小于1\n";
			exit(EXIT_FAILURE);
		}
		size=0;
		max=n;
		st=new T[n];
	}
	~Stack()
	{
		delete [] st;
	}
	bool isfull()
	{
		if(size>=max)
			return true;
		return false;
	}
	bool isempty()
	{
		if(size<=0)
			return true;
		return false;
	}
	bool push(const T &x)
	{
		if(isfull())
		{
			cout<<"栈满了\n";
			return false;
		}
		st[size++]=x;
		return true;
	}
	T pop()
	{
		if(isempty())
		{
			cerr<<"栈空了\n";
			exit(EXIT_FAILURE);
		}
		return st[--size];
	}
	T top()
	{
		if(isempty())
		{
			cerr<<"栈空了\n";
			exit(EXIT_FAILURE);
		}
		return st[size];
	} 
	int getsize()
	{
		return size;
	}
};
#endif F