CFLAGS ?= -Wall -Werror=format -Werror=return-type -Werror=vla -Werror=uninitialized -Werror=maybe-uninitialized -Werror-implicit-function-declaration -Werror=declaration-after-statement
VG_FLAGS ?= -q --track-origins=yes --malloc-fill=66 --free-fill=66 --error-exitcode=1 --leak-check=full --track-fds=yes
VG_FILTER ?= ../filter_unclosed_files

run: formatter
	@echo "=== Style Checker Self-Test ==="
	$(VG_FILTER) valgrind $(VG_FLAGS) ./$< $<.c
	$(VG_FILTER) valgrind $(VG_FLAGS) ./$< utils.c

formatter: formatter.c utils.c

%.c:
	wget -nv --show-progress http://formenos.campus.mipt.ru/outgoing/C1/formatter/$@

clean:
	$(RM) formatter *.c
