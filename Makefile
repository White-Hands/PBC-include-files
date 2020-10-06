Source = 123.c 234.c
Target = out
Object = 123.o 234.o

DIR_I = /usr/local/include/pbc
DIR_L = /usr/local/lib
FLAG = -I $(DIR_I) -L $(DIR_L) -Wl,-rpath $(DIR_L) -lpbc -lgmp

$(Target):$(Object)
	gcc -o $@ $^ $(FLAG)
	@echo "Succeed!"

.c.o:
	gcc -c $(Source)
clean:
	rm $(Target)
	rm $(Object)
