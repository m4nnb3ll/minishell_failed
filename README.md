# minishell
A program that mimics the bash.

> to run valgrind run the following command: `valgrind --suppressions=valgrind_suppress.txt --leak-check=full --show-leak-kinds=all --track-origins=yes --show-mismatched-frees=yes`


# The grammar used

```
<CMD>		--> <EXP(0)>
<EXP(p)> 	--> <SIMP> {<B> <EXP(q)>}
<B>			--> '|' | '||' | '&&'
<SIMP>		--> {
					name,
					args,
					redirections
				}
```