tokenizer: history.o tokenizer.o main.o

	gcc -o tokenizer history.o tokenizer.o main.o

history.o: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c

main.o: main.c

clean:
	rm -f *.o tokenizer

run:
	./tokenizer
