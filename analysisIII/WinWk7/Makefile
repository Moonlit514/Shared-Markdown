# 作业文件名
PROJ = WinWk7

all: $(PROJ).pdf


# 没有参考文献用这个
$(PROJ).pdf: $(PROJ).tex
	xelatex $(PROJ).tex
	xelatex $(PROJ).tex


# 有参考文献用这个
# $(PROJ).pdf: $(PROJ).tex
# 	xelatex $(PROJ).tex
# 	bibtex $(PROJ)
# 	xelatex $(PROJ).tex
# 	xelatex $(PROJ).tex


clean:
	rm -f *.aux *.log *.out *.toc *.bbl *.blg *.lof *.lot *.pdf *.gz