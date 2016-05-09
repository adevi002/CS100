#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command 
{
	protected:
		Base* root;	
	public:
		Command() {};
		double execute()
		{
			return root->evaluate();
		};
		Base* get_root() 
		{
			return root;
		};
};
class OpCommand : public Command 
{
	public:
		OpCommand(double number)
		{
			this->root = new Op(number);
		};
};
class AddCommand : public Command 
{	
	public:
		AddCommand(Command* newCommand, double number)
		{
			this->root = new Add((newCommand->get_root()), new Op(number));
		};
};
class SubCommand : public Command 
{
	public:
		SubCommand(Command* newCommand, double number)
		{
			this->root = new Sub((newCommand->get_root()), new Op(number));
		};
};
class MultCommand : public Command 
{
	public:
		MultCommand(Command* newCommand, double number)
		{
			this->root = new Mult((newCommand->get_root()), new Op(number));
		};
};
class SqrCommand : public Command 
{
	public:
		SqrCommand(Command* newCommand)
		{
			this->root = new Sqr(newCommand->get_root());
		};
};
#endif //__COMMAND_CLASS__
