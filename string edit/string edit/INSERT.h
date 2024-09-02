#pragma once
#include "COMMAND_INTERFACE.h"
#include "TEXT_FOR_EDIT.h"


class INSERT : public COMMAND_INTERFACE
{
private:
	TEXT_FOR_EDIT* text_for_edit;
	string text_for_insert;
	int ind_to_insert;

public:

	INSERT(TEXT_FOR_EDIT* text_for_edit, string text_for_insert, int ind_to_insert) :
		text_for_edit{ text_for_edit },
		text_for_insert{ text_for_insert },
		ind_to_insert{ ind_to_insert }
	{}
	void execute() override
	{
		string tmp = text_for_edit->get_text();
		tmp.insert(ind_to_insert, text_for_insert);
		text_for_edit->set_text(tmp);
	}
}; 
