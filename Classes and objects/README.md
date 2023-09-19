# Classes e objetos em C++

## *sobre Classes e Objetos*

Em C++, as classes são estruturas que permitem definir objetos. Uma classe é uma entidade que encapsula dados e funções relacionadas. Os objetos são instâncias das classes, ou seja, são criados a partir das classes.

As classes permitem organizar e estruturar o código de forma mais modular e orientada a objetos. Elas podem conter atributos, que representam as características dos objetos, e métodos, que são as funções que podem ser executadas pelos objetos.

Ao criar um objeto a partir de uma classe, ele herda todas as propriedades e comportamentos definidos na classe. Isso permite que os objetos tenham seu próprio estado e comportamento, tornando-os independentes.

No C++, a definição de uma classe é feita utilizando a palavra-chave `class`, seguida pelo nome da classe e seu conteúdo entre chaves. Os atributos e métodos são declarados dentro da classe.

Para criar um objeto, basta declarar uma variável do tipo da classe. Por exemplo, se tivermos uma classe chamada `Carro`, podemos criar um objeto chamado `meuCarro` da seguinte forma: `Carro meuCarro;`.

Os objetos podem ser utilizados para acessar os atributos e invocar os métodos definidos na classe. Por exemplo, podemos acessar o atributo `cor` do objeto `meuCarro` utilizando a sintaxe `meuCarro.cor` e invocar o método `acelerar()` utilizando a sintaxe `meuCarro.acelerar()`.

Em resumo, as classes e objetos em C++ permitem a criação de estruturas de dados mais complexas e organizadas, fornecendo uma abordagem orientada a objetos para o desenvolvimento de programas.

### Exemplo de classe:

```cpp
#include <iostream>

// Definindo uma classe chamada 'MinhaClasse'
class MinhaClasse {
public:
    // Construtor da classe
    MinhaClasse() {
        std::cout << "Construtor chamado!" << std::endl;
    }

    // Destrutor da classe
    ~MinhaClasse() {
        std::cout << "Destrutor chamado!" << std::endl;
    }

    // Método público da classe
    void MeuMetodo() {
        std::cout << "Método da classe chamado!" << std::endl;
    }

private:
    // Membro privado da classe
    int meuMembroPrivado;
};

int main() {
    // Criando um objeto da classe 'MinhaClasse'
    MinhaClasse objeto;

    // Chamando o método público da classe
    objeto.MeuMetodo();

    return 0;
}
```

## *Sobre métodos:*

Existem diferentes tipos de métodos em C++. Além dos métodos de acesso e modificação que vimos no exemplo, também existem os métodos construtores e destrutores.

O método construtor é responsável por inicializar os atributos do objeto quando ele é criado. No exemplo, temos dois construtores na classe Pessoa: um construtor padrão sem parâmetros e um construtor parametrizado que recebe o nome e a idade da pessoa.

O método destrutor é responsável por liberar os recursos alocados pelo objeto quando ele é destruído. No exemplo, não temos um destrutor definido explicitamente, mas o compilador do C++ gera um destrutor padrão.

Além disso, é possível definir outros métodos na classe para realizar diferentes operações ou funcionalidades específicas. Os métodos podem ter parâmetros e retornar valores, como o método `exibirInformacoes()` no exemplo, que exibe as informações da pessoa.

