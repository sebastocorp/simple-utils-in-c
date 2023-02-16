# Project directories
BUILD_DIR    :=build
OBJ_DIR      :=obj
LIB_DIR      :=lib
INCLUDE_DIR  :=include
SRC_DIR      :=src
TEST_DIR     :=test
DOC_DIR      :=doc
EXAMPLES_DIR :=examples
SRC_DIRS     :=$(shell find $(SRC_DIR) -type d)
OBJ_DIRS     :=$(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC_DIRS))

# Project files
SRC_FILES :=$(shell find $(SRC_DIR) -type f -iname *.c)
OBJ_FILES :=$(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(patsubst %.c,%.o,$(SRC_FILES)))

# Project binaries
BIN_NAME:=binary

# Project compiler variables
C:=gcc
# Compiler flags
C_OPS      :=-g
ifdef RELEASE
	C_OPS=-O3
endif
C_STD      :=-std=c18
C_INCLUDES :=-I$(INCLUDE_DIR) -I$(LIB_DIR)
C_WARN     :=-Wall -Wextra -Wconversion -Wpedantic -Werror
C_DEBUG    :=-g -fsanitize=address
C_FLAGS    :=$(C_OPS) $(C_STD) $(C_WARN) $(C_INCLUDES)
# Linker flags
C_LIBS_PATHS :=-L./$(LIB_DIR)
C_LIBS       :=#-l:example.a -lX11
C_LDFLAGS    :=$(C_LIBS_PATHS) $(C_LIBS)
ifdef SANITIZE
	C_LDFLAGS+=-fsanitize=address
endif

# Exports
export BUILD_DIR
export OBJ_DIR
export LIB_DIR
export INCLUDE_DIR
export SRC_DIR
export TEST_DIR
export DOC_DIR
export EXAMPLES_DIR
export SRC_FILES
export OBJ_FILES
export BIN_NAME

########################################################################################################################
### GENERAL
########################################################################################################################
.PHONY: all clean-all

all: gen-libs build

clean-all: clean-build clean-objs

########################################################################################################################
### BUILD
########################################################################################################################
.PHONY: build build-dirs clean-build

build: objs build-dirs $(BUILD_DIR)/$(BIN_NAME)

build-dirs:
	mkdir --parents $(BUILD_DIR)

clean-build:
	rm -r ./$(BUILD_DIR) || true

$(BUILD_DIR)/$(BIN_NAME): $(OBJ_FILES)
	$(C) -o $@ $^ $(C_LDFLAGS)

########################################################################################################################
### OBJS
########################################################################################################################
.PHONY: objs objs-dirs clean-objs

objs: objs-dirs $(OBJ_FILES)

objs-dirs:
	mkdir --parents $(OBJ_DIRS)

clean-objs:
	rm -r ./$(OBJ_DIR) || true

$(OBJ_FILES): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(C) -o $@ $< -c $(C_FLAGS)

########################################################################################################################
### LIBRARIES
########################################################################################################################
.PHONY: gen-libs

gen-libs:
	#$(MAKE) --directory $(LIB_DIR) all

########################################################################################################################
### TESTS
########################################################################################################################
.PHONY: tests

tests:
	$(MAKE) --directory $(TEST_DIR) all

########################################################################################################################
### EXAMPLES
########################################################################################################################
.PHONY: examples

examples:
	$(MAKE) --directory $(EXAMPLES_DIR) all

########################################################################################################################
### DOCUMENTATION
########################################################################################################################
.PHONY: gen-docs info

gen-docs: $(DOC_DIR)
	doxygen

$(DOC_DIR):
	mkdir --parents ./$(DOC_DIR)

info:
	$(info $(SRC_DIRS))
	$(info $(SRC_FILES))
	$(info $(OBJ_DIRS))
	$(info $(OBJ_FILES))
