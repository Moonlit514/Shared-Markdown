CC = gcc

OBJ = conway.o main.o
TARGET = conway

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lncurses

%.o: %.c
	$(CC) -c $< -o $@

doc:
	mkdir -p doc
	doxygen Doxyfile

clean:
	rm -f *.bak *.o $(TARGET)
	rm -rf doc

.PHONY: doc clean