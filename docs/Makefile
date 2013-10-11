

default: bdk.html bdk-getting-started.html bdk-internals.html bdk-interactive.html bdk-bringup-guide.html bdk-faqs.html bdk-release-notes.html bdk-cn70xx.html api-docs lua-modules

slides: bdk-intro-slides.html bdk-slides-advanced1.html

clean:
	rm -rf *.html api-docs

%.html: %.txt
	asciidoc -a toc2 -a theme=flask -a toclevels=5 -a numbered $^

%.pdf: %.txt
	a2x -f pdf $^

api-docs: Doxyfile
	doxygen

LUA_FILES:=$(wildcard ${BDK_ROOT}/lua-modules/*)
LUA_FILES:=$(patsubst %/bdk-version.lua,,$(LUA_FILES))
lua-modules: $(LUA_FILES)
	ldoc -p "BDK Lua Modules" -t "BDK Lua Module Reference" -f discount -d $@ ${BDK_ROOT}/lua-modules
	touch $@

.PHONY: copy
copy:
	rm -rf /var/www/bdk3/*
	cp -r *.html *slides*.txt images api-docs lua* /var/www/bdk3/
