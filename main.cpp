#include <bits/stdc++.h>
using namespace std;
#define quickie                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define div2(a) (!(a & 1))
#define deb(x) cout << "\n" \
                    << (#x) << " : " << (x) << "\n";
#define newl cout << "\n"

struct node
{
    int val;
    node *rchild;
    node *lchild;
    node(int key) : val(key), rchild(0), lchild(0) {}
};
node *root = 0;



node *succ(node *key)
{
    if (key->rchild)
    {
        node *l = key->rchild;
        if (l->lchild)
        {
            while (l->lchild)
            {
                l = l->lchild;
            }
            return l;
        }
        return 0;
    }
    return 0;
}

node *pred(node *key)
{
    if (key->lchild)
    {
        node *r = key->lchild;
        if (r->rchild)
        {
            while (r->rchild)
            {
                r = r->rchild;
            }
            return r;
        }
        return 0;
    }
    return 0;
}



void insert(node *p, int key)
{
    if (p)
        if (p->val < key)
        {
            if (!p->rchild)
                p->rchild = new node(key);
            else
                insert(p->rchild, key);
        }
        else if (p->val > key)
        {
            if (!p->lchild)
                p->lchild = new node(key);
            else
                insert(p->lchild, key);
        }
        else
        {
            cout << " error!\nkey " << key << " exists already";
            newl;
        }
}

void insert(int key)
{
    if (!root)
    {
        root = new node(key);
    }
    else
    {
        insert(root, key);
    }
}



void print(node *temp)
{
    if (temp)
    {
        cout << temp->val << " ";
        print(temp->rchild);
        print(temp->lchild);
    }
}






int main()
{
    quickie;
    insert(30);
    insert(40);
    insert(35);
    insert(33);
    insert(34);
    print(root);
    node *s = pred(root->rchild->lchild->lchild);

    if (s){
        deb(s->val);
    }else
        cout << "\nthere is no predesser\n";
    return 0;
}