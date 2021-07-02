#ifndef DEPENDENCY_H
#define DEPENDENCY_H
#include <iostream>


struct Dependency {
    std::string dependencyId;
    
    Dependency() : dependencyId(){}
    Dependency(std::string id) : dependencyId(id) {}

    bool operator==(const Dependency &dependency) const {
        return  dependencyId == dependency.dependencyId;
    }

    bool operator<(const Dependency &dependency) const {
        return dependencyId < dependency.dependencyId;
    }
};

#endif