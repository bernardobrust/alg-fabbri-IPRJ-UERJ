# Algoritmos e Estrutura de Dados 2025

## Informações gerais
- **Professor** [Ricardo Fabbri, Ph.D](http://rfabbri.github.io)
- **Datas** das avaliações teóricas
    - P1: qua1Out25
    - P2: qua2Dez25
- **Repositorio** principal da disciplina: 
    git clone http://github.com/rfabbri/alg-fabbri-IPRJ-UERJ

## Criterio de Avaliacao

M = 0.3*P + 0.7*T
P = (P1 + P2)/2
T = nota de trabalhos e tarefas

## Aulas Teoricas
- Exemplos em codigo fonte de videogames e software voltado para bolsa Google
  Summer of Code
- Apenas os melhores algoritmos e as melhores implementacoes!
    - Até onde a IA consegue ajudar em algoritmos de alta eficiencia e altamente
      precisos, usando técnicas especializadas e lógica elaborada?
    
## Aulas Praticas
- O objetivo das aulas praticas sera trazer o aluno para um estado de
  proficiencia que tambem se utiliza no ambito profissional, nao apenas o
  minimo suficiente para realizar as tarefas

- IA: Iremos usar o gemni-cli, mas tendo o claude-code como referencia de sistema
  production-grade em diferentes niveis durante o curso

## Explicacao sobre este repositorio
Como compilar, etc
ver GEMINI.md
  
## Linguagem
C/C++ com CMake

### Revisao de C, ponteiros, etc.
C/C++ Fabbri Parte 1 https://youtu.be/Gru0DnXWr0g

C/C++ Fabbri Parte 2 https://youtu.be/k0KfKildD-U

## IDE/Ambiente
- VSCode eh padrao atualmente para explorar codigo como IA, porém não é avançado
- Usaremos o Vim, em especial explorando o Neovim (NVim) (motivacao nos slides).
  A IDE mais respeitada por desenvolvedores de acordo com o Stack Overflow
  Developer Survey 2025.
- Na prática usam-se ambos.

### IA/LLMs
- Uso de IA será explorado em alguns projetos
- Na primeira aula foi adotado o Gemni e o Gemni-CLI (13ago25)
- Video sobre Gemni-CLI https://www.youtube.com/watch?v=KrnyAJyjVG4
- No entanto, o foco do curso será na qualificação de programação profissional e base
teorica sem IA.

## Trabalhos

- Semanais
    - Praticos
        - Lista de exercicios em casa
        - Nao entrega lista, mas programa na hora da aula pratica
        - Testes passando -> nota
    - Teoricos
- Trabalho final da disciplina: consiste em trabalhos maiores
- IA sera permitida em alguns trabalhos
- Toda correção terá acompanhamento individual do professor para garantir
  conhecimento

### Envio

Os trabalhos que forem para serem entregues diretamente ao professor devem ser 
enviados para:

rfabbri@iprj...

ATENCAO: subject tem que conter: [alg-iprj]

Porem a maioria das atividades valendo nota sera semanal e avaliada diretamente
em sala de aula.

### Detalhes, Data de Entrega, etc

A informação de qual tarefa foi passada em que dia pode ser encontrada na pasta
aulas/, a aula correspondente (a de maior numero). No entanto, é
responsabilidade do aluno comparecer às aulas e ficar atento aos e-mails ou se
inteirar com os colegas que compareceram. Chegar a uma aula sem ter se inteirado
da aula anterior quase sempre irá incorrer na falta de compreensão e perda de
nota em atividades.

### Tarefa 0: questionario e contas, até 17h de 14ago25

A tarefa 0.1) consiste em responder ao questionário (enviado por email).

Solicito outras tarefas:

0.2) criar uma conta github até a mesma data, caso ainda não tenha, 

0.3) assinatura do plano de estudante do Gemni gratuito por 1 ano, que foi eleito para algumas atividades do curso.

Recomendo já instalar o gemni-cli na sua máquina pessoal, que foi o assistente
de programação eleito/justificado em aula.

### Tarefa  1 

#### Mini-tarefa: jogo centipede
O jogo centipede esta em scripts/
Pratique o jogo em casa consistentemente.

Voce tera 5min em aula para mostrar que consegue atingir um score de 80

#### Mini-tarefa: vimtutor
Rode vimtutor no terminal e faca todas as atividades. Em aula havera perguntas.

#### Tarefa principal

Fazer lista de exercicios e praticar por conta.
Lista de exercicios (explicada em aula)
1) Programar e testar a operacao merge_ordenado de dois vetores ordenados sem IA
    - Entrada: dois vetores ordenados v e w
    - Saída: um vetor ordenado vw contendo os elementos de v e w
2) Programar e testar a operacao básica partition do quicksort: dado um elemento x de um
  vetor v, particionar o vetor v em elementos menores que x, x, seguidos dos
  maiores que x.
    - Entrada: um vetor v, e um índice ix  (de um elemento x tq v[ix] == x)
    - Saída: v  da seguinte forma [ elementos < x | x | elementos > x ]
  Nao utilizar nenhum vetor auxiliar.
3) Repetir para listas encadeadas
- Tipo de dado: int
- IMPORTANTE: Seguir recomendacoes do GEMINI.md sobre boas praticas de código e
  testes. Em especial, usar arrays em C [] e nao STL vector, pois se trata de
  codigo de alta performance.
