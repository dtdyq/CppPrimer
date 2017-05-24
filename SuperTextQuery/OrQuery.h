#pragma once
#include<memory>
#include<set>
#include"BinaryQuery.h"
#include"QueryResult.h"
#include"Query.h"
class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query&l, const Query&r) :
		BinaryQuery(l, r, "|") {}
	QueryResult eval(const TextQuery&)const;
};
QueryResult OrQuery::eval(const TextQuery&text)const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	//将左侧运算结果的对象的行号拷贝到结果set中
	auto ret_lines = std::make_shared<std::set<line_no>>
		(left.lines->begin(), left.lines->end());
	//插入右侧对象运算所得行号:
	ret_lines->insert(right.lines->begin(), right.lines->end());
	return QueryResult(rep(), ret_lines, left.file);
}