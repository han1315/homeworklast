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

slide: slide.tex
	xelatex slide
	rm slide.log
	rm slide.nav
	rm slide.out
	rm slide.aux
	rm slide.snm
	rm slide.toc


