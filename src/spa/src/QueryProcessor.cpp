#include "QueryProcessor.h"
#include "Tokenizer.h"

// constructor
QueryProcessor::QueryProcessor() {}

// destructor
QueryProcessor::~QueryProcessor() {}

// method to evaluate a query
// This method currently only handles queries for getting all the procedure names,
// using some highly simplified logic.
// You should modify this method to complete the logic for handling all required queries.
void QueryProcessor::evaluate(string query, vector<string>& output) {
	// clear the output vector
	output.clear();

	// tokenize the query
	Tokenizer tk;
	vector<string> tokens;
	tk.tokenize(query, tokens);

	// check what type of synonym is being declared
	// string synonymType = tokens.at(0);

	// create a vector for storing the results from database
	vector<string> databaseResults;

	// call the method in database to retrieve the results
	// This logic is highly simplified based on iteration 1 requirements and 
	// the assumption that the queries are valid.
	for(int i = 0; i < tokens.size(); i++){
		if (tokens[i] == "procedure"){
			Database::getSelectResult(databaseResults, "procedure");
		}
		if (tokens[i] == "variable"){
			Database::getSelectResult(databaseResults, "variable");
		}
		if (tokens[i] == " constant"){
			Database::getSelectResult(databaseResults, "constant");
		}
	}

	// post process the results to fill in the output vector
	for (string databaseResult : databaseResults) {
		output.push_back(databaseResult);
	}
}