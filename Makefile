ms: minishell.c minishell.h
	gcc -DDEBUG -o ms  minishell.c

clean:
	rm -f ms
