# Makefile compilant les fichiers sources

# Définition des variables :

# Numéro du tp, utile pour les noms de certains fichiers
NUM_TP := X

# Répertoires
REP_SRC := src
REP_EXE := bin
REP_DOC := doc

# Compilation
CC := gcc
COPTION := -Wall -lm -DNDEBUG

# Liste des fichiers sources
SRC := $(wildcard $(REP_SRC)/*.c)

# Liste des fichiers objets
OBJ := $(patsubst $(REP_SRC)/%.c, $(REP_EXE)/%.o, $(SRC))

# Définition du nom de l'exécutable et de son emplacement final
EXE := charriersi-tp$(NUM_TP).out
CHE_EXE := $(REP_EXE)/$(EXE)

#Liste des extensions de fichiers à supprimer avec clean dans le répertoire source
SUPPR := *~ .old .bak \#*\#

#Doxyfile
DOXYFILE := Doxyfile



# Cible all
all: $(CHE_EXE)

# Règle de compilation
$(CHE_EXE): $(OBJ)
	$(CC) $(COPTION) $^ -o $@

# Règle pour les fichiers objets
$(REP_EXE)/%.o: $(REP_SRC)/%.c
	$(CC) $(COPTION) -c $< -o $@



# Cible clean
clean: 
	rm -f $(REP_EXE)/*.o $(CHE_EXE) $(REP_SRC)/$(SUPPR)


# Cible doc

# On génére la documentation
doc: $(REP_DOC)/$(DOXYFILE)
	doxygen $(REP_DOC)/$(DOXYFILE)

#Si il n'existe pas, on créer le fichier de configuration
$(REP_DOC)/$(DOXYFILE):
	doxygen -g $@
	sed -i 's#OUTPUT_DIRECTORY.*=.*#OUTPUT_DIRECTORY       = $(REP_DOC)#' $@

.PHONY: all clean doc

# Cible exe
exe:
	./bin/charriersi-tpX.out

# Cible tar
tar:
	tar -czvf charriersi-tp$(NUM_TP).tar.gz
