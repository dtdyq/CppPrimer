#pragma once
#include"Query.h"
#include"Query_base.h"
class BinaryQuery :public Query_base {
protected:
	BinaryQuery(const Query&r, const Query&l, std::string s) :
		lhs(l), rhs(r), opSym(s) {}
	std::string rep()const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string opSym;//运算符的名称
};