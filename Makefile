OUTDIR = build
BINDIR = bin

$(OUTDIR)/main.o: src/fetcher.h src/main.c
	@mkdir -p $(@D)
	$(CC) -c src/main.c -o $@

$(OUTDIR)/fetcher.o: src/fetcher.h src/fetcher.c
	@mkdir -p $(@D)
	$(CC) -c src/fetcher.c -o $@

link: src/fetcher.c src/main.c
	@mkdir -p $(OUTDIR)/$(BINDIR)
	$(CC) $(OUTDIR)/fetcher.o $(OUTDIR)/main.o -o $(OUTDIR)/$(BINDIR)/fetchy

build:
	make $(OUTDIR)/fetcher.o && make $(OUTDIR)/main.o && make link

clean:
	rm -r $(OUTDIR)/