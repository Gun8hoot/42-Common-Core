

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

// int main(void)
// {
// 	t_list *aaa;
// 	t_list *bbb;
// 	t_list *ccc;

// 	aaa = malloc(sizeof(t_list));
// 	bbb = malloc(sizeof(t_list));
// 	ccc = malloc(sizeof(t_list));
// 	aaa->content = "zzz";
// 	bbb->content = "bbb";
// 	bbb->content = "iii";

// 	aaa->next = bbb;
// 	bbb->next = ccc;
// 	ccc->next = NULL;

//     size_t sz = ft_lstsize(aaa);

//     free(aaa);
//     free(bbb);
//     free(ccc);

// 	printf("sz %ld\n", sz);
// }