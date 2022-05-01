#pragma once

#include "Character.h"

class CharStack{

private:
	Character* top;

public:

	CharStack();
	void push(char Newchar);
	void pop();
	Character* get_top();
	bool is_empty();
	void print(Character* stack);


};

