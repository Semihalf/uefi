

default: bdk.html bdk-internals.html bdk-interactive.html bdk-faqs.html api-docs

clean:
	rm -rf *.html api-docs

%.html: %.txt
	asciidoc -a toc -a toclevels=5 -a numbered $^

%.pdf: %.txt
	a2x -f pdf $^

api-docs: Doxyfile
	doxygen

.PHONY: copy
copy:
	rm -rf /var/www/bdk/*
	cp -r *.html *.png api-docs lua* /var/www/bdk/
