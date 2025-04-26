APP_NAME = bin/Tetris.app/Contents/MacOS/Tetris
CXX = g++
FLAGS = -Wall -Wextra -pedantic -std=c++14
SRCS = main.cpp piece.cpp board.cpp
FRAMEWORKS = -F/Library/Frameworks/SDL3.xcframework/macos-arm64_x86_64 -framework SDL3 -Wl,-rpath,/Library/Frameworks/SDL3.xcframework/macos-arm64_x86_64

$(APP_NAME):
	$(CXX) $(FLAGS) $(SRCS) $(FRAMEWORKS) -o $(APP_NAME)

clean:
	rm -f $(APP_NAME)

