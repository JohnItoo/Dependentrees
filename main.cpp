#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

#include "dependency.h"
#include "processor.h"

using namespace std;

bool malformedInput = false;
string DEPENDS = "depends";
string ON = "on";

void parseLibraryStructure(
    map<Dependency, vector<Dependency> >& dependencyGraph,
    vector<string>& outputOrder) {
    string libraryString;
    while (getline(cin, libraryString)) {
        int stringSize = libraryString.size();
        if (stringSize == 0) break;
        int i = 0;
        int stringsFound = 0;
        Dependency vertex;
        while (i < stringSize) {
            int j = i;
            while (libraryString[j] != ' ') {
                j++;
            }
            string substring = libraryString.substr(i, j - i);

            if((stringsFound < 1 || stringsFound > 2) && (substring == DEPENDS || substring == ON))  {
                malformedInput = true;
            }
            if(stringsFound == 1 && substring != DEPENDS) {
                malformedInput = true;
            }

            if(stringsFound == 2 && substring != ON)  {
                malformedInput = true;
            }

            if (i == 0) {
                vertex = Dependency(substring);
                outputOrder.push_back(substring);
            } else if (substring != DEPENDS && substring != ON) {
                Dependency child = Dependency(substring);
                dependencyGraph[vertex].push_back(child);
            }

            i = j + 1;
            stringsFound++;
            if(malformedInput) break;
        }
    }
}

int main() {
    freopen("textfiles/input.txt", "r", stdin);
    freopen("textfiles/output.txt", "w", stdout);

    map<Dependency, vector<Dependency> > dependencyGraph;
    vector<string> outputOrder;
    parseLibraryStructure(dependencyGraph, outputOrder);

    if(malformedInput) {
        cout << "Malformed Input detected!";
        return 0;
    }

    Processor processor = Processor(dependencyGraph, outputOrder);
    processor.process();
    return 0;
}
