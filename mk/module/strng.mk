
# Directory:
STRNGDIR::= $(COMMDIR)/strng
vpath	%.c		$(STRNGDIR)



# Expected objects:
STRNG::= $(OBJDIR)/strng.o
DATA_STRNG::= data_strng.o
STRNGRAW::= $(addprefix $(RAWDIR)/, $(shell find $(STRNGDIR) -maxdepth 1 -type f -printf "%f " | sed -e 's/\.[cs]/.o/g') $(DATA_STRNG)) 



# Recipe:
$(STRNG): $(STRNGRAW)
	$(LD) $(MDFLAGS) $^ -o $@
