#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	system("cls");
	Trie trie; 
	string word;

	ifstream dict_file("dictionary.txt");
	while (getline(dict_file, word))
		trie.insert(word);
	dict_file.close();

	string prefix;
	while (true)
	{
		cout << "\n������� �������: (��� '0', ����� �����): ";
		getline(cin, prefix);
		if (prefix == "0")
			break;

		vector<string> completions = trie.findCompletions(prefix);
		if (completions.empty())
			cout << "\n�� ������� ����, ��������������� ����� ��������.\n";
		else
		{
			cout << "\n���������� �����:\n";
			for (string& word : completions)
				cout << " ->" << word << endl;
		}
		cout << "\n������� �����, ����� �������� ���, ��� ����������� ������� �������, ����� �������� �����.\n";
	}

	cout << endl;
	system("pause");
	return 0;
}