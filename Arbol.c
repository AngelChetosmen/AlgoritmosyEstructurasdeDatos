/*
Autor: AngelChetosmen
Consultar la Licencia del Autor | Derechos Reservados EUVA B&T ©
*/
#include <stdio.h>

int complete_node = 15;

char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

// funcion para determinar el padre
int get_parent(int index)
{
    if (tree[index] != '\0' && index > 1 && index <= complete_node)
        return index / 2;
    return -1;
}

int get_right_child(int index)
{

    if (tree[index] != '\0' && ((2 * index) + 1) <= complete_node)
        return (2 * index) + 1;
    return -1;
}

int get_left_child(int index)
{
    if (tree[index] != '\0' && (2 * index) <= complete_node)
        return 2 * index;

    return -1;
}

void preorder(int index)
{

    if (index > 0 && tree[index] != '\0')
    {
        printf(" %c ", tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}

void postorder(int index)
{

    if (index > 0 && tree[index] != '\0')
    {
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %c ", tree[index]);
    }
}

void inorder(int index)
{

    if (index > 0 && tree[index] != '\0')
    {
        inorder(get_left_child(index));
        printf(" %c ", tree[index]);
        inorder(get_right_child(index));
    }
}

int is_leaf(int index)
{

    if (!get_left_child(index) && !get_right_child(index))
        return 1;

    if (tree[get_left_child(index)] == '\0' && tree[get_right_child(index)] == '\0')
        return 1;
    return 0;
}

int get_max(int a, int b)
{
    return (a > b) ? a : b;
}

int get_height(int index)
{

    if (tree[index] == '\0' || index <= 0 || is_leaf(index))
        return 0;

    return (get_max(get_height(get_left_child(index)), get_height(get_right_child(index))) + 1);
}

int main()
{
    inorder(1);
    printf("\n");
    preorder(1);
    printf("\n");
    postorder(1);
    printf("\n %d", get_height(1));
    return 0;
}
