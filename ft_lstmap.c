#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmp;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newcontent = (*f)(lst->content);
		tmp = ft_lstnew(newcontent);
		if (!tmp)
		{
			del(newcontent);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, tmp);
		lst = lst->next;
	}
	return (newlist);
}
