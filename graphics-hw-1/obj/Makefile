CXXFLAGS=-Wall -O2 -std=c++17
CXX=g++

VPATH = ../src:../src/renderers:../src/math

objects = main.o vec4.o ray.o mat4.o color.o image.o scene.o rayTracer.o

edit: $(objects)
	$(CXX) -o ../bin/main $(objects)

main.o: main.cpp vec4.hpp color.hpp ray.hpp camera.hpp mat4.hpp rayTracer.hpp
scene.o: scene.cpp camera.hpp
ray.o: ray.cpp vec4.hpp
color.o: color.cpp
camera.o: camera.cpp vec4.hpp ray.hpp
mat4.o: mat4.cpp vec4.hpp
scene.o: scene.cpp camera.hpp
rayTracer.o: rayTracer.cpp scene.hpp image.hpp

clean: 
	rm ./*.o ../bin/main 