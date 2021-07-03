# Dependentrees
This is a CLI tool that lists all the transitive dependencies when given direct dependencies of every dependency.


### Compile
Run ```make``` in the root directory.

### Run
Execute the Deptrees executable like so :  ```./Deptrees```

This will be run against the ```input.txt		``` file in the textfiles directory.  ```output.txt``` will be the expected Dependency result.

### Testcase format.
Currently the supported format of libraries is like so

```
Y depends on Z

A depends on Q R S

X depends on Y

Z depends on A B
```

Every Dependency itemises its direct dependencies with spaces in-between after  ```depends on``` .
