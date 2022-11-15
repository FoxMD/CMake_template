dependency:
	cd build && cmake .. --graphviz=test.dot && dot -Tpng test.dot -o test.png

prepare:
	rm -rf build
	mkdir build
	cd build && conan install .. && cd ..

make_conan:
	cd build && conan install ..

install:
	sudo apt-get install gcovr lcov

install_docs:
	pip install jinja2 Pygments
	sudo apt-get install doxygen