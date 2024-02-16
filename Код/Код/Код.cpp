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
	int endIndex = 0;

	getline(cin, input);
	input += " ";

	if (input.size() == 0)
		return 0;

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
			input.erase(startIndex, counter + 1);
			counter = -1;
		}

		counter++;
	}

	cout << input << endl;
}
