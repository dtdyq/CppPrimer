#include "Query.h"
#include"WordQuery.h"
#include"NotQuery.h"
#include"AndQuery.h"
#include"OrQuery.h"
Query::Query(const std::string&s):q(new WordQuery(s)) {

}
inline Query operator~(const Query&oped) {
	return std::shared_ptr<Query_base>(new NotQuery(oped));
}
Query operator|(const Query & q1, const Query& q2){
	return std::shared_ptr<Query_base>(new OrQuery(q1, q2));
}
Query operator&(const Query & q1, const Query& q2) {
	return std::shared_ptr<Query_base>(new AndQuery(q1,q2));
}
