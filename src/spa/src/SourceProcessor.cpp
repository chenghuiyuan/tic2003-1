#include "SourceProcessor.h"
#include <unistd.h>

// Returns true if s is a number else false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

// void Database::insertProcedure(string procedureName, string isRead=NULL, string isPrint=NULL, string isAssign=NULL, string variable=NULL, string constant=NULL) {
void insertIntoDB(string procedureName, string token, string isRead, string isPrint, string isAssign){
	if (isNumber(token))
		Database::insertProcedure(procedureName, isRead, isPrint, isAssign, NULL, token);
	else
		Database::insertProcedure(procedureName, isRead, isPrint, isAssign, token, NULL);
}

// method for processing the source program
// This method currently only inserts the procedure name into the database
// using some highly simplified logic.
// You should modify this method to complete the logic for handling all the required syntax.
void SourceProcessor::process(string program) {
	// initialize the database
	Database::initialize();

	// tokenize the program
	Tokenizer tk;
	string procedureName;
	vector<string> tokens;
	tk.tokenize(program, tokens);

	// This logic is highly simplified based on iteration 1 requirements and 
	// the assumption that the programs are valid.

	for(int i = 0; i < tokens.size(); i++){
		if (tokens[i] == "procedure"){
			procedureName = tokens[i+1];
		}
		else if (tokens[i] == "read"){
			insertIntoDB(procedureName, tokens[i+2], "1", "0", "0");
		}
		else if (tokens[i] == "print"){
			insertIntoDB(procedureName, tokens[i+2], "0", "1", "0");
		}
		else if (tokens[i] == "assign"){
			insertIntoDB(procedureName, tokens[i+2], "0", "0", "1");
		}
	}

}