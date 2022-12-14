CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

SRC_DIR := src
OBJ_DIR := obj
OUT_DIR := bin
OUT := lexer_runner parser_runner interpreter_runner

LEX_LIB := token.cpp exception.cpp lexer.cpp
PAR_LIB := ast/astree.cpp ast/astlist.cpp ast/astleaf.cpp ast/obj.cpp ast/null_stmnt.cpp ast/assign_stmnt.cpp ast/expr_stmnt.cpp \
			ast/if_stmnt.cpp ast/while_stmnt.cpp ast/block_stmnt.cpp parser.cpp
INT_LIB := interpreter.cpp 

LEX_SRC += $(LEX_LIB) lexer_runner.cpp
PAR_SRC += $(LEX_LIB) $(PAR_LIB) parser_runner.cpp
INT_SRC += $(LEX_LIB) $(PAR_LIB) $(INT_LIB) interpreter_runner.cpp
# LEX_SRC := LEX_LIB + lexer_runner.cpp
# PAR_SRC := token.cpp exception.cpp lexer.cpp parser.cpp parser_runner.cpp ast/astree.cpp ast/astlist.cpp ast/astleaf.cpp \
# 			ast/obj.cpp ast/null_stmnt.cpp ast/assign_stmnt.cpp ast/expr_stmnt.cpp ast/if_stmnt.cpp ast/while_stmnt.cpp \
# 			ast/block_stmnt.cpp 
# INT_SRC := token.cpp exception.cpp lexer.cpp parser.cpp ast/astree.cpp ast/astlist.cpp ast/astleaf.cpp ast/obj.cpp \
# 			ast/null_stmnt.cpp ast/assign_stmnt.cpp ast/expr_stmnt.cpp ast/if_stmnt.cpp ast/while_stmnt.cpp ast/block_stmnt.cpp \
# 			interpreter.cpp interpreter_runner.cpp

LEX_OBJ := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(LEX_SRC))
PAR_OBJ := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(PAR_SRC))
INT_OBJ := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(INT_SRC))

all: $(OUT)

lexer_runner: $(LEX_OBJ) 
	@mkdir -p $(OUT_DIR)
	$(CXX) -o $(OUT_DIR)/$@ $(LEX_OBJ) 

parser_runner: $(PAR_OBJ)
	@mkdir -p $(OUT_DIR)
	$(CXX) -o $(OUT_DIR)/$@ $(PAR_OBJ)

interpreter_runner: $(INT_OBJ)
	@mkdir -p $(OUT_DIR)
	$(CXX) -o $(OUT_DIR)/$@ $(INT_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)
