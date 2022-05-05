typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

int cmp(void *a, void *b)
{
	/*...*/
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current; //현재
	t_list	*prev; //이전
	t_list	*next; //다음

	current = *begin_list; //current가 Head를 가리켜
	prev = ((void *)0); //일단 널 가리키도록 초기화. 선언만하고 초기화안하면 if문에서 쓰레기값이 읽힘
	while (current)
	{
		next = current->next; //next가 B가리키게 저장해둠 //next가 C 가리키게 저장해둠
		if (cmp(current->data, data_ref) == 0) //일치하면 current가 가리키는 노드 삭제할거임
		{
			if (prev) //처음에 널이라 else로 넘어감 //prev가 A가리키니까 if문 진입
				prev->next = current->next; // //A의 next는 B였는데 B의 next인 C로 변경. B 없앨 준비
			else    //첫번째 노드에서 일치했을 경우에만 이 else문으로 진입함.
				*begin_list = current->next; //Head가 B를 가리키게 함.
			free(current); //current가 가리키던 A를 free, free직후 current에 쓰레기값 들어있음 //이후 동일하게 B를 free
			current = ((void *)0); //또 밑에 prev에 대입할 때 쓰레기값 들어가는거 방지해서 0이 들어있도록
		}
		prev = current; //A 없앴으면 널가리킴, A 패스했으면 A가 이전으로 넘겨짐
		current = next; // current에 위에서 저장해둔 B를 담음. :다음 노드로 넘어가 현재 노드로 해서 보겠다(i++)
	}
}

int main()
{
  char a = 'a';
  char b = 'b';
  char c = 'c';

	t_list A, B, C;
	
	A->next = &B;
	A->data = &a;
	
	B->next = &C;
	B->data = &b;
	
	C->next = ((void *)0);
	C->data = &c;
	
	t_list* Head = &A;

	ft_list_remove_if(&Head, &a, cmp);
}
