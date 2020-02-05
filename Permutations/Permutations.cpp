#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

const int BUFFER_MAX = 1e5;

// #define DEBUG

#ifdef DEBUG
#define trace(x) cerr << "[DEBUG]\t" << #x << ": " << x << endl;
void debugv(vector<string> &v)
{
	cerr << "[";
	for (int i = 0; i < int(v.size()); ++i)
		cerr << v[i] << "\t";
	cerr << " ]\n";
}
#else
#define trace(x)
void debugv(vector<string> &v)
{
}
#endif

string processBuffer(const string &buffer)
{
	string res = "";
	for (int i = 0; i < int(buffer.size()); ++i)
		if (isalnum(buffer[i]))
			res.push_back(buffer[i]);

	return res;
}

int main(int argc, const char **argv)
{
	// Handles invalid argument exec
	if (argc < 2)
	{
		cerr << "Please pass input file as argument" << endl;
		return EXIT_FAILURE;
	}

	fstream fin;
	try
	{
		string file_name = argv[1];
		fin.open(file_name, ios::in);

		string buffer;
		vector<string> lineList;
		while (fin)
		{
			getline(fin, buffer, '\n');
			string processed = processBuffer(buffer);
			lineList.push_back(processed);
		}
		int no_of_lines = int(lineList.size());

		vector<string> past, present;

		for (int i = 0; i < lineList[0].size(); ++i)
		{
			string s;
			s += (lineList[0][i]);
			past.push_back(s);
		}

		for (int i = 1; i + 1 < lineList.size(); ++i)
		{
			present.clear();

			for (int j = 0; j < past.size(); ++j)
				for (int k = 0; k < lineList[i].size(); ++k)
					present.push_back(past[j] + lineList[i][k]);

			past = present;
		}

		for (int i = 0; i < past.size(); ++i)
			cout << past[i] << (i + 1 == past.size() ? "\n" : ", ");
	}
	catch (const std::exception &e)
	{
		cerr << "Error while opening file" << endl;
		fin.close();
		std::cerr << e.what() << '\n';
	}

	return 0;
}