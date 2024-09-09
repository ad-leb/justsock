
$(TGT): $(_MAIN) $(SOCKS) $(STRNG)
	$(LD) $(LDFLAGS) $^ -o $@
