#include <string>//said322
#include <iostream>
using namespace std;
int main()
{
	int n, indenticalsymbols, i = 0;
	for (;;)
	{
		cin >> n;
		if (n <= 0 || n > 60000)

			cout << "Error, write again  " << endl;
		else
			if (cin.good()){
				break;
			}
		cin.clear();
        break;
	}
	cin.ignore();
	string word1, word2;
	while (i<n)
	{
		int indenticalsymbols = 0;
		getline(cin, word1);
		if (word1.length() >= 46) {
			cout << "what a dich?" << endl;
			continue;
		}
		getline(cin, word2);
		if (word2.length() >= 46) {
			cout << "What a dich?" << endl;
			continue;
		}
		++i;
		for (int k = 0; k < word1.length(); ++k)
		{
			if (word2.find(word1[k]) != string::npos)
			{
				word2[word2.find(word1[k])] = '#';
				indenticalsymbols++;
			}
		}
		cout << "Case #" << i << ":  " << word1.length() + word2.length() - 2 * indenticalsymbols << endl;
	}
	system("pause");
	return 0;
}
