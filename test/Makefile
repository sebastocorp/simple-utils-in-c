# Project directories
BUILD_DIR    :=build
OBJ_DIR      :=obj
LIB_DIR      :=lib
INCLUDE_DIR  :=include
SRC_DIR      :=src
#TEST_DIR     :=test
#DOC_DIR      :=doc
#EXAMPLES_DIR :=examples
SRC_DIRS     :=$(shell find $(SRC_DIR) -type d)
OBJ_DIRS     :=$(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC_DIRS))

# Project files
SRC_FILES :=$(shell find $(SRC_DIR) -type f -iname *.c)
OBJ_FILES :=$(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(patsubst %.c,%.o,$(SRC_FILES)))

# Project binaries
BIN_NAME:=tests.out
#STATIC_LIB_NAME :=libsu.a
#DYNAMIC_LIB_NAME:=$(patsubst %.a,%.so,$(STATIC_LIB_NAME))

# Project compiler variables
CC:=gcc
# Compiler flags
CC_OPS      :=-g
ifdef RELEASE
	CC_OPS=-O3
endif
CC_STD       :=-std=c18
CC_DLIB_FLAG :=#-fPIC
CC_INCLUDES  :=-I../build/$(INCLUDE_DIR)
CC_WARN      :=-Wall -Wextra -Wconversion -Wpedantic -Werror
CC_DEBUG     :=-g -fsanitize=address
CC_FLAGS     :=$(CC_OPS) $(CC_DLIB_FLAG) $(CC_STD) $(CC_WARN) $(CC_INCLUDES)
# Linker flags
LD_LIBS_PATHS :=-L../build/$(LIB_DIR)
LD_LIBS       :=-lsu
LD_FLAGS      :=$(LD_LIBS_PATHS) $(LD_LIBS) -static
ifdef SANITIZE
	LD_FLAGS+=-fsanitize=address
endif

########################################################################################################################
### GENERAL
########################################################################################################################
.PHONY: all clean-all

all: build

clean-all: clean-build clean-objs

########################################################################################################################
### BUILD
########################################################################################################################
.PHONY: build build-dirs clean-build

build: objs build-dirs $(BUILD_DIR)/$(BIN_NAME) #$(BUILD_DIR)/lib/$(STATIC_LIB_NAME) $(BUILD_DIR)/lib/$(DYNAMIC_LIB_NAME)

build-dirs:
	mkdir --parents $(BUILD_DIR)

clean-build:
	rm -r ./$(BUILD_DIR) || true

$(BUILD_DIR)/$(BIN_NAME): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LD_FLAGS)

#$(BUILD_DIR)/lib/$(STATIC_LIB_NAME): $(OBJ_FILES)
#	ar rc $@ $^

#$(BUILD_DIR)/lib/$(DYNAMIC_LIB_NAME): $(OBJ_FILES)
#	$(CC) -o $@ $^ $(LD_FLAGS) -shared

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
	$(CC) -o $@ $< -c $(CC_FLAGS)

########################################################################################################################
### LIBRARIES
########################################################################################################################
#.PHONY: gen-libs

#gen-libs:
#	$(MAKE) --directory $(LIB_DIR) all

########################################################################################################################
### TESTS
########################################################################################################################
#.PHONY: tests

#tests:
#	$(MAKE) --directory $(TEST_DIR) all

########################################################################################################################
### EXAMPLES
########################################################################################################################
#.PHONY: examples

#examples:
#	$(MAKE) --directory $(EXAMPLES_DIR) all

########################################################################################################################
### DOCUMENTATION
########################################################################################################################
#.PHONY: gen-docs info

#gen-docs: $(DOC_DIR)
#	doxygen

#$(DOC_DIR):
#	mkdir --parents ./$(DOC_DIR)

info:
	$(info $(SRC_DIRS))
	$(info $(SRC_FILES))
	$(info $(OBJ_DIRS))
	$(info $(OBJ_FILES))
