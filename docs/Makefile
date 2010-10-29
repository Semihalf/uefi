

default: bdk.html bdk-internals.html api-docs

clean:
	rm -rf *.html api-docs

%.html: %.txt
	asciidoc -a toc -a numbered $^

%.pdf: %.txt
	a2x -f pdf $^

api-docs: Doxyfile
	doxygen
