
${SO}: ${SOCKS} ${STRNG}
	gcc -shared -Wl,-soname,${SONAME} $^ -o $@
