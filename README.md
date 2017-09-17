# Build project
```
cd build
cmake ..
make
```

# Execution
In most of the cases to execute solution of a specific problem you should launch binary after it is built and redirect problem input to stdin. Here is the example:
```
./build/uVA_100 < ./test/uVA_100/uVA_100_test_input.txt
```

# Tests
* To run all tests run in the `build` folder execute the following command:
```
make test
```
* To execute test for the specific problem and see more details run bin with `_test` suffix of this problem from `build` folder