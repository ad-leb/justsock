
$(RAWDIR)/%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@
$(RAWDIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
