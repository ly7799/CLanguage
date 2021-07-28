

all:register unregister

register:
	gcc -g lifetime_reg.c -o reg

unregister:
	gcc -g lifetime_no_reg.c -o unreg

clean:
	rm reg
	rm unreg
