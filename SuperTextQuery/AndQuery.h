#pragma once
#include<set>
#include"BinaryQuery.h"
class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query&l, const Query&r) :
		BinaryQuery(l, r, "&") {}
	QueryResult eval(const TextQuery&)const;
	
};
QueryResult AndQuery::eval(const TextQuery&text)const {
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	set_intersection(left.lines->begin(), left.lines->end(),
		right.lines->begin(), right.lines->end(), ret_lines);
	return QueryResult(rep(), ret_lines, left.file);
}
