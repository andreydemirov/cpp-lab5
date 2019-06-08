// Дан файл, компонентами которого являются целые числа. Получить в файле g все компоненты файла f деляющийся на 3.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.H>

using namespace std;

template <typename Stream>
bool read_num(Stream& stream, int& number)
{
	char c = 0;
	string buf;
	while (true)
	{
		stream.read(&c, 1);
		if (c == ' ' || stream.eof())
		{
			if (!buf.empty())
			{
				number = atoi(buf.c_str());
				return true;
			}
		}
		else
		{
			buf += c;
		}
	}
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream fin;
	string inputPath = "C:\Users\BOSS\Desktop\input.txt.txt";
	string outputPath = "C:\Users\BOSS\Desktop\output.txt.txt";

	fin.open(inputPath);

	vector <int> numbers;

	if (fin.is_open()) {
		while (!fin.eof())
		{
			int num;

			if (read_num(fin, num))
				numbers.push_back(num);
		}

	}
	else {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}
	fin.close();

	cout << "Числа из текстового файла : " << endl;
	for (int num : numbers)
		cout << num << " ";


	ofstream fout;          // поток для записи
	fout.open(outputPath); // окрываем файл для записи


	fout << "Числа, которые делятся на 3 :" << endl;
	for (int num : numbers)
		if (num / 3 < 0.001) {
			fout << num << " ";
		}
	fout.close();

	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
