TARGET = result
.PHONY: all clean run
all: $(TARGET)
clean:
	rm $(TARGET) *.o
run: $(TARGET)
	./$(TARGET)
main.o: main.c
	gcc -c main.c
bin.o: main.c
	gcc -c bin.c
oct.o: main.c
	gcc -c oct.c
hex.o: main.c
	gcc -c hex.c
reverse.o: main.c
	gcc -c reverse.c
$(TARGET): main.o bin.o oct.o hex.o reverse.o
	gcc main.o bin.o oct.o hex.o reverse.o -o $(TARGET)