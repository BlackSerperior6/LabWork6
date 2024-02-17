#include <iostream>
#include <string>
#include <map>

using namespace std;

char AllowedChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_' , '-'};

int Check(char element) 
{
	setlocale(LC_ALL, "rus");
	bool flag = false;
	int counter = 0;

	while (counter < 12 && !flag) 
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
	int counter = 0;
	bool flag = false;
	int startIndex = 0;

	cout << "Введите строку" << endl;

	getline(cin, input);

	if (input.size() == 0)
	{
		cout << "Строка не должна быть пустой" << endl;
		return 0;
	}


	input += ' ';

	while (counter < input.size())
	{
		if (!flag && input[counter + 1] != ' ' && (counter == 0 || input[counter - 1] == ' ') && Check(input[counter]))
		{
			flag = true;
			startIndex = counter;
		}

		if (flag && input[counter] == ' ')
		{
			flag = false;
			input.erase(startIndex, (counter - startIndex) + 1);
			counter = -1;
		}

		counter++;
	}

	cout << endl << "Ваша строка:" << endl << input << endl;
}
