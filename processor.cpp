#include "processor.h"

#include <iostream>

#include "dependency.h"

std::set<Dependency> Processor::traverseDependencyGraph(Dependency vertex) {
    if (isCycleDetected) return visitedVertices;
    if (foundDependencies.find(vertex) != foundDependencies.end()) {
        return foundDependencies[vertex];
    }
    std::set<Dependency> res;
    if (visitedVertices.find(vertex) != visitedVertices.end()) {
        isCycleDetected = true;
        return visitedVertices;
    }

    visitedVertices.insert(vertex);

    if (dependencyGraph.find(vertex) != dependencyGraph.end()) {
        for (auto& child : dependencyGraph[vertex]) {
            res.insert(child);
            std::set<Dependency> childsDependencies =
                traverseDependencyGraph(child);
            for (auto subDependency : childsDependencies) {
                res.insert(subDependency);
            }
        }
    }

    foundDependencies[vertex] = res;
    return res;
}

void Processor::process() {
    for (auto vertexPair : dependencyGraph) {
        std::set<Dependency> childDependencies;
        std::set<Dependency> visitedVertices;
        if (isCycleDetected) break;

        childDependencies = traverseDependencyGraph(vertexPair.first);
        std::vector<Dependency> childDependenciesVector(
            childDependencies.size());
        copy(childDependencies.begin(), childDependencies.end(),
             childDependenciesVector.begin());
        resultMap[vertexPair.first] = childDependenciesVector;
    }

    if (isCycleDetected) {
        std::cout << "A Dependency Cycle has been detected\n";
    } else {
        int verticesCount = outputOrder.size();

        for (int i = 0; i < verticesCount; i++) {
            Dependency d = Dependency(outputOrder[i]);
            std::cout << outputOrder[i] << " depends on ";

            for (Dependency sub : resultMap[d]) {
                std::cout << sub.dependencyId << " ";
            }
            std::cout << std::endl;
        }
    }
}
