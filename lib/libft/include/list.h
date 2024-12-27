/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:03:43 by caide-so          #+#    #+#             */
/*   Updated: 2024/12/26 01:15:47 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

/* @brief Adds the node 'new' at the end of the list.
 * 
 * @param lst the address of a pointer to the first node of a list
 * @param new the address of a pointer to the node to be added to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/* @brief Adds the node 'new' at the beginning of the list.
 * 
 * @param lst the address of a pointer to the first node of a list.
 * @param new the address of a pointer to the node to be added to the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/* @brief Deletes and frees the given node and every successor of that node,
 * using the function 'del' and frees it. Finally, the pointer to the list
 * must be set to NULL.
 * 
 * @param lst the address of a pointer to a node
 * @param del the address of the function used to delete the content
 * of the node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*));

/* @brief Takes as a parameter a node and frees the memory of the node’s
 * content using the function 'del' given as a parameter and free the node.
 * The memory of 'next' must not be freed.
 * 
 * @param lst the node to free
 * @param del 'he address of the function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/* @brief Iterates the list 'lst' and applies the function 'f' on the content 
 * of each node.

 * @param lst the address of a pointer to a node.
 * @param f the address of the function used to iterate on the list.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* @brief Returns the last node of the list.
 * 
 * @param lst the beginning of the list
 * @return Last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/* @brief Iterates the list 'lst' and applies the function 'f' on the content 
 * of each node. Creates a new list resulting of the successive applications 
 * of the function 'f'. The 'del' function is used to delete the content of a 
 * node if needed.
 *
 * @param lst the address of a pointer to a node.
 * @param f  the address of the function used to iterate on the list.
 * @param del the address of the function used to delete the content of a node 
 * if needed.
 * @return The new list. NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* @brief Allocates with malloc and returns a new node.
 * The member variable 'content' is initialized with the value of the parameter 
 * 'content'. The variable 'next' is initialized to NULL.
 * 
 * @param content the content to create the node with
 * @return The new node.
*/
t_list	*ft_lstnew(void *content);

/* @brief Counts the number of nodes in a list.
 * 
 * @param lst the beginning of the list
 * @return The length of the list.
*/
int		ft_lstsize(t_list *lst);

#endif
