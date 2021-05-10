fetchy: src/fetcher.c src/main.c
	$(CC) $? -o $@

clean:
	rm fetchy