Os métodos podem ser invocados utilizando a sintaxe `nomeDoObjeto.nomeDoMetodo()`. Por exemplo, no código do exemplo, estamos invocando o método `exibirInformacoes()` nos objetos `pessoa1` e `pessoa2 para exibir suas informações na saída.

Os métodos são uma parte fundamental das classes e objetos em C++, permitindo a manipulação dos atributos e a execução de operações relacionadas a eles.

## *Destrutores e construtores:*

Os construtores são métodos especiais que são chamados automaticamente quando um objeto é criado a partir de uma classe. Eles são usados para inicializar os atributos do objeto. No exemplo, vimos a implementação de um construtor padrão e um construtor parametrizado na classe Pessoa.

Os destrutores, por sua vez, são métodos especiais que são chamados automaticamente quando um objeto é destruído. Eles são usados para liberar recursos alocados pelo objeto. No exemplo, não temos um destrutor definido explicitamente, mas o compilador do C++ gera um destrutor padrão.

## *setters e getters:*

O uso de setters e getters é uma prática recomendada em programação orientada a objetos, pois ajuda a manter o encapsulamento dos dados, tornando mais fácil implementar lógica de validação e evitar que dados sejam acessados ou modificados de maneira não autorizada.

- Exemplo de setter:

```cpp
class Pessoa {
private:
    std::string nome;

public:
    // Setter para atribuir um nome
    void setNome(std::string novoNome) {
        // Lógica de validação ou manipulação de dados, se necessário
        nome = novoNome;
    }
};
```

## *Exemplo de divisão de arquivos .h e .cpp:*

Em projetos maiores, é comum dividir a definição da classe em um arquivo de cabeçalho (.h) e a implementação dos métodos em um arquivo de código (.cpp). Isso ajuda a organizar o código e separar a interface da implementação. No exemplo, vemos a definição da classe Pessoa no arquivo Pessoa.h e a implementação dos métodos no arquivo Pessoa.cpp.

### arquivo .h

```cpp
#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
public:
    // Construtor padrão
    Pessoa();

    // Construtor parametrizado
    Pessoa(const std::string& nome, int idade);

    // Métodos de acesso
    std::string getNome() const;
    int getIdade() const;

    // Métodos de modificação
    void setNome(const std::string& novoNome);
    void setIdade(int novaIdade);

    // Método para exibir informações da pessoa
    void exibirInformacoes() const;

private:
    std::string nome;
    int idade;
};

#endif
```

### Arquivo .cpp:

```cpp
#include "Pessoa.h"
#include <iostream>

// Implementação do construtor padrão
Pessoa::Pessoa() : nome(""), idade(0) {}

// Implementação do construtor parametrizado
Pessoa::Pessoa(const std::string& nome, int idade) : nome(nome), idade(idade) {}

// Implementação do método de acesso para o nome
std::string Pessoa::getNome() const {
    return nome;
}

// Implementação do método de acesso para a idade
int Pessoa::getIdade() const {
    return idade;
}

// Implementação do método de modificação para o nome
void Pessoa::setNome(const std::string& novoNome) {
    nome = novoNome;
}

// Implementação do método de modificação para a idade
void Pessoa::setIdade(int novaIdade) {
    idade = novaIdade;
}

// Implementação do método para exibir informações da pessoa
void Pessoa::exibirInformacoes() const {
    std::cout << "Nome: " << nome << ", Idade: " << idade << " anos" << std::endl;
}
```

# *Herança,encapsulamento e polimorfismo:*

### Resumo sobre:

Em C++, a herança, o encapsulamento e o polimorfismo são conceitos importantes na programação orientada a objetos.

A herança permite que uma classe herde características e comportamentos de outra classe, chamada classe base ou superclasse. Isso possibilita a reutilização de código e a criação de hierarquias de classes. Por exemplo, uma classe "Cachorro" pode herdar da classe "Animal", obtendo assim todos os atributos e métodos da classe "Animal".

O encapsulamento é o princípio de esconder os detalhes de implementação de uma classe e fornecer uma interface para acessar e manipular seus atributos e métodos. Isso ajuda a proteger os dados e a garantir a consistência do estado do objeto. Por exemplo, uma classe "ContaBancaria" pode ter atributos privados como "saldo" e métodos públicos como "sacar" e "depositar" para manipular o saldo de forma segura.

O polimorfismo permite que objetos de diferentes classes sejam tratados de maneira uniforme, através do uso de ponteiros ou referências de tipos mais genéricos. Isso possibilita a criação de código mais flexível e modular, onde diferentes classes podem responder de maneira diferente a uma chamada de método. Por exemplo, se tivermos uma classe "Forma" e suas subclasses "Circulo" e "Retângulo", podemos tratar objetos dessas classes de forma polimórfica ao chamarmos um método "calcularArea( )", onde cada classe implementa esse método de acordo com suas próprias regras.

Esses conceitos são fundamentais na programação em C++ e permitem a criação de código mais limpo, modular e flexível.

- A herança permite que uma classe herde características e comportamentos de outra classe, possibilitando a reutilização de código e a criação de hierarquias de classes.
- O encapsulamento permite esconder os detalhes de implementação de uma classe e fornecer uma interface para acessar e manipular seus atributos e métodos, garantindo a proteção dos dados e a consistência do estado do objeto.
- O polimorfismo permite que objetos de diferentes classes sejam tratados de maneira uniforme, através do uso de ponteiros ou referências de tipos mais genéricos, possibilitando a criação de código mais flexível e modular.

Esses conceitos são fundamentais na programação em C++ e permitem a criação de código mais organizado, reutilizável e flexível.