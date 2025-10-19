
#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list lst;

    lst.content = content;
    lst.next    = NULL;
    return (&lst);
}

int main(void)
{
    t_list *qqq;

    qqq = ft_lstnew("fdfd");
    printf("%s\n\n%s", qqq->content, qqq->next);
    return (0);
}