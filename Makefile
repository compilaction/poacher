.POSIX:

examples:
	make -C examples all

clean:
	make -C examples clean

install:
	cp -r poacher/ $(PREFIX)/include

uninstall:
	rm -rf $(PREFIX)/include/poacher

.PHONY: examples clean install uninstall
