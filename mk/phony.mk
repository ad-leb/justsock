.PHONY:	default so init		zen down clear		run dbg install uninstall




default: init $(TGT)
so: init $(SO)
init: 
	@mkdir -p $(BINDIR)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(RAWDIR)



zen: down clear
	@rm -rf $(OBJDIR)
	@rm -rf $(BINDIR)
down:
	@rm -fd $(RAWDIR)/* 
	@rm -fd $(OBJDIR)/* 
	@rm -fd $(BINDIR)/*
clear:
	@for f in *; do if [ ! -d $$f ] && [ ! $$f = 'Makefile' ] && [ ! $$f = 'README.md' ]; then rm -fr $$f; fi; done



run:
	@./$(TGT)
dbg:
	@gdb $(TGT)
install:
	@install ${INCLUDE} ${INCPATH}/${NAME}.h
	@install ${SO} ${LIBPATH}/${SONAME}
	@ldconfig ${LIBPATH}/${SONAME}
	@ln -s ${LIBPATH}/${SONAME} ${LIBPATH}/lib${NAME}.so
	@echo -e "  Done. Now when you will be ready to use lib, DON'T FORGET to set LD_LIBRARY_PATH to needed path: ${LIBPATH}\n  ^_^\n"
uninstall:
	@rm -f ${INCPATH}/${NAME}.h
	@rm -f ${LIBPATH}/${SONAME}
	@rm -f ${LIBPATH}/lib${NAME}.so
	@ldconfig
	@echo -e "  Done! But I hope, you DON'T have to CHANGE a libpath BEFORE doing it? ${LIBPATH}\n  ^_^\n"
