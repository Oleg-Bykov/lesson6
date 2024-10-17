#include <stdio.h>
#define datatype int  //определяем тип данных в дереве
typedef struct tree     //определяем параметры структуры дерева(key типа инт и обозначем ветки лева, право и родителя(которе нигде не используется дальше))
{
    datatype key;
    struct tree *left, *right, *parent;
} tree;

void sum_tree(tree *root, tree *it)     
{
    static int sum = 0;
    if(root == NULL)        // проверяем есть ли вообще дерево
        return;
    sum+=root->key;         // сум присваиваем значение key из root
    if(root->left)          // если идя налево != 0, т.е. есть ветка, то идем налево
        sum_tree(root->left,it);        // записываем значения в функцию
    if(root->right)             // то же самое проверяем право
        sum_tree(root->right,it);
    if(it==root)            //выход из рекурсивной функции
    {
        printf("%d\n",sum);
        sum=0;
    }
}

/*int sum(tree *root)         // более простое и более понятное решение вместо sum_tree
{
	if(!root)
		return 0;
	return root->key + sum(root->left) + sum(root->right);
}
*/
int main(int argc, char ** argv)
{
    tree t[10]={0,0,0,0};       // создаем дерево

    t[0].left = t+1;
    t[0].right = t+2;
    t[0].key = 10;

    t[1].left = t+3;
    t[1].right = t+4;
    t[1].key = 5;
    t[1].parent = t + 0;

    t[2].left = t+5;
    t[2].right = t+6;
    t[2].key = 15;
    t[2].parent = t + 0;

    t[3].left = t+7;
    t[3].parent = t + 1;    
    t[3].key = 3;

    t[4].left = t+8;
    t[4].parent = t + 1;    
    t[4].key = 7;

    t[5].key = 13;
    t[5].parent = t + 2;    
    
    t[6].key = 18;
    t[6].parent = t + 2;

    t[7].key = 1;
    t[7].parent = t + 3;

    t[8].key = 6;
    t[8].parent = t + 4;   
 
    sum_tree(t,t);      // вызываем фукцию sum_tree. если поменяем на sum(t),которая выведет одно значение интовое 
    return 0;
}
