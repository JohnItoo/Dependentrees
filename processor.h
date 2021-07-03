#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <iostream>
#include <map>
#include <vector>
#include <set>

#include "dependency.h"

class Processor {
   private:
    std::map<Dependency, std::vector<Dependency> > dependencyGraph;
    std::vector<std::string> outputOrder;
    bool isCycleDetected;
    std::map<Dependency, std::set<Dependency> > foundDependencies;
    std::map<Dependency, std::vector<Dependency> > resultMap;
    std::set<Dependency> visitedVertices;
    
    std::set<Dependency> traverseDependencyGraph(Dependency vertex);

   public:
    Processor(std::map<Dependency, std::vector<Dependency> > graph,
              std::vector<std::string> order)
        : dependencyGraph(graph), outputOrder(order), isCycleDetected(false) {}

    void process();

};

#endif