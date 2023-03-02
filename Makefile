
test_large_numbers: build_test_large_numbers run_test_large_numbers

build_test_large_numbers:
	cmake -DCMAKE_BUILD_TYPE=Debug . -Bbuild
	cmake --build build --target test_large_numbers

run_test_large_numbers:
	ctest --test-dir ./build

app_large_numbers: build_app_large_numbers run_app_large_numbers

build_app_large_numbers:
	cmake -DCMAKE_BUILD_TYPE=Debug . -Bbuild
	cmake --build build --target large_numbers

run_app_large_numbers:
	./build/large_numbers

app_simulated_sensors: build_app_simulated_sensors run_app_simulated_sensors

build_app_simulated_sensors:
	cmake -DCMAKE_BUILD_TYPE=Debug . -Bbuild
	cmake --build build --target simulated_sensors

run_app_simulated_sensors:
	./build/simulated_sensors

clean:
	rm -rf build