#include "Functions.h"
vector<vector<string>> Table1(string filename) {
    ifstream inFS;
    inFS.open(filename);
    string line;
    string temp;
    vector<vector<string>> table1;

    if (inFS.is_open()) {
        while (getline(inFS, line)) {
            if (line.length() > 1) {
                stringstream ss(line);
                vector<string> row;
                while (getline(ss, temp, ',')) {
                    row.push_back(temp);
                }
                table1.push_back(row);
            }
        }
    }

    else if (!inFS.is_open()) {
        cout << "File not found" << endl;
    }

    inFS.close();
    return table1;
}

vector<vector<string>> Table2(string filename) {
    ifstream inFS;
    inFS.open(filename);
    string line;
    string temp;

    vector<vector<string>> table2;

    if (!inFS.is_open()) {
        cout << "File not found" << endl;
    }
    else if (inFS.is_open())
    {
        while (getline(inFS, line))
        {
            if (line.length() > 1)
            {
                stringstream ss(line);
                vector<string> row;

                while (getline(ss, temp, ','))
                {
                    row.push_back(temp);
                }

                table2.push_back(row);
            }
        }
    }
    inFS.close();
    return table2;
}

vector<vector<string>> innerJoin(vector<vector<string>> table1, vector<vector<string>> table2) {
    vector<vector<string>> output_table;

    for (int i=0; i < table1.size() ; i++)
    {
        vector<string> table1_row = table1.at(i);
        for(int j=0; j < table2.size();j++)
        {
            vector<string> table2_row = table2.at(j);

            if(table1_row[0]==table2_row[0])
            {
                vector<string> row_match;

                for (int k=0; k < table1_row.size(); k++ )
                {
                    row_match.push_back(table1_row.at(k));
                }

                for (int k=1; k < table2_row.size(); k++ )
                {
                    row_match.push_back(table2_row.at(k));
                }

                output_table.push_back(row_match);
            }
        }
    }
    return output_table;
}

void Output(vector<vector<string>> output_table) {
    for (int i = 0; i < output_table.size(); i++) {
        for (int j = 0; j < output_table.at(i).size() - 1; j++) {
            cout << output_table.at(i).at(j) << ",";
        }
        cout << output_table.at(i).at(output_table.at(i).size() - 1) << endl;
    }
}