.PYONY : all clean

all : report.tex mandelbrot_ref.bib
	xelatex report.tex
	bibtex report
	xelatex report.tex
	xelatex report.tex

clean :
	rm -f *.aux *.bbl *.blg *.log *.out *.toc *.lof *.lot *.lol *.loa *.lox *.xdv *.pdf
	rm -f *.fdb_latexmk  *.fls  *.synctex.gz