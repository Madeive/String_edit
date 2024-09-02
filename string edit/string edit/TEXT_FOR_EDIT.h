#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class TEXT_FOR_EDIT
{
private:
	string file_name;
	string text_for_edit;
public:
	string get_text()
	{
		return text_for_edit;
	}
	string get_name()
	{
		return file_name;
	}

	void set_text(string text)
	{
		text_for_edit = text;
	}

	TEXT_FOR_EDIT(string file_name)
	{
		this->file_name = file_name;
		ifstream read_txt(this->file_name);
		if (!read_txt.is_open())
		{
			try
			{
				ofstream New_file(this->file_name);
				New_file << "PIPEC NE HOROSHO";
				New_file.close();
				read_txt.open(this->file_name);
			}
			catch (const exception& E)
			{
				cout << E.what();
			}
		}
		while (!read_txt.eof())
		{
			getline(read_txt, text_for_edit);
		}
		read_txt.close();
		if (read_txt.is_open())
		{
			try
			{
				read_txt.close();
			}
			catch (const exception& E)
			{
				cout << E.what();
			}
		}
	}

	TEXT_FOR_EDIT() :TEXT_FOR_EDIT{ "STRING.txt" } {};
};
