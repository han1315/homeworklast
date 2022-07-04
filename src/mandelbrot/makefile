make: bitmap.h bitmap.cpp Manderbrot.h manderbrot.cpp Window.h
	g++ -o test bitmap.cpp manderbrot.cpp
	./test z.bmp 0.0 0.0 2.0
	./test y.bmp 0.5 0.0 0.8
	./test x.bmp 0.5 0.0 0.3
	./test w.bmp 0.3 0.0 0.1

clean:
	rm test
	rm y.bmp
	rm z.bmp
	rm x.bmp
	rm w.bmp
