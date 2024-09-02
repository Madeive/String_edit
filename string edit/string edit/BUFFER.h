#pragma once
#include <string>
using namespace std;
class BUFFER
{
protected:
	string buffer;
public:
	void set_buffer(string copy)
	{
		buffer = copy;
	}
	string get_buffer()
	{
		return buffer;
	}
};