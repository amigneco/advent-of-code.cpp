build_dir := ./build

.PHONY: all clean configure build test

all: build

clean:
	cd "$(build_dir)" && make clean

configure:
	mkdir -p "$(build_dir)"
	cmake -S "." -B "$(build_dir)"

build:
	cmake --build "$(build_dir)" -j 6

test:
	cd "$(build_dir)" && make test
