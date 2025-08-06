if not exist build mkdir build
pushd build
cmake ..
cmake --build .
popd
build\Debug\opengl_learn.exe
