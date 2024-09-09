.SUFFIXES:	# fuck implicit rules


MKDIR::= mk
MODSDIR::= $(MKDIR)/module
GOALDIR::= $(MKDIR)/goal


include $(MKDIR)/dirs.mk
include $(MKDIR)/vars.mk
include $(MKDIR)/phony.mk
include $(MKDIR)/rules.mk
include $(MODSDIR)/*.mk
include $(GOALDIR)/*.mk
