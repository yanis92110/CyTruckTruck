CC = clang
CFLAGS = -g -Wno-everything -pthread

SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRCS))
HEADER = $(SRC_DIR)/header.h

LIBS = -lm

# La cible par défaut
main: $(OBJS) main.o
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

# Règle générique pour la création des fichiers objets
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Règle spécifique pour le fichier main.c
main.o: $(SRC_DIR)/main.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers générés et de l'exécutable
clean:
	rm -f main $(OBJS) main.o
