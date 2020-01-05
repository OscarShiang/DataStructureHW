TEST=../test_data.txt

all: longer original shorter

longer:
	g++ longer.cpp -o longer -O2

original:
	g++ original.cpp -o original -O2

shorter:
	g++ shorter.cpp -o shorter -O2

test:
	./longer < $(TEST)
	./shorter < $(TEST)
	./original < $(TEST)

clean:
	rm longer original shorter
