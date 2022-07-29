# Cross-Reference-Using-BinTrees-Research
Referência cruzada utilizando ABPs  (Árvore Binária de Pesquisa)
 
Descrição do problema:
Um dicionário pode ter um processo de busca de palavras otimizado se o armazenamento das palavras for realizado em uma árvore de pesquisa. A árvore de pesquisa vai reduzir o número de comparações realizadas na busca dos dados, uma vez que os mesmos foram inseridos de forma ordenada permitindo uma pesquisa binária. Para um número grande de palavras, essa otimização nas buscas pode melhorar ainda mais se forem utilizadas várias ABPs, cada uma para armazenar as palavras iniciadas por uma letra do alfabeto. 
O objetivo deste trabalho é implementar uma referência cruzada com as palavras de um texto.  Uma referência cruzada é uma relação ou vínculo semântico que se estabelece entre duas ou mais informações ou entre documentos. A referência cruzada a ser estabelecida é a contagem de cada palavra em um texto. As palavras do texto vão ser inseridas no dicionário, que é organizado através de um conjunto de ABPs, uma ABP por letra do alfabeto, tendo como critério de ordenação a ordem alfabética das palavras.
 
Representação das Estruturas de Dados
A entrada de dados é um texto (palavras separadas por espaços em branco). O texto a ser submetido à referência cruzada pode estar originalmente num arquivo (arquivo texto.txt), ou pode ser digitado pelo usuário. As palavras serão colocadas em uma lista de ABPs, separadas por letra inicial, com as seguintes características (ver figura abaixo):
1.	uma lista de letras (tabela hash), sendo que cada letra (cada item da tabela) referencia a ABP das palavras que começam com aquela letra. A lista de letras pode ser implementada como vetor ou como lista encadeada. Se for uma lista encadeada, pode conter apenas as letras que tem palavras associadas.
2.	ABPs para as palavras que começam por uma letra. Cada ABP é composta por nodos que contém as informações abaixo. Cada palavra tem 1 como menor número de ocorrências.

-	palavra
-	número de ocorrências daquela palavra no texto
-	referências para filhos da esquerda e da direita
 
![image](https://user-images.githubusercontent.com/85631998/181791109-d7ce601c-e05c-4c36-a2a7-a4a641ae2d39.png)

  
Detalhes da Implementação:
Pode ser implementado em C, C++, C#, Java ou Python, desde que as referências entre os nodos sejam manipuladas explicitamente pelo programa (não pode usar classe, método ou função pronta da linguagem nem para o hash nem para listas encadeadas, nem para a ABP).
Cada nodo deverá conter a palavra, número de ocorrências e as referências para os dois filhos, mas pode conter outras informações necessárias para a realização das operações.
A interface pode ser bem simples (textual), o importante é que as operações funcionem.
As operações obrigatórias a serem implementadas pelo programa são:
•	INSERE: permite a inserção de uma palavra do texto na ABP. Palavras não podem ser duplicadas, por isso contém também o número de ocorrências. Ao inserir uma palavra, seu número de ocorrências é inserido também. \n
•	CONSULTA: consulta uma palavra no dicionário, informando seu número de ocorrências. \n
•	REMOVE: remove uma palavra do dicionário, mantendo em ordem a ABP na qual ela estava situada.\n
•	CONTA: retorna o número total de palavras do dicionário.\n
•	CONTA_OCORRÊNCIAS: retorna o número total de ocorrências de todas as palavras (soma todos os contadores).\n
•	EXIBE_PALAVRAS: exibe a lista das palavras do dicionário (só as palavras, ou com os respectivos contadores, em ordem alfabética (de A a Z).\n
•	EXIBE_PALAVRAS_LETRA: exibe a lista das palavras do dicionário iniciadas por uma determinada letra (só as palavras ou com contadores), em ordem alfabética (de A a Z).\n
•	MAIOR_NRO_OCORRENCIAS: exibe a palavra (ou as palavras) com maior número de ocorrências.\n
•	UMA_OCORRENCIA: exibe, em ordem alfabética, as palavras que só tem uma ocorrência.\n
