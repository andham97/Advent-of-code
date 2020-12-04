main: main.o ../common.o
	gcc $^ -o $@

%.o: %.c
	gcc -g -c $< -o $@

clean:
	rm ./*.o ./main