report: last.tex han.bib
	xelatex last
	bibtex last
	xelatex last
	xelatex last
	rm last.aux
	rm last.bbl
	rm last.blg
	rm last.log
	rm last.out


