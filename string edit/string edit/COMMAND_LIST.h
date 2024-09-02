#pragma once
#include "COMMAND_INTERFACE.h"
#include <vector>
using namespace std;


class COMMAND_LIST
{
public:
	vector <COMMAND_INTERFACE*> command_pull;
	vector <COMMAND_INTERFACE*> undo_list;
	void push_command(COMMAND_INTERFACE* comand);
	void execute_command();
	void clear();



};

void COMMAND_LIST::push_command(COMMAND_INTERFACE* command)
{
	command_pull.push_back(command);
}

void COMMAND_LIST::execute_command()
{
	int test = 1;

	command_pull.front()->execute();
	undo_list.push_back(command_pull.front());
	command_pull.erase(command_pull.begin());
	cout << "execute comand " << test << endl;
	test++;
	cout << undo_list.size() <<endl;
}

void COMMAND_LIST::clear()
{
	command_pull.clear();
}