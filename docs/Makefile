
src:=
src+=bdk.txt
src+=bdk-release-notes.txt

docs:=$(patsubst %.txt,%.html,$(src))
pdfs:=$(patsubst %.txt,%.pdf,$(src))

default: $(docs) api-docs lua-modules

pdf: $(pdfs)

clean:
	rm -rf api-docs $(docs) pdf lua-modules

%.html: %.txt
	asciidoc -d book -a toc2 -a theme=flask -a toclevels=2 -a numbered -o $@ $^

%.pdf: %.txt
	a2x -f pdf --fop $^

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
