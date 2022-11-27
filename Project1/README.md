# Análise e Síntese de Algoritmos - Projeto 1

## Descrição do Problema

Pretende-se ladrilhar, ou seja cobrir com ladrilhos, uma dada área definida sobre um retângulo,
delimitada por um caminho em escada, tal como ilustrado na Figura 1. A área a ladrilhar é
definida sobre uma grelha unitária, com `n` linhas e `m` colunas. Os ladrilhos a utilizar são sempre
quadrados com dimensões do lado múltiplas da unidade, ou seja: 1×1, 2×2, etc. Consi-
derando que pode utilizar um número arbitrário de ladrilhos quadrados das várias dimensões,
existem diversas configurações possíveis dos ladrilhos que permitem cobrir totalmente a área
em questão.
No exemplo ilustrado na Figura 1, existem 4 configurações possíveis para ladrilhar a área em
questão. Uma configuração apenas utliza ladrilhos com dimensão 1×1, sendo que as restantes
três utilizam ladrilhos com dimensões 1×1 e 2×2.

![Exemplo 1](./images/asa1.png "Figura 1")
```
Figura 1: Exemplo de uma área a ladrilhar e respetivas configurações.
```

![Exemplo 2](./images/asa2.png "Figura 2")
```
Figura 2: Especificação de um caminho em escada pelos valores ci, para n = 4 e m = 5.
```
### Objectivo
Dadas as dimensões `n` e `m`, bem como a especificação do caminho em escada que
delimita a área a ladrilhar, pretende-se determinar onúmero de configurações distintasde
ladrilhos que permitem ladrilhar a referida área.

Tal como ilustrado na Figura 2, a especificação do caminho em escada será efetuada através de
uma sequência denvalores inteirosci, para `i= 1 , 2 ,...,n`, que indicam o índice da coluna pela
qual passa o caminho na i-ésima linha. Note que `0 ≤ ci ≤m, para i= 1 , 2 ,...,n`. Note também
que `ci ≥ ci−1 , para i= 2 , 3 ,...,n`. A Figura 3 ilustra todos os caminhos em escada possíveis
para `n = 3` e `m = 3`.

## Input

O ficheiro de entrada contendo a informação relativa ao problema a resolver, é definido da
seguinte forma:

- uma linha contendo apenas um valor inteiron, que indica o número de linhas da grelha
    unitária utilizada para descrever a área a ladrilhar;
- uma linha contendo apenas um valor inteirom, que indica o número de colunas da grelha
    unitária utilizada para descrever a área a ladrilhar;
- nlinhas, em que cada linha contém apenas um valor inteiroci, que indica o índice da
    coluna pela qual o caminho em escada passa nai-ésima linha.

## Output

O programa deverá escrever no output uma linha contendo um único valor inteiro, que corres-
ponderá ao número de configurações distintas de ladrilhos que permitem ladrilhar a área em
questão. Considere que, para o caso em que o caminho em escada é definido por `ci = 0`, para
`i = 1 , 2 ,...,n`, o número de configurações é 0.

![Exemplo 3](./images/asa3.png "Figura 3")

```
Figura 3: Ilustração de todos os caminhos em escada possíveis para n = 3 e m = 3, com os respetivos valores de ci
```

## Exemplos

### Input

```
4 
5 
0 
2 
3 
5
```

### Output

```
4
```

### Input

```
3
4
4
4
4
```

### Output

```
13
```

## Parâmetros de compilação:

```
C++: g++ -O3 -std=c++11 -Wall file.cpp -lm
```