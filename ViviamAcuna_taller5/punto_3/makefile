caos.pdf: d1.txt caos.py
	python caos.py
d1.txt: caos.x
	./caos.x > d1.txt
caos.x: caos.cpp
	c++ caos.cpp -o caos.x
