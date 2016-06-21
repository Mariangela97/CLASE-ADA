#include "vEB.h"

vEB::vEB(int tam)
{
    u=tam;
    min=NULL;
    max=NULL;
    cout<<"creando el de "<<u<<endl;
    if (u>2)
    {
        int tam2=pow(tam,0.5);
        for (int i=0;i<tam;i=i+tam2)
        {
            cluster.push_back(new vEB(tam2));
        }
        summary=new vEB(tam2);
    }
}

int vEB::vEB_Tree_Minimum(vEB* V)
{
    return (V->min);
}

int vEB::vEB_Tree_Maximum(vEB* V)
{
    return (V->max);
}

int vEB::high(int x)
{
    return u/pow(u,0.5);
}

int vEB::low(int x)
{
    return x%int(pow(u,0.5));
}

int vEB::index(int x,int y)
{
    return x*pow(u,0.5)+y;
}


void vEB::vEB_Empty_Tree_insert(vEB* V, int x)
{
    V->min=x;
    V->max=x;
}

void vEB:: vEB_Tree_Insert(vEB* V, int x)
{
    if (V->min==NULL)
    {
        vEB_Empty_Tree_insert(V,x);
    }
    else
    {
        if(x<V->min)
        {
            int aux=V->min;
            V->min=x;
            x=aux;
        }
        if(V->u>2)
        {
            if ((vEB_Tree_Minimum(V->cluster[high(x)]))==NULL)
            {
                vEB_Tree_Insert(V->summary,high(x));
                vEB_Empty_Tree_insert(V->cluster[high(x)],low(x));
            }
        }
    }

}
bool vEB:: vEB_Tree_Member(vEB* V, int x)
{
    if (x == V.min or x == V.max)
        return true;
    else if (V.u == 2)
        return false;
    else return vEB_Tree_Member(V.cluster[high(x)],low(x));
}
int vEB:: vEB_Tree_Successor(vEB* V, int x)
{
    if (V.u == 2)
    {
        if (x == 0 and V.max == 1) return 1;
        else return NULL;
    }
    else if (V.min !=NULL and x < V.min) return V.min;

    else
    {
        max-low = vEB_Tree_Maximum(V.cluster[high(x)]);
        if (max-low != NULL and low(x) < max-low)
        {
            offset=vEB_Tree_Successor(V.cluster[high(x)],low(x));
            return index(high(x), offset);
        }
        else
        {
            succ_cluster=vEB_Tree_Successor(V.summary,high(x));
            if (succ_cluster == NULL)
                return NULL;

            else
            {
                offset=vEB_Tree_Minimum(V.cluster[succ_cluster]);
                return index(succ_cluster,offset);
            }
        }
    }
}
int vEB:: vEB_Tree_Predecessor(vEB* V, int x)
{
    if (V.u == 2)
    {
        if (x == 0 and V.max == 1) return 0;
        else return NULL;
    }
    else if (V.max !=NULL and x > V.max) return V.max;

    else
    {
        min-low = vEB_Tree_Minimum(V.cluster[high(x)]);
        if (min-low != NULL and low(x) > min-low)
        {
            offset=vEB_Tree_Predecessor(V.cluster[high(x)],low(x));
            return index(high(x), offset);
        }
        else
        {
            pred_cluster=vEB_Tree_Predecessor(V.summary,high(x));
            if (pred_cluster == NULL)
            {
                if( V.min!= NULL and x > V.min) return V.min;
                else return NULL;
            }
            else
            {
                offset=vEB_Tree_Maximum(V.cluster[pred_cluster]);
                return index(pred_cluster,offset);
            }
        }
    }
}

void vEB::print(vEB* V)
{
    for (i=0;i<u;i+i)
}

vEB::~vEB()
{
    //dtor
}
