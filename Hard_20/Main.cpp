#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	char buff[500]{};
	char out_buff[500]{};
	int count_out = 0;


	ifstream fin;
	fin.open("original.txt");
	
	if (!fin.is_open())
	{
		cout << endl << "ќшибка! файл ƒЋя „“≈Ќ»я не был открыт!" << endl;
	}
	else
	{
		cout << "‘айл дл€ „“≈Ќ»я открыт корректно!\n";
		while (!fin.eof())               
		{
			fin.getline(buff, 500);




			char* word[20]{};                       // массив указателей на —Ћќ¬ј
			char* X = NULL;                         // вспомогательный √≈ћќ–ќ… дл€ strtok_s

			word[0] = strtok_s(buff, " ", &X);
			int counter = 0;                      // счетчик слов

			while (word[counter] != NULL)         // пока не получили "нулевое слово"
			{
				
				
			if (isalpha(word[counter][0]))
			{
				out_buff[count_out] = word[counter][0];
				count_out++;
			}
				
				
				counter++;
				word[counter] = strtok_s(NULL, " ", &X);   //вызыва€ на NULL, продолжаем искать слова с места остановки
			}

			count_out++;
			out_buff[count_out] = ' ';
		
		}
		fin.close(); 
	}


	for(int i = 0; i < count_out; i++)
	cout << out_buff[i];

	ofstream fout;
	fout.open("out.txt");

	if (!fout.is_open())
	{
		cout << endl << "ќшибка! файл ƒЋя «јѕ»—» не был открыт!" << endl;
	}
	else
	{
		cout << endl << "‘айл ƒЋя «јѕ»—» открыт корректно!\n";

		cout << count_out;
		fout.write(out_buff, sizeof(out_buff));
		
	fout.close();                       
	}

	system("pause");
	return 0;
}