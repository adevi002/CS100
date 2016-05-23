#include "visitor.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>

Visitor::Visitor(Base* root) {}
PrintVisitor::PrintVisitor(Base* root): Visitor(root)
{
	this_itr = new PreOrderIterator(root);
}
void PrintVisitor::rootNode(){}
void PrintVisitor::sqrNode()
{
	output.append(" ^2");
}
void PrintVisitor::multNode()
{
	output.append(" *");
}
void PrintVisitor::subNode()
{
	output.append(" -");
}
void PrintVisitor::addNode()
{
	output.append(" +");
}
void PrintVisitor::opNode(Op* op)
{
	int opVal = (int)op->evaluate();
	char buff [50];
	sprintf(buff, " %d", opVal);
	output.append((const char*)(&buff));
}
void PrintVisitor::execute()
{
	for(this_itr->first(); !this_itr->is_done(); this_itr->next())
	{
		this_itr->current()->accept(this);
	}
	cout << output << endl;
}

