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
		cout << endl << "������! ���� ��� ������ �� ��� ������!" << endl;
	}
	else
	{
		cout << "���� ��� ������ ������ ���������!\n";
		while (!fin.eof())               
		{
			fin.getline(buff, 500);




			char* word[20]{};                       // ������ ���������� �� �����
			char* X = NULL;                         // ��������������� ������� ��� strtok_s

			word[0] = strtok_s(buff, " ", &X);
			int counter = 0;                      // ������� ����

			while (word[counter] != NULL)         // ���� �� �������� "������� �����"
			{
				
				
			if (isalpha(word[counter][0]))
			{
				out_buff[count_out] = word[counter][0];
				count_out++;
			}
				
				
				counter++;
				word[counter] = strtok_s(NULL, " ", &X);   //������� �� NULL, ���������� ������ ����� � ����� ���������
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
		cout << endl << "������! ���� ��� ������ �� ��� ������!" << endl;
	}
	else
	{
		cout << endl << "���� ��� ������ ������ ���������!\n";

		cout << count_out;
		fout.write(out_buff, sizeof(out_buff));
		
	fout.close();                       
	}

	system("pause");
	return 0;
}