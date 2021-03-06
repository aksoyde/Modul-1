#include "pch.h" 
#include <iostream> 
#include <list> 
#include <cmath> 

using namespace std; 

template<typename T1, typename T2> 
class Pair 
{
public: 
	T1 a; 
	T2 b; 
};

long int factorial(int N) 
{
	if (N == 0) return 1; 
	else if (N == 1) return 1; 
	else return N * factorial(N - 1); 
}

int f(int x) 
{
	if (x > 0) return factorial(x) % 108; 
	else if (x < 0) 
	{
		if ((int)pow(x, 7) % 208 < 0) 
			return (int)pow(x, 7) + 208*((int)(pow(x*(-1), 7) / 208)+1); 
		else return (int)pow(x, 7) % 208; 
	}
}

int f(double x) 
{
	return (int)exp(1 / sin(x)) % 308;  
}

int f(string str) 
{
	int count = 0; 
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] >= 98 && str[i] <= 122 && str[i] != 101 && str[i] != 105 && str[i] != 111 && str[i] != 117 && str[i] != 121) 
		{
			count++; 
		}
		if (str[i] >= 66 && str[i] <= 90 && str[i] != 69 && str[i] != 73 && str[i] != 79 && str[i] != 85 && str[i] != 89) 
		{
			count++; 
		}
	}
	return count; 
}

template<typename T1, typename T2> 
int f(Pair<T1, T2> x) 
{
	return (int)pow(f(x.b), f(x.a)) % 508;  
}

template<typename T> 
int f(list<T> list) 
{
	int summ = 0; 
	for (auto i = list.begin(); i != --(list.end()); ++i) 
	{
		summ += f(*i)*f(*(++i)); 
		i--; 
	}
	return summ; 
}

template<typename T1> 
int f(T1 x) 
{
	return 4558; 
}

int main() 
{
	cout << f(5) << endl; 
	cout << f(-3) << endl; 
	cout << f(0.5) << endl; 
	cout << f("primer") << endl; 
	Pair<int,string> t; 
	t.a = 5; 
	t.b = "sd"; 
	cout << f(t) << endl; 
	list<int> list1; 
	list1.push_back(4); 
	list1.push_back(8); 
	list1.push_back(5); 
	cout << f(list1) << endl; 
	bool tie = false; 
	char ch = 's'; 
	cout << f(tie) << endl; 
	cout << f(ch) << endl; 
}
