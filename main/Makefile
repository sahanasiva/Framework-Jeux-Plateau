CC = g++
CFLAGS = -Wall -g
EXEC_NAME = jeux
INCLUDES =-I/.
FRAMEWORK = Joueur.o Plateau.o Piece.o Partie.o
ECHECS = echecs/EchecsJoueur.o echecs/EchecsPlateau.o echecs/Echecs.o echecs/EchecsPiece.o

MAIN = main.o

INSTALL_DIR = /usr/bin

all : $(EXEC_NAME)

clean :
	rm -f *~ \#*\#
	rm -f $(EXEC_NAME) $(FRAMEWORK) $(ECHECS) $(MAIN)

$(EXEC_NAME) : $(FRAMEWORK) $(ECHECS) $(MAIN)
	$(CC) -o $(EXEC_NAME) $(FRAMEWORK) $(ECHECS) $(MAIN) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
