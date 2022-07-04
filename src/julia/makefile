make: bitmap.h bitmap.cpp Window.h Julia.h julia.cpp
	g++ -o test julia.cpp bitmap.cpp
	./test a.bmp  0.45 -0.1428 20
	./test b.bmp  -0.75 0.0 20
	./test c.bmp  -0.8 0.156 20
	./test d.bmp  -0.70176 -0.3842 20  

clean:
	rm a.bmp
	rm b.bmp
	rm c.bmp
	rm d.bmp
	rm test
