CXXFLAGS=-Wall -O2 -std=c++17
CXX=g++

VPATH = ../src:../src/renderers:../src/math:../src/geometry:../src/materials

objects = main.o vec4.o ray.o mat4.o color.o image.o camera.o scene.o rayTracer.o geometry.o plane.o sphere.o groundGrid.o baseMaterial.o 

edit: $(objects)
	$(CXX) -o ../bin/main $(objects)

main.o: main.cpp vec4.hpp color.hpp ray.hpp camera.hpp mat4.hpp rayTracer.hpp
scene.o: scene.cpp camera.hpp
ray.o: ray.cpp vec4.hpp
color.o: color.cpp
camera.o: camera.cpp vec4.hpp ray.hpp
mat4.o: mat4.cpp vec4.hpp
scene.o: scene.cpp camera.hpp geometry.hpp plane.hpp sphere.hpp
rayTracer.o: rayTracer.cpp scene.hpp image.hpp
geometry.o: geometry.cpp mat4.hpp hit.hpp vec4.hpp
plane.o: plane.cpp geometry.hpp
sphere.o: sphere.cpp geometry.hpp
groundGrid.o: groundGrid.cpp material.hpp
baseMaterial.o: baseMaterial.cpp material.hpp

.PHONY: clean
clean: 
	rm -rf *.o
	rm ../bin/main