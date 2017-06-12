
all: main.cpp src/templates.cpp
	CXX -std=c++11 -o ipToHtml main.cpp src/templates.cpp
