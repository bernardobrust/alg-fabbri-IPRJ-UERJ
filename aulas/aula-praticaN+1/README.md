# Practical Lecture (07nov25) BigString - estrutura ligada de blocos textuais, aula 2

- Inicio 9:00. Horarios abaixo indicam horario do sorteio
- Uso auxiliar de IA permitido (gemini-cli)

## 1 Compilar repo alg, testar, benchmark (Avaliacao 9:10 outra chance 9:10)
git pull


## 2 Ultima chance para organizar repo (9:40)
Pasta disciplina 'alg'

```
alg-fabbri-IPRJ-UERJ/alg/
    sort/
    graph/
```

Atencao especial ao BigString (da outra aula pratica)
- localizar codigo da aula anterior de BigString
- 2.1 (9:50) indexacao "random access" / operator[i]
    - atencao: tabela de tamanhos cumulativos dos blocos == vetor ordenado
        - 2.2 (10:00) busca binaria para localizar qual bloco tem (i+1)-esimo caractere
        (aula anterior)

## 3 Inserir texto (10:30)

Objetivo: implementar:

**BigString::inserir(BigString &A, int i) assinatura // na pratica unsigned ou size_t**

Fazer toda esta etapa com duas representacoes dos blocos/nos da BigString
possiveis

repreentacao 1) Bloco de string dada por ponteiros para blocos (a principio alocados com
malloc)


```C
struct {
    char *block;
    BigStringNode *next;
} BigStringNode;
```

representacao 2) Bloco de string dado por um valor com tamanho maximo,
sendo que, assim, todaos os nos BigStringNode tem o mesmo tamanho na memoria,
a string ocupa mais ou menos espaco desse blocl:

```C
#define MAX_CHAR_PER_BLOCK 4096  // algum multiplo de 2, exemplos:
                                 // 64 para alinhar com cacheline tipico (64 bytes)
                                 // 4096 page = aprox 64 cache lines
struct {
    char block[MAX_CHAR_PER_BLOCK];  // o quanto eh usado eh dado por '\0'
    BigStringNode *next
} BigStringNode;
```

Lembrando que essas representacoes ja foram exercitadas na primeira aula de
BigString.

### Exemplo 

```C
    S.inserir(A, 1013) --> insere BigString A na posicao 1013 (apos caractere 1013)
```
    
### Etapas Intermediarias    

#### 3.1) 

```C
S.concat(A): concatena A na string S ("append")
```

#### 3.2) 
```C
S.inserirSimples("hello",i)   // insere string simples "hello" na posicao (caractere) i de S
```

# Todas as aulas praticas presenciais devem, posteriormente, estar 100% finalizadas em casa antes da proxima aula pratica
