# IADE/UE - Programação e Algoritmos  <!-- omit in toc -->

## Coleção de algoritmos de ordenação <!-- omit in toc -->

- [Contrato](#contrato)
- [Implementações](#implementações)
- [Testes](#testes)

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

Para executar os testes fazer:

```bash
$ make tests
```
