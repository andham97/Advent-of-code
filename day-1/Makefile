main: main.o ../common.c
	gcc $^ -o $@

%.o: %.c
	gcc -g -c $< -o $@

clean:
	rm ./*.o ./main