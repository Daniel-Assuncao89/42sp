Esse projeto foi criado como parte do currículo da 42 por dassunca

# Descrição/Description
 	Esse projeto tem o objetivo de ensinar principios de projeto, além de como criar e usar sua própria biblioteca.

# Instruções/Instructions
	Clone o projeto com git clone.
	Utilize o comando "make" dentro da pasta clonada para gerar a biblioteca, inclua nos seus arquivos o *#include* do "libft.h" para utilizar as funções disponiveis na biblioteca. Compile seus arquivos adicionando a libft.a
	
# Fontes/Resources
	GNU-LINUX - MAKEFILE https://www.gnu.org/software/make/#documentation
	Functions documentations - man pages
	IA foi utilizada para simular testes extremos para o código.
	
# Descrição detalhada da biblioteca
	Parte 1
		- ft_isalpha
			- int ft_isalpha(int c);
		- ft_isdigit
			- int ft_isdigit(int c);
		- ft_isalnum
			- int ft_isalnum(int c);
		- ft_isascii
			- int ft_isascii(int c);
		- ft_isprint
			- int ft_isprint(int c);
		- ft_strlen
			- int ft_strlen(int c);
		- ft_memset
			- void *ft_memset(void *s, int c, size_t n);
			- preenche os primeiros n bytes da memoria apontada por 's' com a constante 'c'
		- ft_bzero
			- void ft_bzero(void *s, size_t n);
			- apaga a data dentro do n bytes da memoria.
		- ft_memcpy
			- void *memcpy(void *dest, const void *src, size_t n);
			- copia n bytes da memoria, da area 'src' para area 'dest'. Retorna um ponteiro do 'dest'.
		- ft_memmove
			- void *memmove(void *dest, const void *src, size_t n);
			- copia n bytes da memoria area 'src' para a memoria 'dest' sem sobrepor 'src' ou 'dest'.
		- ft_strlcpy
			- ft_strlcpy(char *dst, const char *src, size_t size);
			- Copia string de src para dst, garantindo o null terminator.
		- ft_strlcat
			- ft_strlcat(char *dst, const char *src, size_t size);
			- Concatena a string de src para dst, garantindo null terminator.
		- ft_toupper
			- int ft_toupper(int c);
			- Retorna o uppercase equivalente
		- ft_tolower
			- int ft_tolower(int c);
			- Retorna o lowecase equivalente
		- ft_strchr
			- char *ft_strchr(const char *s, int c);
			- retorna um ponteiro para primeira ocorrencia do caracter 'c'
		- ft_strrchr
			- char *ft_strrchr(const char *s, int c);
			- retorna um ponteiro para ultima ocorrencia de 'c'
		- ft_strncmp
			- int ft_strncmp(const char *s1, const char *s2, size_t n);
			- compara 'n' caracters da string s1 e s2.
		- ft_memchr
			- void *ft_memchr(const void *s, int c, size_t n);
			- escaneia os primeiros n bytes da memoria apontada por s pela primeira instancia de c.
		- ft_memcmp
			- int ft_memcmp(const void *s1, const void *s2, size_t n);
			- compara os primeiros n bytes da area de memoria de s1 e s2.
		- ft_strnstr
			- char *ft_strnstr(const char *big, const char *little, size_t len);
			- localiza a primeira ocorrencia de 'little' (com null terminator) dentro da string 'big'
		- ft_atoi
			- int ft_atoi(const char *nptr);
			- converte a parte inicial de uma string nptr para int.
		- ft_calloc
			- void *ft_calloc(size_t nmemb, size_t size);
			- função aloca size bytes e retorna um ponteiro para a memoria alocada.
		- ft_strdup
			- char *strdup(const char *s);
			- retorna um ponteiro para uma nova string que é a duplicação da sring s.

	Parte 2
		- ft_substr
			- char *ft_substr(char const *s, unsigned int start, size_t len);
			- retorna substring da string 's'
		- ft_strjoin
			- char *ft_strjoin(char const *s1, char const *s2);
			- concatena s1 e s2 e retorna uma nova string
		- ft_strtrim
			- char *ft_strtrim(char const *s1, char const *set);
			- remove o 'set' do inicio e do fim da string 's1'.
		- ft_split
			- char **ft_split(char const *s, char c);
			- Retorna um array de strings obtido a partir da separação do 's' utilizando o caracter 'c' como delimitador. O array termina com um ponteiro NULL.
		- ft_itoa
			- char *ft_itoa(int n);
			- retorna uma string representando o inteiro recebido como argumento. Números negativos devem ser tratados.
		- ft_strmapi
			- char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
			- Aplica a função ponteiro 'f' em cada caracter da string 's'. Retorna uma nova string que armazena o resultado das sucessivas aplicações de 'f'.
		- ft_striteri
			- void ft_striteri(char *s, void (*f)(unsigned int, char*));
			- Aplica a função 'f' em cada caracter da string passada como argumento.
		- ft_putchar_fd
			- void ft_putchar_fd(char c, int fd);
			- Exibe o caracter 'c' no arquivo file descriptor especificado.
		- ft_putstr_fd
			- void ft_putstr_fd(char *s, int fd);
			- Exibe a string 's' no arquivo file descriptor especificado
		- ft_putendl_fd
			- void ft_putendl_fd(char *s, int fd);
			- Exibe a string 's' seguida por uma nova linha no arquivo file descriptor especificado
		- ft_putnbr_fd
			- void ft_putnbr_fd(int n, int fd);
			- exibe o integer 'n' no arquivo especificado no file descriptor.

	Parte 3
		- ft_lstnew
			- t_list *ft_lstnew(void *content);
			- Retorna um novo nó, inicializado com o conteudo de 'content' e o next inicializado com 'NULL'
		- ft_lstadd_front
			- void ft_lstadd_front(t_list **lst, t_list *new);
			- adiciona um novo nó no começo da lista.
		- ft_lstsize
			- int ft_lstsize(t_list *lst);
			- conta o número de nós na lista encadeada.
		- ft_lstlast
			- t_list *ft_lstlast(t_list *lst);
			- retorna o ultimo nó da lista
		- ft_lstadd_back
			- void ft_lstadd_back(t_list **lst, t_list *new);
			- adiciona o novo nó no final da lista.
		- ft_lstdelone
			- void ft_lstdelone(t_list *lst, void (*del)(void*));
			- pega o nó como parametro e libera o conteudo usando a função del. Libera o nó passado, mas não libera o próximo nó.
		- ft_lstclear
			- void ft_lstclear(t_list **lst, void (*del)(void *));
			- deleta e libera o nó dado e todos os seus sucessores usando a função 'del'
		- ft_lstiter
			- void ft_lstiter(t_list *lst, void (*f)(void *));
			- itera pela lista e aplica a funcao 'f' ao conteudo de cada nó.
		- ft_lstmap
			- t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
			- itera pela lista 'lst', aplica a funcao 'f' em cada conteudo do nó e cria uma nova lista com o resultado da sucessiva aplicação de 'f'.
