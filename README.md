<h1> Lista Encadeada Em C</h1>
Uma implementação de lista encadeada na linguagem C.

<h2>Structs</h2>
<ul>
<li><i><code>struct linked_list</code></i></li>
Referida, por meio de <code>typedef</code>, como <code>llist</code> (abreviação para <i>linked list</i>), armazena a estrutura básica do elemento de uma lista, isto é, a informação principal que guarda (conteúdo) e um ponteiro para o próximo elemento.
</ul>

<h2>Funções</h2>
<ul>
<li><i><code>lcreate</code></i>(int add)</li>
Retorna um ponteiro para o primeiro elemento de uma nova lista encadeada. O primeiro elemento terá seu valor igual àquele passado como argumento. Novas listas podem ser criadas com <code>llist* nome = lcreate(valor);</code> 
<hr/>

<li><i><code>laddToStart</code></i> (llist** aList, int add)</code></li>
Adiciona um novo elemento ao início da lista encadeada. Seu primeiro parâmetro é o endereço do ponteiro usado para se referir à estrutura, enquanto o segundo é o inteiro que deve ser armazenado como elemento da lista. 
<hr/>

<li><i><code>linsert</code></i> (llist** aList, int index, int add)</code></li>
Insere um elemento de valor <i>add</i> na lista na posição indicada. 
<hr/>

<li><i><code>lerase</code></i> (llist** aList, int index)</code></li>
Apaga um elemento da lista (e da memória) numa posição <i>index</i>. O endereço dessa lista deve ser passado como argumento.
<hr/>

<li><i><code>lchange</code></i> (llist** aList, int index, int change)</code></li>
Altera o valor do elemento na posição <i>index</i> para <i>change</i>.
<hr/>

<li><i><code>lget</code></i> (llist* aList, int index)</code></li>
Por meio de uma busca linear, retorna o inteiro guardado na posição de índice <i>index</i> (segundo parâmetro) na lista. O primeiro parâmetro é o ponteiro referente ao início da lista. Retorna NULL caso o elemento não exista.
<hr/>

<li><i><code>lgetPointer</code></i> (llist* aList, int index)</code></li>
Retorna um ponteiro para o elemento na posição de índice <i>index</i> numa lista. Pode ser interessante para lidar com algum elemento a qualquer momento, mesmo após mudança de posição dentro da lista ou de valor. Isso porque o ponteiro retornado apontará para ele independentemente, com exceção nos casos em que o elemento foi apagado. Também pode ser usado como ponto de partida para a leitura de elementos posteriores na lista. Retorna NULL caso o elemento não exista.
<hr/>

<li><i><code>lprint</code></i> (llist* aList)</code></li>
Dado o ponteiro que aponta para o início da lista, imprime seu conteúdo no formato {a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, ..., a<sub>n</sub>}, com cada elemento a<sub>i</sub> numa lista de tamanho n.
<hr/>

<li><i><code>lfind</code></i> (llist* aList, int value)</code></li>
Retorna o índice (a posição) do primeiro elemento de valor <i>value</i> na lista. Caso ele não exista, retorna -1.
<hr/>

<li><i><code>lfindPointer</code></i> (llist* aList, int value)</code></li>
Retorna um ponteiro para o primeiro elemento de valor <i>value</i> na lista. Caso ele não exista, retorna um ponteiro NULL. Pode ser interessante para possibilitar a modificação do valor do elemento de forma direta, ou então para ler/modificar elementos posteriores a ele, sem a necessidade do uso de outras funções. Sua funcionalidade se assemelha à de <code>lgetPointer</code>.

</ul>
