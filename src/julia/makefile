make: bitmap.h bitmap.cpp Window.h Julia.h julia.cpp
	g++ -o test julia.cpp bitmap.cpp
	./test test.bmp 0.2 0.2 2.0 
	eog test.bmp

clean:
	rm test.bmp
	rm test
