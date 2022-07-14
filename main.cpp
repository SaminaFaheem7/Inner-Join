#include "Functions.h"
using namespace std;
int main()
{
    vector<vector<string>> table1 = Table1("../Table1.csv");
    vector<vector<string>> table2 = Table2("../Table2.csv");
    vector<vector<string>> final_table = innerJoin(table1, table2);
    Output(final_table);
    return 0;
}