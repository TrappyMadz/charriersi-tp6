# Makefile compilant les fichiers sources

# Définition des variables :

# Numéro du tp, utile pour les noms de certains fichiers
NUM_TP := 6

# Compilation
CC := gcc
COPTION := -Wall -lm -DNDEBUG

# Liste des fichiers sources
SRC := $(wildcard /*.c)

# Liste des fichiers objets
OBJ := $(patsubst /%.c, /%.o, $(SRC))

# Définition du nom de l'exécutable et de son emplacement final
EXE := charriersi-tp$(NUM_TP).out

#Liste des extensions de fichiers à supprimer avec clean dans le répertoire source
SUPPR := *~ .old .bak \#*\#

#Doxyfile
DOXYFILE := Doxyfile



# Cible all
all: $(EXE)

# Règle de compilation
$(EXE): $(OBJ)
	$(CC) $(COPTION) $^ -o $@

# Règle pour les fichiers objets
/%.o: /%.c
	$(CC) $(COPTION) -c $< -o $@



# Cible clean
clean: 
	rm -f /*.o $(EXE) /$(SUPPR)


# Cible doc

# On génére la documentation
doc: /$(DOXYFILE)
	doxygen /$(DOXYFILE)

#Si il n'existe pas, on créer le fichier de configuration
/$(DOXYFILE):
	doxygen -g $@
	sed -i 's#OUTPUT_DIRECTORY.*=.*#OUTPUT_DIRECTORY       = #' $@

.PHONY: all clean doc

# Cible exe
exe:
	./bin/charriersi-tpX.out

# Cible tar
tar:
	tar -czvf charriersi-tp$(NUM_TP).tar.gz
