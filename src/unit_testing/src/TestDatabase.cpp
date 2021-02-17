
#include "Database.h"

#include "catch.hpp"
using namespace std;

// Each cpp is a set of test cases for a specific component.
namespace TestDatabase {
    void require(bool b) {
        REQUIRE(b);
    }

    // The name of a test case should be unique and meaningful.
    TEST_CASE("CheckDatabaseProcedure") {
        // initialize the database and insert a procedure
        Database::initialize();
        Database::insertProcedure("echo1", "0", "0", "0", "var", "const");
        Database::insertProcedure("echo2", "0", "0", "0", "var", "const");

        // retrieve the procedures from the database
        vector<string> dbResults;
        Database::getSelectResult (dbResults, "procedureName");

        // create the test output string from the procedures retrieved
        string testOutput;
        for (unsigned int i = 0; i < dbResults.size(); i++)
        {
            testOutput.append(dbResults.at(i) + "$");
        }

        // create the expected output string
        string expectedOutput = "echo1$echo2$";

        // compare the test output with expected output
        require(testOutput == expectedOutput);

        // The test output should match with the expected output
        // and hence the assertion would be true.
    }
        // The name of a test case should be unique and meaningful.
    TEST_CASE("CheckDatabaseVariable") {
        // initialize the database and insert a procedure
        Database::initialize();
        Database::insertProcedure("echo1", "0", "0", "0", "var1", "const");
        Database::insertProcedure("echo2", "0", "0", "0", "var2", "const");

        // retrieve the procedures from the database
        vector<string> dbResults;
        Database::getSelectResult (dbResults, "variable");

        // create the test output string from the procedures retrieved
        string testOutput;
        for (unsigned int i = 0; i < dbResults.size(); i++)
        {
            testOutput.append(dbResults.at(i) + "$");
        }

        // create the expected output string
        string expectedOutput = "var1$var2$";

        // compare the test output with expected output
        require(testOutput == expectedOutput);

        // The test output should match with the expected output
        // and hence the assertion would be true.
    }

    TEST_CASE("CheckDatabaseConstant") {
        // initialize the database and insert a procedure
        Database::initialize();
        Database::insertProcedure("echo1", "0", "0", "0", "var1", "const1");
        Database::insertProcedure("echo2", "0", "0", "0", "var2", "const2");

        // retrieve the procedures from the database
        vector<string> dbResults;
        Database::getSelectResult (dbResults, "constant");

        // create the test output string from the procedures retrieved
        string testOutput;
        for (unsigned int i = 0; i < dbResults.size(); i++)
        {
            testOutput.append(dbResults.at(i) + "$");
        }

        // create the expected output string
        string expectedOutput = "const1$const2$";

        // compare the test output with expected output
        require(testOutput == expectedOutput);

        // The test output should match with the expected output
        // and hence the assertion would be true.
    }
}



