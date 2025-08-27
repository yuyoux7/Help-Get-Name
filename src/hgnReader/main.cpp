#include <iostream>
#include <fstream>

using namespace ::std;

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		string Buff{}, fstr{}, allstring{}, laststring{};
		ifstream ifile{};
		ofstream ofile{};
		ifile.open(argv[1]);
		cout << argv[1];
		if (ifile.is_open())
		{
			while (!ifile.eof())
			{
				ifile >> fstr;
				allstring += (fstr + "\n");
			}
		}
		ifile.close();
		for (auto i = 0; i < allstring.size(); i++)
		{
			laststring += (allstring[i] ^ 'a');
		}
		laststring.pop_back();
		ofile.open(argv[1]);
		if (ofile.is_open())
		{
			ofile << laststring;
		}
		ofile.close();
	}
}