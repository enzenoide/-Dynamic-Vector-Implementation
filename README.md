# 🧮 Implementação de Vetor Dinâmico em C++

Atividade avaliativa para implementar um vetor dinâmico, similar ao `std::vector`do C++ e ao _Python List_ em python. Deve ser feita em **C++**, usando alocação dinâmica de memória.


## 🎯 Objetivo
Nesta atividade você deve implementar uma biblioteca de classes para manipulação de um vetor dinâmico de números inteiros. São duas classes a serem desenvolvidas:

- 🏗️ Uma implementada com alocação dinâmica de _arrays_

- 🔗 Outra implementada com lista duplamente ligada


## 🔍 Vetor dinâmico

Um vetor dinâmico é uma estrutura que possui capacidade de armazenamento modificada dinamicamente, conforme
a quantidade de elementos inseridos/removidos do vetor. Um exemplo prático, implementado na linguagem de programação **Python**, é o tipo _List_.

A principal forma de acesso aos elementos é através de um valor inteiro associado à posição do elemento no vetor,
chamado índice. A quantidade de elementos determina os índices válidos em um vetor. Exemplo: Se o vetor possuir
`1234` elementos os índices válidos são de `0` a `1233`.

### 📚 Características Principais:
- ✨ Capacidade ajustável automaticamente
- 🔢 Acesso por índices (`0` a `size-1`)
- 📈 Cresce conforme necessidade
- 📉 Pode reduzir (opcional)

Inserções podem ser feitas para qualquer índice válido, além do próximo índice disponível. Por exemplo, em um
vetor de `18` elementos os índice válidos são todos os inteiros entre `0` e `17`, inclusive. Além desses índices, um elemento
pode ser inserido no índice `18`, que é o índice disponível ao se adicionar um elemento no "final" da lista. A remoção pode
ser feita para qualquer índice válido do vetor, o que causa uma diminuição da quantidade de elementos armazenados.
A busca deve retornar o índice do elemento encontrado ou `−1` caso o elemento buscado não esteja presente no vetor.
Além das operações de inserção, busca e remoção baseadas nos índices, há outras operações úteis, como inserir no
início, _push front_, inserir no final, _push back_, remover do início, _pop front_, e remover do final, _pop back_, além de outras.
A lista de operações (métodos) a serem implementadas está descrita na seção 4.


## 🏗️ Estrutura do Projeto

```markdown
.
├── 📜 CMakeLists.txt             # Configuração do CMake
├── 📂 include/                   # Diretório include da biblioteca
│   └── 📂 vector-lib/            # Código fonte da implementação (.hpp)
│       ├── 🏗️ vector-array.hpp   # Vetor com arrays alocados dinamicamente
│       └── 🔗 vector-linked.hpp  # Vetor com listas duplamente ligadas
├── 📂 tests/                     # Testes para a implementação
│   ├── 📜 CMakeLists.txt         # Configuração do CMake para os testes
│   ├── 📂 inputs                 # Arquivos de entradas para alguns testes
│   ├── 🧪 tests_array/           # Testes da classes vector_array
│   │   └── 📜 CMakeLists.txt     # Configuração
│   ├── 🧪 tests_linked/          # Testes da classes vector_linked
│   │   └── 📜 CMakeLists.txt     # Configuração
│   └── 🧪 tests_student/         # Testes feitos pelo aluno
│       └── 📜 CMakeLists.txt     # Configuração
└── 📂 build/                     # Diretório para construção (gerado)
```

Os diretórios `tests_array` e `tests_linked` possuem vários arquivos `.cpp`, 
cada um com um teste. 

## 🛠️ Configuração

Para desenvolver a tarefa você deve usar um ambiente configurado adequadamente. 
Para compilar, executar e testar é necessário ter o **CMake**, versão **3.31** ou superior, e um **compilador C++**, com suporte a `C++23`.  

Ambientes pré-configurados podem ser usado. É fornecido um arquivo _devcontainer_ configurado adequadamente par o desenvolvimento do projeto. A seguir 2 formas simples de usar o ambiente pré-configurado:  _codespace_ do GitHub e `VS Code` local. 

### 1. 🖥️ Codespace

Você pode editar o projeto diretamente no navegador através do **codespace**.

Na aba `code` clique emno botão `<> code`, selecione codespaces e depois `Create codespace on main`.
Uma nova abra será aberta no navegador com um ambiente de desenvolvimento conigurado para o projeto. 
É uma versão do **VS Code** para web. Use normalmente como o **VS Code** local. 

### 2. 🔵 VS Code local

#### 🔧 Pré-requisitos 
- 🐳 Docker
- 💻 VSCode


#### 🔄 Configuração passo a passo

1. 🔽 Clone o repositório:
```bash
git clone <URL_DO_REPOSITÓRIO>
cd <NOME_DO_PROJETO>
```

2. 📂 Abra no VSCode:
```bash
code .
```

* **OU** abra via `VSCode -> Abrir pasta` (_open folder_)

3. 🐳 Inicie o _Dev Container_:

