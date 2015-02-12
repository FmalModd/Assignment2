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
	int index;
	char last;
	bool valid(char c);
	bool stop(char c);
	TokenCode getToken(string lexeme);
};