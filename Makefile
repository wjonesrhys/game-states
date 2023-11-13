all: compile link

test: compile link clean run 

compile:
	g++ -c main.cpp ./src/*.cpp -I./headers -IC:\SFML\include -DSFML_STATIC

link:
	g++ ./*.o -o main -LC:\SFML\lib -lsfml-main -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -static
# before -static
# -static was to statically link the gcc compiler
# -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 needs this order to statically link SFML dependencies

clean:
	del *.o

run:
	main.exe