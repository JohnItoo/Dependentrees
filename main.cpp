#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "dependency.h"

using namespace std;

void parseLibraryStructure(
    map<Dependency, vector<Dependency> >& dependencyGraph,
    vector<string>& outputOrder) {
    string libraryString;
    while (getline(cin, libraryString)) {
        int stringSize = libraryString.size();
        int i = 0;
        Dependency vertex;
        while (i < stringSize) {
            int j = i;
            while (libraryString[j] != ' ') {
                j++;
            }
            string substring = libraryString.substr(i, j - i);
            i = j + 1;
            if (i == 0) {
                cout << substring << " ";
                vertex = Dependency(substring);
                outputOrder.push_back(substring);
            } else if (substring != "depends" && substring != "on") {
                cout << substring << " ";
                Dependency child = Dependency(substring);
                dependencyGraph[vertex].push_back(child);
            }
        }
        cout << endl;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    Dependency dependency;

    map<Dependency, vector<Dependency> > dependencyGraph;
    vector<string> outputOrder;
    parseLibraryStructure(dependencyGraph, outputOrder);

    return 0;
}
