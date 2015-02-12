#define TOKEN_H
#include <string>

using namespace std;

enum TokenCode {ID, ASSIGN, SEMICOL, INT, PLUS, MINUS, MULT, LPAREN, RPAREN, PRINT, END, ERROR};

class Token {
public:
	Token() { };
	Token(string lexeme, TokenCode tCode) : lexeme(lexeme), tCode(tCode) { };
private:
	string lexeme;
	TokenCode tCode;
};