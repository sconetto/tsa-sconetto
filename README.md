# Sistema de Consulta de cadastro do Conselho Federal de Odontologia (CFO) - Gerencial.
## Quantitativos sobre Profissionais e Entidades da área de odontologia no Brasil.


![Version](https://img.shields.io/badge/version-1.0-brightgreen.svg?style=flat-square)
![Language](https://img.shields.io/badge/language-C-blue.svg?style=flat-square)
***
#### TSA-III - Trabalho em Sala de Aula III - Trabalho Final
#### Disciplina: Estruturas de Dados e Algoritmos. Código: 193704
#### Professores: Dr. Nilton Correia da Silva e Dr. Fabricio Ataides Braz
#### Aluno: João Pedro Sconetto - Matrícula: 14/0145940
***
###### Observações
- Observação geral: Este é um arquivo de Markdown, pode ser melhor visualizado em navegadores web. Recomenda-se [Mozilla Firefox][firefox] ou [Google Chrome][chrome]. Também pode ser usado o site do [Dillinger] para visualizar o Markdown deste projeto (Para visualização no Dillinger é necessário ter o RAW do texto em Markdown para que ele apresente a prévia/exibição).
- Demais observações: Este trata-se de um projeto da matéria de Estruturas de Dados e Algoritmos (EDA), ministrado na Universidade de Brasília (UnB - FGA) Campus Gama, onde foi implementado uma solução em software para um problema proposto que pode ser encontrado nos arquivos _source_ na pasta do projeto `(doc/EDA_TSA_FINAL.pdf)`, demais explicações sobre implementação e execução serão posteriomente apresentados neste mesmo documento.

***
## Como executar o Sistema:
Para executar o sistema é simples, mas antes atente-se a alguns pré-requisitos para rodar na sua máquina:
+ O programa foi implementado em um Sistema Operacional (SO) _Linux-Based_ , logo para sua execução é necessário um terminal *bash*. (**OBS**: Isso não exclui a execução em SOs Windows ou Mac OS mas para tal é necessário fazer trativas de sistema para reconhecimento de comandos de sistema e compilação, no caso do Windows, por exemplo, é necessário arquivos fonte e binários do MinGW para compilação dos arquivos em .c, ou mudar os comandos `system("clear")` para `system("cls")`, mas lembrando que estes são apenas exemplos do que deve e pode ser feito e que vai depender do SO que você utiliza).
```
Dependencias necessárias:
    gcc - versão 5.3.1 ou superior
               ou
    g++ - versão 5.3.1 ou superior
    E todas bibliotecas necessárias para compilação
```
O sistema tem dois *shell scripts* presentes na pasta raíz para auxiliar a execução, para executar o programa desta forma basta rodar os seguintes comandos:
```
# ./clean.sh
# ./install-run.sh
```
Lembrando que se a execução for feita com o usuário padrão vai ser solicitado a senha de *super usuário (su)* para alterar permissões do arquivo de execução, também é pedido para o script de limpeza pois o arquivo de execução será protegido de escrita e para exclusão do mesmo recomenda-se acesso de administrador.

Para executar de forma manual basta rodar o seguinte comando:
```sh
$ gcc -v -Wall -ansi -W -pedantic -pedantic-errors -L. *.c -o bin/cfo-exe
$ sudo chown -R root:`whoami` ./bin/cfo-exe
$ sudo chmod +x ./bin/cfo-exe
$ ./bin/cfo-exe
```
Os comandos devem ser executados na pasta raíz do projeto.
Não me responsabilizo caso o código não rode em outros sistemas diferentes ao linux, pois a forma como o sistema trata os diretórios, abertura de arquivos, manipulação de memória, tudo pode diferir do implementado usando o linux, logo pode ser fonte de diversos erros e problemas, logo recomendo **_fortemente_** o uso de qualquer sistema *linux-based* que tenha um terminal *bash* para execução deste projeto.

**OBS**: A compilação no script e no comando acima está para *output* verboso, para compilação sem o *output* basta retirar a flag `-v` presente no comando.
***
## Relatório da complexidade do cógido:
1. Importação do arquivo dadoscfo.csv:
> A importação de dados do arquivo `dadoscfo.csv` se dá pela execução de dois laços `while`,
> para a criação já ordenada da árvore binária, onde o primeiro laço percorre todo o arquivo lendo a linha com os dados
> e o segundo laço faz a separação das palavras da linha de dados, após executada esta ação é por fim feita a inserção
> dos dados em folhas de uma ABP (Árvore Binária de Pesquisa) tendo esta a complexidade O(N³) onde N é o número
> de folhas a serem inseridas e complexidade N³ dado o fato de ter que se verificar se a raíz é nula, verificar se a inserção
> vai ser feita a esquerda ou a direita (balanceamento da árvore) e por fim se será inserido na folha atual
> ou na folha anterior, justificando a alta complexidade com a presença de estruturas de controle `if-else`.
2. Relatórios:
> Para apresentar os relatórios é necessário que se façam as buscas dado a opção selecionada
> para apresentação, logo se assemelha bastante ao exibir os demais relatórios, em casos de O(N) para
> buscas mais simples, perto da raíz, e O(log N), onde o logaritmo é na base 2, para folhas mais longes da raíz.
3. Relatório de um estado:
> Para apresentar o relatório de um estado é preciso buscar os dados nas folhas da árvore de forma
> ordenada, ou seja, buscar as folhas mais a esquerda de cada raíz para então verificar as folhas a direita,
> logo a complexidade nesta ação é, no melhor caso, de O(N) quando o estado desejado está nas folhas a esquerda,
> e de O(log N), onde o logaritmo é na base 2, para quando for necessário deslocar-se para folhas filhas na árvore durante a busca.
4. Dados de um município específico:
> Para apresentar os dados de um munícipio específico é necessário fazer uma busca
> nas folhas da árvore binária, é percorrida com um laço de repetição enquando não
> for nulo a folha, o melhor caso é quando o município está logo no início da árvore,
> neste caso a complexidade é de O(N), o pior caso é quando o município está no final da árvore,
> neste caso a complexidade é O(log N) onde o logaritmo é na base 2 (dado o fato de a árvore estar balenceada
> e não ser uma árvore degenerada).
5. Sair do sistema:
> Para sair do sistema a única ação antes de terminar a execução com o comando `exit(0)`
> é desalocar as árvores binárias com os dados,
> e para desalocar é preciso percorrer a árvore nas suas N folhas, logo a complexidade para percorrer
> as N folhas é O(N).

[//]: # (Essa seção abaixo após este comentário é para os possíveis links que existam no arquivo do Markdown para que possam funcionar de forma correta)


   [Dillinger]: <http://dillinger.io/>
   [firefox]: <https://www.mozilla.org/pt-BR/firefox/new/>
   [chrome]: <https://www.google.com/chrome/browser/desktop/index.html>