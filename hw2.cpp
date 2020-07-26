#include <iostream>
#include <sstream>
#include <vector>

void promptCLI(std::vector<std::string>& tokens){
	std::string command;
	std::string ctok;

	getline(std::cin, command);
	std::stringstream sscmd(command);
	while(getline(sscmd, ctok, ' ')){
		tokens.push_back(ctok);
	}

	return;
}

int main(){
	std::vector<std::string> tokens;

	while(true){
		promptCLI(tokens);

		if(tokens.size() > 0){
			tokens.clear();
		}
	}
}


