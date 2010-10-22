

default: bdk.html bdk-internals.html

clean:
	rm *.html

%.html: %.txt
	asciidoc -a toc -a numbered $^

