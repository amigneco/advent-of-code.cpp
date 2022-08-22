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

test: build
	find build -iname '*_test' -execdir ctest --output-on-failure \;
	# cd "$(build_dir)" && make test
