rm -r build
mkdir build
cmake -S . -B build/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_WITH_TESTS=OFF
cd build/
make
# cd tests/
# ./tests_cpp
