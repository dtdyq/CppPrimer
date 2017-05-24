#pragma once
#include"Query_base.h"
#include"TextQuery.h"
#include"QueryResult.h"
//管理Query_base继承体系的接口类
class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&,const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery&t)const {
		return q->eval(t);
	}
	std::string rep()const {
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) :q(query) {}
	std::shared_ptr<Query_base> q;
};
//query输出运算符：
std::ostream &operator<<(std::ostream &os, const Query& query) {
	return os << query.rep();
}