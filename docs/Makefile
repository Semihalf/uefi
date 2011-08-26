

default: bdk.html bdk-internals.html bdk-interactive.html bdk-bringup-guide.html bdk-faqs.html bdk-release-notes.html api-docs

slides: bdk-intro-slides.html

clean:
	rm -rf *.html api-docs

%.html: %.txt
	asciidoc -a toc2 -a theme=flask -a toclevels=5 -a numbered $^

%.pdf: %.txt
	a2x -f pdf $^

api-docs: Doxyfile
	doxygen

.PHONY: copy
copy:
	rm -rf /var/www/bdk/*
	cp -r *.html *slides.txt images api-docs lua* /var/www/bdk/
