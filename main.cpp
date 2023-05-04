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
		cout << "\nВведите префикс: (или '0', чтобы выйти): ";
		getline(cin, prefix);
		if (prefix == "0")
			break;

		vector<string> completions = trie.findCompletions(prefix);
		if (completions.empty())
			cout << "\nНе найдено слов, соответствующих этому префиксу.\n";
		else
		{
			cout << "\nПодходящие слова:\n";
			for (string& word : completions)
				cout << " ->" << word << endl;
		}
		cout << "\nВведите слово, чтобы выделить его, или продолжайте вводить префикс, чтобы уточнить поиск.\n";
	}

	cout << endl;
	system("pause");
	return 0;
}