#include <iostream>
#include <string>
#include <map>

using namespace std;

char AllowedChars[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '_' , '-'};

map<int, string> GetMap(string String) //Перегрузка для нахождения кол-ва слов, начинающихся на а
{
	map<int, string> TestMap;
	int size = String.size(); //Получаем размер строки
	string buffer = ""; //Инициализируем буффер

	for (int i = 0; i < size + 1; i++) //Проходим по всей строке
	{
		if (String[i] == ' ' || i == size) //Если текущий элемент - пробел или же достигнут последний элемент
		{
			TestMap[i - buffer.size()] = buffer; 
			cout << i - buffer.size() << " " << TestMap[i - buffer.size()] << endl;
			buffer = ""; 
		}
		else
		{
			buffer += String[i];
			cout << "Значение буффера " << buffer << endl;
			cout << "Размер буффера: " << buffer.size() << endl;
		}	
	}

	return TestMap;
}

int Check(char element) 
{
	setlocale(LC_ALL, "rus");
	bool flag = false;
	int counter = 0;

	while (counter < 11 && !flag) 
	{
		flag = AllowedChars[counter] == element;
		counter++;
	}

	return flag;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	string input;
	getline(cin, input);

	map<int, string> map = GetMap(input);

	for (auto& item : map) 
	{
		if (Check(item.second[0]) && item.second.size() >= 2 && input.size() > 0)
			input.erase(item.first, item.second.size());
	}

	cout << input << endl;
}
