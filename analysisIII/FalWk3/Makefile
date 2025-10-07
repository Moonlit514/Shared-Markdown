.PHONY: all clean

TARGET = FalWk3.pdf
SRC = FalWk3.tex

all: $(TARGET)

$(TARGET): $(SRC)
	xelatex $(SRC)

clean:
	rm -f *.aux *.bbl *.blg *.log *.out *.toc *.lof *.lot *.lol *.loa *.lox *.xdv *.pdf
	rm -f *.fdb_latexmk *.fls *.synctex.gz