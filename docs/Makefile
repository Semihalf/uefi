
src:=
src+=bdk.txt
src+=bdk-release-notes.txt
src+=bdk-bringup-guide.txt
src+=bdk-faqs.txt
src+=bdk-getting-started.txt
src+=bdk-internals.txt
src+=chip-cn70xx.txt
src+=chip-cn78xx.txt

docs:=$(patsubst %.txt,%.html,$(src))
pdfs:=pdf/bdk-manual.pdf

default: $(docs) api-docs lua-modules

pdf: $(pdfs)

clean:
	rm -rf api-docs $(docs) pdf lua-modules

%.html: %.txt
	asciidoc -d book -a toc2 -a theme=flask -a toclevels=2 -a numbered -o $@ $^

pdf/%.pdf: %.txt
	mkdir -p pdf
	a2x -f pdf --fop -D pdf $^

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
	cp -r *.html images api-docs lua* /var/www/bdk3/
