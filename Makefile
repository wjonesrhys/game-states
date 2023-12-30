all: compile link

test: compile link clean run 

#linux
# compile:
# 	g++ -c main.cpp ./src/*.cpp -I./headers -I/usr/include/SFML -DSFML_STATIC
# link:
# 	g++ ./*.o -o main -L"/lib/x86_64-linux-gnu" -lsfml-graphics -lsfml-window -lsfml-system
# clean:
# 	find . -name '*.o' -delete
# run:
# 	./main

#windows
compile:
	g++ -c main.cpp ./src/*.cpp ./src/states/*.cpp -I./headers -I./headers/states -IC:\SFML\include -DSFML_STATIC
link:
	g++ ./*.o -o main -LC:\SFML\lib -lsfml-main -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -static
clean:
	del *.o	
run:
	main.exe

# READ
# -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 needs this order to statically link SFML dependencies
# -lsfml-graphics-s just means libsfml-graphics-s.so

# -static was to statically link the gcc compiler
# in other words it does not require a dependency on dynamic libraries at runtime in order to run.

# To achieve static linking requires that the archive (.a) versions of your libraries exist on the system. 
# /usr/lib/libc.a, /usr/lib/crt1.o, etc.

# On modern linux systems (as you are using red hat): when a binary links together it 1) either puts the code
# into the executable via .o and .a files, or 2) puts in references to dynamic libraries (.so) files that is 
# resolved by /lib/ld-linux.so (or /lib64/ld-linux=x86-64.so) which is always at a well known place.