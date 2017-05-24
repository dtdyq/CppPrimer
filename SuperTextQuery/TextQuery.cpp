#include"TextQuery.h"
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"QueryResult.h"
TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines) {
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}
QueryResult TextQuery::query(const string& text)const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(text);
	if (loc == wm.end()) {
		return QueryResult(text, nodata, file);
	}
	else {
		return QueryResult(text, loc->second, file);
	}
}