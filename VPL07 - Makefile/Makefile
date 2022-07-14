CC := g++
CC_FLAGS := -Wall -g

SRC     := src
BUILD   := build
INCLUDE := include
EXE     := vpl_execution

all: vpl_execution

vpl_execution: ${BUILD}/Pessoa.o ${BUILD}/Funcionario.o ${BUILD}/Professor.o ${BUILD}/main.o
	@echo "Linking $^"
	$(CC) $(CC_FLAGS) -o ${EXE} $^

${BUILD}/Funcionario.o: $(SRC)/**/Funcionario.cpp $(INCLUDE)/Funcionario.hpp
	$(CC) -c $(CC_FLAGS) -I $(INCLUDE) $< -o $@

${BUILD}/Pessoa.o: $(SRC)/**/Pessoa.cpp $(INCLUDE)/Pessoa.hpp
	$(CC) -c $(CC_FLAGS) -I $(INCLUDE) $< -o $@

${BUILD}/Professor.o: $(SRC)/**/Professor.cpp $(INCLUDE)/Professor.hpp
	$(CC) -c $(CC_FLAGS) -I $(INCLUDE) $< -o $@

${BUILD}/main.o: $(SRC)/main.cpp
	$(CC) -c $(CC_FLAGS) -I $(INCLUDE) $< -o $@

clean:
	@echo "Clearing binary files"
	-rm -f  ${BUILD}/*.o ${EXE}
	