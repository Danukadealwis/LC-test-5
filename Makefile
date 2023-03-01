
test: build_test run_test

build_test:
	cmake -DCMAKE_BUILD_TYPE=Debug . -Bbuild
	cmake --build build --target test_large_numbers

run_test:
	ctest --test-dir ./build

clean:
	rm -rf build