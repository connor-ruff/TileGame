

runproj: gfx2.o project.cpp proj.cpp 
	g++ project.cpp proj.cpp gfx2.o -std=c++11 -lX11 -o runproj

clean:
	rm runproj
