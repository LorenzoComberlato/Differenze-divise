
.PHONY: clean

CC = g++
CFLAGS = -Wall -g

SDIR = src
INC = include
ODIR = lib
OUT = bin
TEST = test

all: test

test: test.o creazione_vettori.o creazione_script.o differenze_divise.o queue_frazioni.o
	$(CC) $(CFLAGS) -o $(OUT)/test $(TEST)/test.o $(ODIR)/creazione_vettori.o $(ODIR)/creazione_script.o $(ODIR)/differenze_divise.o $(ODIR)/queue_frazioni.o

test.o: $(TEST)/test.cc $(INC)/creazione_vettori.hpp $(INC)/queue_frazioni.hpp $(INC)/differenze_divise.hpp $(INC)/creazione_script.hpp
	$(CC) $(CFLAGS) -o $(TEST)/test.o -c test/test.cc

creazione_vettori.o: $(SDIR)/creazione_vettori.cc $(INC)/creazione_vettori.hpp $(INC)/queue_frazioni.hpp
	$(CC) $(CFLAGS) -o $(ODIR)/creazione_vettori.o -c $(SDIR)/creazione_vettori.cc

creazione_script.o: $(SDIR)/creazione_script.cc $(INC)/creazione_script.hpp $(INC)/queue_frazioni.hpp
	$(CC) $(CFLAGS) -o $(ODIR)/creazione_script.o -c $(SDIR)/creazione_script.cc

differenze_divise.o: $(SDIR)/differenze_divise.cc $(INC)/differenze_divise.hpp
	$(CC) $(CFLAGS) -o $(ODIR)/differenze_divise.o -c $(SDIR)/differenze_divise.cc

queue_frazioni.o: $(SDIR)/queue_frazioni.cc $(INC)/queue_frazioni.hpp
	$(CC) $(CFLAGS) -o $(ODIR)/queue_frazioni.o -c $(SDIR)/queue_frazioni.cc

clean:
	@echo "Cleaning..."
	rm -f $(TEST)/test.o
	rm -f $(OUT)/test $(OUT)/test.exe $(OUT)/test.out
	rm -f $(OUT)/o.txt
	rm -f $(OUT)/plot.pdf
	rm -f $(OUT)/script
	rm -f $(ODIR)/*.o
	@echo "Cleaning completed!"
