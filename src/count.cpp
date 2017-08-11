#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "Utf.h"

void show(map<string, long long>& state);

int main(int argc, char* argv[]){
	string line;
	vector<string> chs;
	map<string, long long> uni, bi, tri, four;
	for (int file_num = 1; file_num < argc; file_num++)
	{
		ifstream read(argv[file_num]);
		if (read.is_open())
		{
			while (getline(read, line))
			{
				getCharactersFromUTF8String(line, chs);
				int char_size = chs.size();
				for (int idx = 0; idx < char_size; idx++)
					uni["UNI=" + chs[idx]]++;
				for (int idx = 0; idx < char_size - 1; idx++)
					bi["BI=" + chs[idx] + "#" + chs[idx + 1]]++;
				for (int idx = 0; idx < char_size - 2; idx++)
					tri["TRI=" + chs[idx] + "#" + chs[idx + 1] + "#" + chs[idx + 2]]++;
				for (int idx = 0; idx < char_size - 3; idx++)
					four["FOUR=" + chs[idx] + "#" + chs[idx + 1] + "#" + chs[idx + 2] + "#" + chs[idx + 3]]++;
			}
			read.close();
		}
		else {
			cout << argv[file_num] << " file don't exist. " << endl;
			return 0;
		}
	}
	show(uni);
	show(bi);
	show(tri);
	show(four);
	return 0;
}

void show(map<string, long long>& count){
	for (map<string, long long>::iterator it = count.begin();
		it != count.end(); it++)
	{ 
		cout << it->first << '\t' << it->second << endl;
	}
}
	