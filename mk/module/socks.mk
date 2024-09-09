
# Directory:
SOCKSDIR::= $(COMMDIR)/socks
vpath	%.c		$(SOCKSDIR)



# Expected objects:
SOCKS::= $(OBJDIR)/socks.o
DATA_SOCKS::= data_socks.o
SOCKSRAW::= $(addprefix $(RAWDIR)/, $(shell find $(SOCKSDIR) -maxdepth 1 -type f -printf "%f " | sed -e 's/\.[cs]/.o/g') $(DATA_SOCKS)) 



# Recipe:
$(SOCKS): $(SOCKSRAW)
	$(LD) $(MDFLAGS) $^ -o $@
