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
	//Token nextToken;
	//bool assign;
	void statements();
	void statement();
	void expr();
	void term();
	void factor();
	void error();
};