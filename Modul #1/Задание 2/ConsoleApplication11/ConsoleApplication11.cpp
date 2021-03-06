#include "pch.h" 
#include <iostream> 
#include <string> 

using namespace std;  

double S = 0; 

class Alpha; 
class Beta; 
class Gamma; 

class Base 
{
public: 
	Base() 
	{
		count++; 
	}
	virtual void Create() = 0; 
	~Base() 
	{
		count--; 
		S = S / 2 - 2 * N; 
		if (count == 0) cout << "S = " << S << endl; 
	}
	template<typename ... T1> 
	friend double predict_S(T1 ... t1); 
protected: 
	static int count; 
	static int N; 
};

int Base::N = 0; 
int Base::count = 0; 

class Alpha : public Base 
{
public: 
	void Create() override 
	{
		cout << "Object Alpha [" << N << "] created!" << endl; 
	}
	Alpha() 
	{
		N++; 
		Create(); 
	}
	~Alpha() 
	{
		S = S + N; 
		delete beta; 
		delete gamma; 
	}
	static string getClassName() 
	{ 
		return className; 
	}
	Beta *beta = 0; 
	Gamma *gamma = 0; 
private: 
	static string className; 
};

class Beta : public Base 
{
public: 
	void Create() override 
	{
		cout << "Object Beta [" << N << "] created!" << endl; 
	}
	Beta() 
	{
		N++; 
		Create(); 
	}
	~Beta() 
	{
		S = S - 2 * N; 
		delete alpha; 
		delete gamma; 
	}
	static string getClassName() 
	{
		return className; 
	}
	Alpha *alpha = 0; 
	Gamma *gamma = 0; 
private: 
	static string className; 
};

class Gamma : public Base  
{
public: 
	void Create() override 
	{
		cout << "Object Gamma [" << N << "] created!" << endl; 
	}
	Gamma() 
	{
		N++; 
		Create();  
	}
	~Gamma() 
	{
		S = S - N - 8; 
		delete alpha; 
		delete beta; 
	}
	static string getClassName() 
	{
		return className; 
	}
	Alpha *alpha = 0; 
	Beta *beta = 0; 
private: 
	static string className; 
};

template<typename ... T1>
double predict_S(T1 ... t1) 
{
	double predictedS = 0; 
	auto list = {t1...}; 
	for (auto elem: list) 
	{
		if (elem.getClassName() == "Alpha") 
		{
			predictedS = predictedS + Alpha::N; 
			predictedS = predictedS/ 2 - 2 * Base::N; 
		}
		else if (elem.getClassName() == "Beta") 
		{
			predictedS = predictedS - 2 * Beta::N; 
			predictedS = predictedS / 2 - 2 * Base::N; 
		}
		else if (elem.getClassName() == "Gamma") 
		{
			predictedS = predictedS - Gamma::N - 8; 
			predictedS = predictedS / 2 - 2 * Base::N; 
		}
	}

	return predictedS; 
}

class Elements 
{
public: 
	string name; 
	static int N; 
};

int Elements::N = 0; 

double predict_S(Elements *arr, int M) 
{
	double predictedS = 0; 
	for (int i = 0; i < M; i++) 
	{
		if (arr[i].name == "Alpha") 
		{
			predictedS = predictedS + arr[i].N; 
			predictedS = predictedS / 2 - 2 * arr[i].N; 
		}
		else if (arr[i].name == "Beta") 
		{
			predictedS = predictedS - 2 * arr[i].N; 
			predictedS = predictedS / 2 - 2 * arr[i].N; 
		}
		else if (arr[i].name == "Gamma") 
		{
			predictedS = predictedS - arr[i].N - 8; 
			predictedS = predictedS / 2 - 2 * arr[i].N;
		}
	}

	return predictedS; 
}

 
string Alpha::className = "Alpha"; 
string Beta::className = "Beta";
string Gamma::className = "Gamma"; 



void Results(Elements *arr, int M, int count) 
{
	if (count == M - 1) { 
		for (int i = M-1; i >= 0; i--) { 
			cout << arr[i].name << " "; 
		}
		cout << "Итоговое значение S = " << predict_S(arr, M) << endl; 
	}
	for (int i = count; i < M; ++i) { 
		swap(arr[i].name, arr[count].name); 
		Results(arr,M,count + 1); 
		swap(arr[i].name, arr[count].name); 
	}
}

int main() 
{
	setlocale(LC_ALL, "rus"); 
	cout << "Введите M < 7: "; 
	int M; 
	cin >> M; 
	Elements *arr = new Elements[M]; 
	cout << "Создать объект Alpha - 1" << endl; 
	cout << "Создать объект Beta - 2" << endl; 
	cout << "Создать объект Gamma - 3" << endl; 
	for (int i = 0; i < M; i++) 
	{
		int unsigned short choice; 
		cout << "Ваш выбор: "; 
		cin >> choice; 
		arr[i].N++; 
		if (choice == 1) 
		{
			arr[i].name = "Alpha"; 
		}
		else if (choice == 2) 
		{
			arr[i].name = "Beta"; 
		}
		else if (choice == 3) 
		{
			arr[i].name = "Gamma"; 
		}
	}
	Results(arr, M, 0); 
	Alpha a1; 
	Alpha a2; 
	cout << "Предсказание: " << predict_S(a1, a2) << endl; 
}

