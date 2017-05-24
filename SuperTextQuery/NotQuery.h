#pragma once
#include"Query_base.h"
#include"QueryResult.h"
#include"Query.h"
class NotQuery :public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query& q) :query(q) {}
	std::string rep()const {
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&)const;
	Query query;
};
QueryResult NotQuery::eval(const TextQuery&text)const {
	auto ret = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = ret.lines->begin(), end = ret.lines->end();
	auto sz = ret.file->size();
	for (size_t t = 0; t != sz; ++t) {
		if (beg == end || *beg != t) {
			ret_lines->insert(t);
		}
		else if(beg!=end){
			++beg;
		}
	}
	return QueryResult(rep(), ret_lines, ret.file);
}