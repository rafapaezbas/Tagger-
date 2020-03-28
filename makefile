tagger: ./src/*.cpp
	sudo g++ -g ./src/*.cpp -o bin/tagger -std=c++17 -lstdc++fs -ltag -lgtest



