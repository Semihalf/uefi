

default: bdk.html bdk-getting-started.html bdk-internals.html bdk-interactive.html bdk-bringup-guide.html bdk-faqs.html bdk-release-notes.html api-docs lua-modules api-docs

slides: bdk-intro-slides.html bdk-slides-advanced1.html

clean:
	rm -rf *.html api-docs

%.html: %.txt
	asciidoc -a toc2 -a theme=flask -a toclevels=5 -a numbered $^

%.pdf: %.txt
	a2x -f pdf $^

api-docs: Doxyfile
	doxygen

lua-modules: ${BDK_ROOT}/lua-modules/*
	ldoc -p "BDK Lua Modules" -t "BDK Lua Module Reference" -f discount -d $@ ${BDK_ROOT}/lua-modules

.PHONY: copy
copy:
	rm -rf /var/www/bdk3/*
	cp -r *.html *slides*.txt images api-docs lua* /var/www/bdk3/
