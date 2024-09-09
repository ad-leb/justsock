
# Directory:
_MAINDIR::= $(COMMDIR)/_main
vpath	%.c		$(_MAINDIR)
vpath	%.s		$(_MAINDIR)



# Expected objects:
_MAIN::= $(OBJDIR)/_main.o
DATA__MAIN::= data__main.o
_MAINRAW::= $(addprefix $(RAWDIR)/, $(shell find $(_MAINDIR) -maxdepth 1 -type f -printf "%f " | sed -e 's/\.[cs]/.o/g') $(DATA__MAIN)) 



# Recipe:
$(_MAIN): $(_MAINRAW)
	$(LD) $(MDFLAGS) $^ -o $@
