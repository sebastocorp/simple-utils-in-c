TESTS_DIR := tests

.PHONY: docs tests
docs: docs-dir
	doxygen

docs-dir:
	mkdir docs

tests:
	cd $(TESTS_DIR) && $(MAKE) tests
