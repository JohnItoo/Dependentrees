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
bool cycle = false;

void parseLibraryStructure(
    map<Dependency, vector<Dependency> >& dependencyGraph,
    vector<string>& outputOrder) {
    string libraryString;
    while (getline(cin, libraryString)) {
        int stringSize = libraryString.size();
        if (stringSize == 0) break;
        int i = 0;
        Dependency vertex;
        while (i < stringSize) {
            int j = i;
            while (libraryString[j] != ' ') {
                j++;
            }
            string substring = libraryString.substr(i, j - i);
            if (i == 0) {
                vertex = Dependency(substring);
                outputOrder.push_back(substring);
            } else if (substring != "depends" && substring != "on") {
                Dependency child = Dependency(substring);
                dependencyGraph[vertex].push_back(child);
            }
            i = j + 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<Dependency, vector<Dependency> > dependencyGraph;
    vector<string> outputOrder;
    parseLibraryStructure(dependencyGraph, outputOrder);

    Processor processor = Processor(dependencyGraph, outputOrder);
    processor.process();
    return 0;
}
