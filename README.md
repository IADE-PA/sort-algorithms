# IADE/UE - Programação e Algoritmos  <!-- omit in toc -->

## Coleção de algoritmos de ordenação <!-- omit in toc -->

- [Contrato](#contrato)
- [Implementações](#implementações)
- [Testes](#testes)
- [Makefile](#makefile)

## Contrato

Um algoritmo de ordenação é definido pelo seguinte contrato, em [`src/sort.h`](src/sort.h):

```C
void sort(comparable collection[], const int size, int (*compare)(comparable, comparable));
```

Onde `comparable` representa um tipo de dados comparável, i.e., que permite estabelecer relações de igualdade (`== < <= > >=`).

```C
typedef void* comparable;
```

As implementações sobre arrays de inteiros seguem o contrato em [`src/sort_int.h`](src/sort_int.h):

```C
void sort(int collection[], const int size);
```

## Implementações

- [BubbleSort para arrays de inteiros](src/bubblesort_int.c)
- [BubbleSort genérico](src/bubblesort_generic.c)
- [QuickSort para arrays de inteiros](src/quicksort_int.c)
- [QuickSort genérico](src/quicksort_generic.c)

## Testes

As duas abordagens (inteiros e genérico) estão testadas recorrendo a testes unitários em [Unity](https://github.com/ThrowTheSwitch/Unity).

- [Testes para arrays de inteiros](tests/test_int.c)
- [Testes para arrays genéricos](tests/test_generic.c)

## Makefile

A compilação pode ser feita com o comando:

```bash
make
```

O resultado compilado é gerado para o diretório `bin` (o make cria o diretório se não existir). É equivalente a:

```bash
gcc -c src/bubblesort_int.c -o bin/bubblesort_int.o
gcc -c tests/unity/unity.c -o tests/bin/unity.o
gcc -c src/bubblesort_generic.c -o bin/bubblesort_generic.o
gcc -c src/quicksort_int.c -o bin/quicksort_int.o
gcc -c src/quicksort_generic.c -o bin/quicksort_generic.o
```

O Makefile inclui as seguintes flags de compilação:

- `-g`: gera código de depuração
- `-Wall`: mostra todos os warnings
- `-Wextra`: mostra warnings extras
- `-Werror`: mostra warnings como erros

Sâo também gerados os programas executáveis para os testes unitários, para o diretório `tests/bin` (o make cria o diretório se não existir):

```bash
gcc tests/test_generic.c bin/bubblesort_generic.o tests/bin/unity.o -o tests/bin/test_bubblesort_generic
gcc tests/test_int.c bin/quicksort_int.o tests/bin/unity.o -o tests/bin/test_quicksort_int
gcc tests/test_int.c bin/bubblesort_int.o tests/bin/unity.o -o tests/bin/test_bubblesort_int
gcc tests/test_generic.c bin/quicksort_generic.o tests/bin/unity.o -o tests/bin/test_quicksort_generic
```

Para gerar todo o código compilado e executar os testes fazer:

```bash
make tests
```

Para apagar todos os ficheiros compilados fazer:

```bash
make clean
```
