gcc -L./bin -Wl,-rpath=./bin -o bin/pacman src/*.c -lcstructures
chmod +x bin/pacman
