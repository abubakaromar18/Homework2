all: hash

hash:
	cc -o hash hashcode.c

clean:
	rm -f hash