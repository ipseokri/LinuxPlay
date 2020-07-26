#include <iostream>
#include <sstream>
#include <vector>
#include "SingleLinkedList.h"

const std::string one = "add";
const std::string two = "cd";
const std::string three = "rm";
const std::string four = "ls";
const std::string five = "cut";
const std::string six = "copy";
const std::string seven = "exit";


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


