default:
	g++ -g -o game main.cpp board/board.cpp -Wall -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -s -O1 -D_DEFAULT_SOURCE -I . -I /home/siks/raylib/src -I /home/siks/raylib/src/external -I /home/siks/raylib/src/extras -I /usr/local/include -L . -L /usr/local/lib -L /home/siks/raylib/src -L /home/siks/raylib -lstdc++ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP
