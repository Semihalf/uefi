SVNROOT=svn+ssh://kreesema@masvn/svn

.PHONY: all
all: fetch generate copy-headers

.PHONY: fetch
fetch: clean
	svn export -q ${SVNROOT}/t88/trunk/hwcode/regs/gen cn88xx
	svn export -q ${SVNROOT}/t85/trunk/hwcode/regs/gen cn85xx

.PHONY: generate
generate:
	rm -rf html
	./csr-tool.py --html \
	    --csr cn88xx,cn88xx \
	    --csr cn85xx,cn85xx

.PHONY: copy-headers
copy-headers:
	mv bdk-csrs.h ../libbdk-arch/
	mv bdk-csrs.c ../libbdk-arch/
	mv csr_db.lua ../lua-modules/

.PHONY: copy-html
copy-html:
	rm -rf /var/www/thunder/csr-html
	mv html /var/www/thunder/csr-html

.PHONY: copy
copy: copy-headers copy-html

.PHONY: clean
clean:
	rm -rf c-code html cn8??? *.pickle *.pyc

