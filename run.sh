rm -r build
mkdir build
cmake -S . -B build/
cd build/
make
cd tests/
./tests_cpp
