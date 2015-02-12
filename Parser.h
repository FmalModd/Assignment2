#define PARSER_H
#include "Lexer.h"

using namespace std;

class Parser {
public:
	Parser();
	Parser(Lexer lexer);
	void parse();
private:
	Lexer lexer;
	void error();
	void expr();
};