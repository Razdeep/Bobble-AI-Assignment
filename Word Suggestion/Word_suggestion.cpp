#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <queue>
#include <algorithm>

#define all(v) v.begin(), v.end()

using namespace std;

// #define DEBUG

#ifdef DEBUG
#define trace(x) cerr << #x << ": " << x << endl;
#else
#define trace(x)
#endif

struct Word
{
	string word_name;
	int frequency, distance;

	Word(string word_name, int frequency) : word_name(word_name), frequency(frequency), distance(0) {}
};

int findComma(const string &buffer)
{
	int i = 0;
	for (int i = 0; i < int(buffer.size()); ++i)
	{
		if (buffer[i] == ',')
			return i;
	}
	return -1;
}

int editDistDP(const string &str1, const string &str2)
{
	int m = int(str1.size());
	int n = int(str2.size());

	int dp[m + 1][n + 1];

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
				dp[i][j] = j;

			else if (j == 0)
				dp[i][j] = i;

			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j] = 1 + min(dp[i][j - 1],
								   min(dp[i - 1][j],
								   dp[i - 1][j - 1]));
		}
	}

	return dp[m][n];
}

bool sortingMethod(struct Word a, struct Word b)
{
	if (a.distance == b.distance)
		return a.frequency > b.frequency;
	return a.distance < b.distance;
}

int main(int argc, const char **argv)
{
	if (argc < 3)
	{
		cerr << "Invalid argument" << endl;
		return EXIT_FAILURE;
	}

	string file_name = argv[1];
	string search_text = argv[2];
	transform(all(search_text), search_text.begin(), ::tolower);
	fstream fin;

	try
	{
		fin.open(file_name, ios::in);
		string buffer;

		vector<Word> dictionary;
		while (fin)
		{
			getline(fin, buffer);

			int comma_location = findComma(buffer);
			string word_name = buffer.substr(0, comma_location);
			transform(all(word_name), word_name.begin(), ::tolower);
			int frequency = atol(buffer.substr(comma_location + 2, buffer.size()).c_str());

			Word word(word_name, frequency);
			dictionary.push_back(word);
		}
		int dictionary_count = int(dictionary.size());

		for (int i = 0; i < dictionary_count; ++i)
		{
			dictionary[i].distance = editDistDP(dictionary[i].word_name, search_text);
		}

		sort(all(dictionary), sortingMethod);
		
		for (int i = 0; i < (int)min(dictionary_count, 5); ++i)
			cout << dictionary[i].word_name << (i + 1 == min(dictionary_count, 5) ? "\n" : ", ");
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}