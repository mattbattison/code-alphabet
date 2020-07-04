hello: 
	nasm -f macho64 hello.asm
	ld -macosx_version_min 10.7.0 -lSystem -o hello hello.o

clean:
	rm -f hello hello.o

