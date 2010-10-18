

default: bdk.html bdk-memory-map.html

clean:
	rm *.html

%.html: %.txt
	asciidoc -a toc -a numbered $^

