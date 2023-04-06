CC = g++
CFLAGS = -Wall -Werror -Wconversion
SRCDIR = archivos_cpps/
INCDIR_CONSTRUCCIONES = $(SRCDIR)construcciones/
INCDIR_CASILLEROS = $(SRCDIR)casilleros/

main:
	$(CC) $(CFLAGS) $(SRCDIR)*.cpp $(INCDIR_CONSTRUCCIONES)*.cpp $(INCDIR_CASILLEROS)*.cpp -o Andypolis

valgrind: 
	valgrind --tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./Andypolis