- Casa tarefa acima devera ter um comando correspondente cuja entrada no stdin
  sao um conjunto de numeros inteiros positivos separados por espaco, e cuja
  saida sera o vetor ordenado no stdout. O nome exato dos executaveis sao
  'merge-ordenado' e 'partition'. 

Na aula prática você tera 30 min para programar um algoritmo similar solicitado
pelo professor.

### Tarefa 2 para sex29ago25

#### Mini-tarefa: ler sobre git
Ler capitulo 1 e 2 do livro Pro Git https://git-scm.com (Getting Started e
Git Basics).
Serao feitas perguntas em aula

#### Mini-tarefa: finalizar o fork do repositorio da disciplina
Vamos dar um nome "my" para seu remote.

github --> entra no repositorio da disciplina --> fork (botao canto superior direito)

```
git remote add my URL
```
Onde URL eh a url do seu repositorio forked do github (botao verde)
```
git fetch my
```

Agora vc consegue adicionar sua solucao com git add e git commit, 
depois
```
git push my main
```

##### Benchmark no fork
Ao fazer esse push, o github iniciara uma action automatica de benchmark. No endereco
https://rfabbri.github.io/alg-fabbri-IPRJ-UERJ/dev/bench/
voce vera graficos de performance do seu algoritmo. (ou, se voce fez fork, isso
estara nesse endereco com seu user no lugar de rfabbri)
Confira na aba Action do
github para certificar-se que o benchmark foi executado.
Se visualizar no repositorio do professor, um grafico de todos os alunos sera
mostrado.

##### Mini-tarefa: refazer o sorted_merge_3way
- Refazer o `sorted_merge_3way` da Tarefa 1 em casa, ate que o make test passe
- Fazer commit 
- Fazer git push no seu fork conforme acima
- novos testes serao inseridos e o seu programa precisa passar os testes para
se obter ponto nesta tarefa

**Bonus 1**: Caso seu algoritmo seja entre os 5 mais rapidos da sala no
benchmark `make eval`, voce ganhara um bonus de nota no valor de uma tarefa seguinte

**Bonus 2**: Caso seu algoritmo seja claramente mais rapido que o gabarito,
voce ganhara um bonus de nota no valor de 1 questao da prova p1.

##### Tarefa principal
1.1) Lista de exercicio de ponteiros.
1.2) Em casa, programar exercicios com lista encadeada com int: inserir no, remover no. 
Na aula prática você tera 30 min para programar um algoritmo similar solicitado
pelo professor, onde a lista encadeada pode armazenar um tipo de dado mais
complexo que int. Realize treinos programando exercicio de livros ou internet
sobre lista encadeada. *Pode usar IA nesta avaliacao especificamente.*

### Tarefa 3 para (sex12set25, era: sex05set25)

#### Mini-tarefa: ler sobre git branching
Ler capitulo 3 do livro Pro Git https://git-scm.com (Getting Started e
Git Basics).
Serao feitas perguntas em aula

#### Tarefa principal
Terminar de realizar a programação de listas encadeadas de nós contendo strings,
dentro do seguinte projeto: editor de estruturas basicas

**Entrada**
- Digite o tipo de implementacao de lista: (1) Encadeada (2) Duplamente encadeada (3) Buffer circular
    - Para cada opcao: digite (i) para inserir (d) deletar. 
- Para cada dessas opcao: escolher posicao para inserir e posicao para deletar
As listas sao todas de strings
- Nao pode ser usada STL, mas bonus sera dado a quem comparar com STL.
- procure usar malloc e nao new, para aprender manipulacao de bytes.
- Permitir ao usuario escolher a representacao de string dentro de no: char * ou
  char name[MAX_CHARS]
- Escrever casos de teste para cada combinacao na pasta tests/
- Maiores esclarecimentos: https://github.com/rfabbri/alg-fabbri-IPRJ-UERJ/issues/2
- FUTURO: separar em backend/frontend:
    - especificar stdin/stdout format style com ctrl-D se quiser interativo
    - ldi"data"f : comandos de 1 letra e numeros: (l) list (d) dinamic (i)
      insert "data" (f) front
    - d20 : delete 20th element
    - seria uma minilinguagem extremamente simples, com os comandos de teclado
      como o usuario faria
    - o frontend simplemente traduziria para isso
    - maquina de estado separada
    - estilo eric raymond hacker

## Livros
- A melhor referencia para cada algoritmo
- Programming Pearls

## Bonus Topcoder
- O aluno que comprovar participação em competições de programação do Topcoder
  (ou outras) poderá ter bonus de nota atribuido pelo professor. As atividades
  devem ser restritas à programação algoritmica em si, e não sobre design de software.

## TODO
- abrir ticket de suporte IPRJ (alunos tambem devem)
    - wifi uerj1 no lab 309 continua lenta
    - solicitar conexao a cabo liberada

## See also
- Dijkstra On the foolishness of "natural language programming" https://news.ycombinator.com/item?id=43564386 
- [Projeto e Analise de Algoritmos - wiki](http://wiki.nosdigitais.teia.org.br/PAA) (em fase de upgrade)
- Qualquer duvida, o prof. Fabbri se coloca à disposicao para google meet https://meet.google.com/ytc-cqrv-qjm
