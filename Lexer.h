#define LEXER_H
#include "Token.h"
#include <vector>

using namespace std;

class Lexer {
public:
	Lexer();
	Token nextToken();
private:
	vector<char> input;
	int index; //position in string
	char last; //the last character we took from the input string
	bool valid(char c);
	bool stop(char c);
	TokenCode getToken(string lexeme);
};