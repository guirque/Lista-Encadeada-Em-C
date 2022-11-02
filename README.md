<h1> Lista Encadeada Em C</h1>
Uma implementação de lista encadeada na linguagem C.

<h2>Structs</h2>
<ul>
<li><i><code>struct linked_list</code></i></li>
Referida, por meio de <code>typedef</code>, como <code>llist</code> (abreviação para <i>linked list</i>), armazena a estrutura básica do elemento de uma lista, isto é, a informação principal que guarda (conteúdo) e um ponteiro para o próximo elemento.
</ul>

<h2>Funções</h2>
<ul>
<li><i><code>lcreate</code></i></li>
Retorna um ponteiro para o primeiro elemento de uma nova lista encadeada. Novas listas podem ser criadas com <code>llist* nome = lcreate();</code> 
<hr/>

<li><i><code>laddToStart</code></i> (llist** aList, int add)</code></li>
Adiciona um novo elemento ao início da lista encadeada. Seu primeiro parâmetro é o endereço do ponteiro usado para se referir à estrutura, enquanto o segundo é o inteiro que deve ser armazenado como elemento da lista. 
<hr/>

<li><i><code>lget</code></i> (llist* aList, int index)</code></li>
Por meio de uma busca linear, retorna o inteiro guardado na posição de índice <i>index</i> (segundo parâmetro) na lista. O primeiro parâmetro é o ponteiro referente ao início da lista. 

</ul>
