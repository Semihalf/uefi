

default: bdk.html bdk-internals.html

clean:
	rm -f *.html

%.html: %.txt
	asciidoc -a toc -a numbered $^

%.pdf: %.txt
	a2x -f pdf $^

