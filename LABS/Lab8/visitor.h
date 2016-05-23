#ifndef VISITORS_H
#define VISITORS_H

#include <iostream>
#include "composite.h"
#include "iterator.h"
#include <string>
using namespace std;

class Base;
class Op;
class Iterator;
class PreOrderIterator;
class Visitor
{
	protected:
		Iterator* this_itr;
	public:
		Visitor(Base* root);
		virtual void rootNode() = 0;
		virtual void sqrNode() = 0;
		virtual void multNode() = 0;
		virtual void subNode() = 0;
		virtual void addNode() = 0;
		virtual void opNode(Op* op) = 0;
		virtual void execute() = 0;
};
class PrintVisitor : public Visitor
{
	protected:
		string output;
	public:
		PrintVisitor(Base* root);
		void rootNode();
		void sqrNode();
		void multNode();
		void addNode();
		void subNode();
		void opNode(Op* op);
		void execute();
};
#endif