Pressione `F1` → "Dev Containers: Reopen in Container"`

Ou clique no ícone ◇ no canto inferior esquerdo

Aguarde a configuração (primeira execução pode demorar)

### 🚀 Compilação e testes

1. ⚙️ Configure o projeto:

```bash
mkdir -p build 
cd build
cmake ..
```

**IMPORTANTE**: O diretório `build` e seu conteúdo não deve ser adicionado ao git. Para evitar adição acidental ele está no arquivo `.gitignore`.

  - Para ajuda do `cmake`:
```bash
cmake -h
```

2. 🔨 Compile:

```bash
cmake --build .  # ou 'make'
```

**Obs.:** Sempre que modificar um arquivo você deve recompilar com `cmake --build .` no diretório `build`.

3. 🧪 Testes:

- Para listar os testes disponíveis:
```bash
ctest -N
```

- Para executar todos os testes
```bash
ctest
```

- Para executar todos os testes com a palavra `EXPR` posse o parâmetro `-R EXPR`. Por exemplo, se você quiser executar todos os testes apenas para a
implementação com _Array_, digite:
```bash
ctest -R Array
```

  - Se quiser executar todos os testes da implementação com _Array_ do método **Push**:
```bash
ctest -R ArrayPush
```

  - E todos os testes de **PopBack** de ambas as implementações:
```bash
ctest -R Pop
```

  - Serve também para a listagem. Se quiser listar todos os testes com a palavra **Pop**:
```bash
ctest -N -R Pop
```

  - Para testes com relatório mais detalhado:
```bash
ctest --verbose
```

  - Caso algum teste falhe e você queira ver o teste mais em detalhes:
```bash
ctest -R ArrayPushBack01 --output-on-failure
```

Os testes de vazamento de memória usam a ferramenta `valgrind`, que produz 
um relatório detalhado do uso da memória. O teste está configurado 
para gerar o relatório no diretório `tests/tests_array` e `tests/tests_linked`
a partir do diretório de _build_. Os nomes dos arquivos começam com `valgrind....txt`


## 📝 Implementação
Implemente em `include/vector-lib/vector-array.hpp` e em `include/vector-lib/vector-linked.hpp` o vetor dinâmico implementado com _array_ e com lista duplamente ligada. 
O projeto consiste de biblioteca apenas de cabeçalho, _header-only lib_, então toda
a implementação deve ser nos arquivos `.hpp`. 

Não deve ser adicionado ou removido arquivos no diretório `include` e seus descendentes, assim como em nenhum outro diretório do projeto além do `tests_student`.  

### 🏗️ Implementação com _array_ dinâmico
Nesta implementação você deve usar um ponteiro para um _array_ estático alocado dinamicamente, `int *data`, e 2 atributos `unsigned int size_, capacity_`. `size_` armazena a quantidade de espaços usados efetivamente e `capacity_` armazena o tamanho da memória alocada. A área de memória deve ser um ponteiro pois a capacidade do _array_ deve ser aumentada quando o _array_ está completo `size_ == capacity_` e um novo elemento deve ser inserido. Um novo _array_ deve começar com capacidade `8` (oito) e duplica cada vez que precisar de mais.



### 🔗 Implementação com lista duplamente ligada

Nesta implementação os valores são armazenados em nós de uma lista duplamente ligada. 
O gerenciamento da memória é feito a cada operação no vetor, pois a memória 
usada e definida para cada um dos elementos. Nesse caso a capacidade será sempre 
igual ao tamanho do vetor. 


## 🧪 Testes

Todos os métodos devem ser implementados para se realizar todos os testes. Faz parte do trabalho garantir que todos os métodos são testados.

Será considerado como extra no trabalho a implementação de novos testes, 
com documentação adequada.


### ✅ O que será testado
- 🧩 Inicialização correta
- ➕ Adição/remoção de elementos
- 📏 Redimensionamento automático
- 🧠 Gerenciamento de memória


### 🧪 Ferramenta **ctest**

Alguns testes estão implementados usando o próprio **CMake**, através do **ctest**. 

Todas as implementações de testes estão no diretórios `tests`. A configuração de testes é feita no arquivo `CMakeLists.txt` do diretório `tests`. Não é necessário modificar este arquivo. 

### 🗂️ Arquivos de Teste
- `tests_array/` - 🏗️ Testes para implementação com array
- `tests_linked/` - 🔗 Testes para implementação com lista ligada
- `tests_student/` - ✍️ Testes do estudante (aqi você coloca seus testes)


Você pode implementar os testes como lhe for conveniente. Depois de implementar os testes é necessário recompilar o projeto com o comand `cmake --build` no diretório `build` antes de executar os testes com o `ctest`.

Seus testes devem ser implementados no diretório `tests_student`. Há um arquivo exemplo de como fazer um teste. O nome do arquivo será
o nome do teste na ferramenta `ctest`. 

**Importante:** Ao adicionar um novo arquivo fonte de testes você deve executar novamente o comando `cmake ../` no diretório `build`. 

## 💡 Dicas de Implementação

1. Comece implementando:
   1. ⚙️ Construtor (Alocação inicial: _capacity = 8_)
   1. 📏 _size()_ e _capacity()_
   1. ➕ _push_back()_ básico

Com estes testes deve ser possível passar o primeiro teste de `push_back`,
no arquivo `tests/tests_array/test_array_push_back.cpp`. Cada um dos testes
de `push_back` lê dos arquivos de entrada no diretório `tests/inputs`. 
O primeiro, `input-01.txt` possui um vetor com `5` elementos, 
o que deve ser suficiente para passar no primeiro teste sem a necessidade 
de redimensionamento da memória.

2. Os testes são feitos em ordem, e cada teste pode usar métodos 
implementados nos testes anteriores. Por isso é aconselhado 
usar a ordem a seguir:

   1. _increase\_capacity()_
   2. _push\_front()_
   3. _pop\_back()_
   4. _pop\_front()_
   5. _get\_at()_
   6. _insert\_at()_
   7. _remove\_at()_
   8. _clear()_
   9. _front()_
   10. _back()_
   11. _remove()_
   12. _find()_
   13. _count()_
   14. _sum()_

Os testes de vazamento de memória usando a maioria dos métodos. Caso 
a classe esteja implementada corretamente os testes de vazamento 
de memória devem passar também. 

## 🎁 **Novas Funcionalidades** 

1. 📉 Redução de memória

Depois de implementar e testar a classe completa você pode implementar a redução do 
espaço de memória (capacidade) quando o uso da memória for menor do que um quarto (`1/4`)
da capacidade. Estes eventos acontecem quando há remoção de elementos. Lembre-se 
também de manter a capacidade mínima de `8` elementos.

Deve ser também considerado a construção de testes desta funcionalidade. Use os arquivos de testes do estudante. Exemplo: Sempre depois de uma operação que altera a quantidade 
de elementos verificar que `capacidade>=tamanho` E `capacidade<=tamanho*4`. 

2. 🧹 Remoção de todas as ocorrências de um mesmo valor

Da forma que está implementado atualmente, a remoção usando o método `remove(x)` deve 
remover apenas a primeira ocorrência de `x`. Fica como sugestão a implementação 
de um método `remove_all(x)`, que remove todas as ocorrências de `x`. 
Faça testes que verificam o funcionamento correto do método. 

3. ✂️ Remoção de todos os elementos em uma faixa

Um método `remove_range(a, b)` que remove todos os elementos entre os índices 
`a` e `b`. Também faça testes que verifiquem o funcionamento correto.

4. 🔗 Inserção de um vetor no final de outro vetor. 

Um método em `v1` que recebe um outro vetor `v2` e insere todos os elementos de 
`v2` em `v1`.

## 🚀 Passos para submeter sua atividade

1. No terminal do Codespace, execute:
```bash
git add include/vector-lib/vector-array.hpp         # Informa que introducao.md entrará na próxima confirmação
git commit -m "Implementação do método push_back()" # Confirma atualização/inclusão
git push                                            # Envia todas as confirmações para o servidor
```

Os comandos do git podem ser feitos diretamente na interface visual do VSCode. Faça o que for mais conveniente para você. 

**Obs.:** Cada alteração em um arquivo deve ser seguida de um _commit_ com comentário adequado. A operação de _push_ deve ser feita quando você quiser enviar as alteração para o professor, normalmente depois de vários _commits_. 


## ✅ Critérios de Avaliação

1. Corretude (40%):
   - ✅ Passar em todos os testes automatizados
   - 🧠 Sem vazamentos de memória

2. Boas práticas (30%):
   - ✨ Código organizado e documentado
   - 📝 Alocação eficiente de memória
   - ⚡ Tratamento de casos especiais

3.  Novas funcionalidade (30%):
   - 🎁 Implementação das novas funcionalidades
   - 🧪 Testes extras implementados
   - ➕ Mais funcionalidades podem ser definidas, adicionadas, documentadas e testadas você. Serão levadas em consideração para a nota.

**Obs.:** não é permitido o uso de LLMs para geração de código. As LLMs podem ser usadas para consultas e compreensão. Caso haja algum código exibido por uma LLM você pode entendê-lo para construir seu próprio código.

## ⁉️ Dúvidas Frequentes
   1. ❓ Posso usar STL?
      - 👉 Não, exceto para estruturas básicas já usadas no esqueleto

   2. ❓ Como tratar índices inválidos?
      - 👉 Retorne false (operações) ou `-1` (consultas)
      - 👉 Pode-se implementar índices inválidos com exceções. Nesse caso deve haver alteração nos testes. Será considerado um extra no trabalho.

   3. ❓ Onde colocar testes extras?
      - 👉 No diretório `tests/tests_student`, com a extensão `.cpp`.

**Seja criativo!!!**


- [Documentação CMake](https://cmake.org/documentation/)
- [Referência C++](https://en.cppreference.com/)
- [Tutorial Containers](https://code.visualstudio.com/docs/remote/containers)
