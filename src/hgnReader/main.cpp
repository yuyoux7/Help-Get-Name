#include <iostream>
#include <fstream>
#include "base64.hpp"
constexpr auto _BFILE_ = "key.ky";
constexpr auto _OFILE_ = "Config.hgn";
using namespace ::std;

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		string Buff{}, fstr{}, allstring{}, tstr{}, ostr{}, bsstr{};
		ifstream ifile{}, bifile{};
		ofstream tofile{}, bfile{};
		bool statstr{}, lock{};
		bifile.open(_BFILE_);
		if (bifile.is_open())
		{
			while (!bifile.eof())
			{
				bifile >> Buff;
				bsstr += Buff;
				if (!bifile.eof())
				{
					bsstr += '\n';
				}
			}
		}
		bifile.close();
		bsstr = base64::from_base64(bsstr);
		ifile.open(argv[1]);
		try {
			if (ifile.is_open())
			{
				while (!ifile.eof())
				{
					ifile >> fstr;
					if (fstr[0] == '#')
					{
						while (fstr[fstr.size() - 1] != '#')
						{
							ifile >> fstr;
						}
						ifile >> fstr;
					}
					allstring += fstr;
					if (!ifile.eof())
					{
						allstring += '\n';
					}
				}
			}
			else {
				lock = true;
				throw invalid_argument("open fail");
			}
		}
		catch (const invalid_argument& e)
		{
			cerr << e.what();
			return -1;
		}
		try {
			if (bsstr != allstring)
			{
				throw (-1);
			}
		}
		catch (const int& n){
			if (n == (-1))
			{
				cerr << "Data Error\nturn to new file";
			}
		}
		ifile.close();
		for (auto i = 0; i < allstring.size(); i++)
		{
			if (allstring[i] == '<' || statstr) {
				statstr = true;
				if (allstring[i] != '\n')
					tstr += allstring[i];
				else
					tstr += ' ';
				if (allstring[i] == '>' && allstring[i - 1] == '/')
				{
					statstr = false;
					ostr += (tstr + '\n');
					tstr.clear();
				}
			}
		}
		ostr.pop_back();
		if (!lock) {
			tofile.open(_OFILE_);
			if (tofile.is_open())
			{
				tofile << ostr;
			}
		}
		tofile.close();
		std::string bstr = base64::to_base64(allstring);
		bfile.open(_BFILE_);
		if (bfile.is_open())
		{
			bfile << bstr;
		}
		bfile.close();
	}
}