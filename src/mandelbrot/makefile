make: bitmap.h bitmap.cpp Manderbrot.h manderbrot.cpp Window.h
	g++ -o test bitmap.cpp manderbrot.cpp
	./test z.bmp 0.0 0.0 2.0
	./test y.bmp 0.5 0.5 0.8

clean:
	rm test
	rm y.bmp
	rm z.bmp
