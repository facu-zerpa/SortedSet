# SortedSet

### Compilation

gcc -Wextra -Werror -Wall -std=c99 -pedantic -g -c sorted_set.c

gcc -Wextra -Werror -Wall -std=c99 -pedantic -g -o sset *.o main.c

### Check memory leaks

valgrind --show-reachable=yes --leak-check=full  ./sset

