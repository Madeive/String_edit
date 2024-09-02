#pragma once
#include "COMMAND_INTERFACE.h"
#include "TEXT_FOR_EDIT.h"

using namespace std;

class DELETE : public COMMAND_INTERFACE
{
protected:

	TEXT_FOR_EDIT* text_for_edit;
	int from;
	int to;

public:

	DELETE(TEXT_FOR_EDIT* text_for_edit, int from, int to) :
		text_for_edit{ text_for_edit },
		from{ from },
		to{ to } {}

	void execute() override
	{
		string tmp = text_for_edit->get_text();
		tmp.erase(from, to);
		text_for_edit->set_text(tmp);
	}
};