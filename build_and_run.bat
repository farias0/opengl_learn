if not exist build mkdir build
pushd build
cmake ..
cmake --build .
Debug\opengl_learn.exe
popd
