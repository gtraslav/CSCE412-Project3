CC = g++
CFLAGS = -Wall -Werror
OBJ = main.o loadBalancer.o request.o webServer.o

all: myprogram

myprogram: $(OBJ)
	$(CC) $(CFLAGS) -o myprogram $(OBJ)

main.o: main.cpp loadBalancer.h request.h webServer.h
	$(CC) $(CFLAGS) -c main.cpp

loadBalancer.o: loadBalancer.cpp loadBalancer.h request.h webServer.h
	$(CC) $(CFLAGS) -c loadBalancer.cpp

request.o: request.cpp request.h
	$(CC) $(CFLAGS) -c request.cpp

webServer.o: webServer.cpp webServer.h request.h
	$(CC) $(CFLAGS) -c webServer.cpp

.PHONY: clean
clean:
	rm -f myprogram $(OBJ)
