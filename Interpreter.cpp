#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main(){
	stack<string> myIDs;
	map<string, int> myMap;
	string s;

	while(cin >> s) {
		cout << "inside while" << endl;
		if (s == "PUSH") {
			cout << "push" << endl;
			cin >> s;
			myIDs.push(s);
		} else if (s == "ASSIGN") {
			// second = first;
			cout << "assign" << endl;
			string first, second;
			int number;
			first = myIDs.top();
			myIDs.pop();
			second = myIDs.top();
			myIDs.pop();

			if(isdigit(first[0])) {
				number = stoi(first);
			} else {
				number = myMap.find(first)->second;
			}
			myMap.insert(pair<string, int>(second, number));
		} else if (s == "SUB") {
			/*




			string first = myIDs.top();
			myIDs.pop();
			string second = myIDs.top();
			myIDs.pop();
			int firstnumber, secondnumber;
			if(isdigit(first[0])) {
				firstnumber = stoi(first);
			} else {
				firstnumber = myMap.find(first)->second;
			}
			if(isdigit(second[0])) {
				secondnumber = stoi(first);
			} else {
				secondnumber = myMap.find(second)->second;
			}
			int result = secondnumber - firstnumber;
			string myString = to_string(result);
			myIDs.push(myString);
			*/
		} else if (s == "PLUS") {
			
		} else if (s == "MULT") {
			
		} else if (s == "PRINT") {
			cout << "print" << endl;
			cout << myMap.find(myIDs.top())->second << endl;
			myIDs.pop();
		}
	}


	return 0;
}