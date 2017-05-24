#pragma once
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<memory>
#include<string>
using namespace std;
class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};