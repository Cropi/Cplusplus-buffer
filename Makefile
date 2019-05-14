CC=g++
FLAGS=-std=c++14 -Werror -Wall -pedantic
TARGET=main
MODULES=buffer
OBJS = $(addprefix obj/, $(addsuffix .o,$(MODULES)))

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(TARGET).cpp -o $@

obj/%.o : %.cpp %.h
	mkdir -p obj
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf obj/ $(TARGET)
