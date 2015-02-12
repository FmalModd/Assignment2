#define LEXER_H
#include "Token.h"

using namespace std;

class Lexer {
public:
	Lexer();
	Token nextToken();
private:
	string input;
	int index;
	char lastChar;
	bool stopScanning(char nextChar);
	bool isValid(char nextChar);
};