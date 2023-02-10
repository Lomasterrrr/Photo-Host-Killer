all:
	g++ -lcurl -c main.cpp
	g++ -lcurl -c connect.cpp
	g++ -lcurl -c generate.cpp
	g++ -lcurl -c algorithms.cpp
	g++ -lcurl -c clear.cpp
	g++ -lcurl -c files.cpp
	g++ -lcurl -o bin/parser main.o connect.o generate.o algorithms.o clear.o files.o
	rm main.o
	rm connect.o
	rm algorithms.o
	rm files.o
	rm clear.o
	rm generate.o
	clear
	chmod +x run.sh
	./run.sh


	