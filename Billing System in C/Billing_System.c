#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cin = 0, cpn = 0, pbn = 0, sbn = 0, prn = 0, z;

struct item
{
    char name[100];
    int hsnc;
    float taxrate;
    double cost;
    int inven;
} * in[1000], *tempi;
struct party
{
    char name[100];
    char gstin[10];
    char add[100];
    double outstanding;
    int creditlim;
} * pn[1000], *tempp;
struct Transaction
{
    int day;
    int month;
    int year;
    int parn;
    struct item *itn[50];
    int qua[50];
    double bas[50];
    double netb;
    double nett;
    double neta;
    double cashpay;
    double cred;
    int cascre;
    int i;
    struct Transaction *next;
} *fp = NULL, *lp = NULL, *temp, *fs = NULL, *ls = NULL, *temp1;
struct payment
{
    int day;
    int month;
    int year;
    int parn;
    double neta;
    struct payment *next;
} * f, *l, *tem, *tem1;
void addit();
void delit();
void disit();
void addpa();
void delpa();
void dispa();
void addtrans();
void addpur();
void addsale();
void delpur();
void delsale();
void dispur();
void dissale();
void pribill(struct Transaction *a);
void modit();
void modpa();
void priprof();
void gst();
void cash();
void addpay();
void delpay();
void dispay();
void pripay(struct payment *a);
void addit()
{
    if (cin > 1000)
    {
        printf("Item List Full!!!\n");
        return;
    }
    char name[100];
    int hsnc;
    float taxrate;
    double cost;
    int inven;
    printf("Enter item name:-");
    scanf("%s", name);
    printf("Enter item hsn:-");
    scanf("%d", &hsnc);
    printf("Enter item taxrate:-");
    scanf("%f", &taxrate);
    printf("Enter item cost:-");
    scanf("%lf", &cost);
    printf("Enter item stock:-");
    scanf("%d", &inven);
    while (inven < 0)
    {
        printf("Item cannot be negative!!!\nPlease reenter:-");
        scanf("%d", &inven);
    }
    tempi = (struct item *)malloc(sizeof(struct item));
    strcpy(tempi->name, name);
    tempi->hsnc = hsnc;
    tempi->taxrate = taxrate;
    tempi->cost = cost;
    tempi->inven = inven;
    in[cin++] = tempi;
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void delit()
{
    int i, x, a;
    if (cin == 0)
    {
        printf("No Items to delete!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    printf("Enter item number to be deleted:-");
    scanf("%d", &x);
    while (x > cin - 1 || x < 0)
    {
        printf("Item does not Exist!!!!\nPlease Reenter:-");
        scanf("%d", &x);
    }
    if (in[x]->inven != 0)
    {
        printf("The item you are about to delete is still in stock!!!\nAre you sure you want to continue?[1/0]:-");
        scanf("%d", &a);
        if (!a)
            return;
    }
    tempi = in[x];
    for (i = x; i < cin; i++)
    {
        in[i] = in[i + 1];
    }
    in[cin--] = NULL;
    printf("The item deleted is :-\nItem Number:-%d\nItem Name:-%s\nItem HSN Code:-%d\nItem Tax Rate:-%f\nItem Cost:-Rs.%lf\nItem Stock:-%d\n", x, tempi->name, tempi->hsnc, tempi->taxrate, tempi->cost, tempi->inven);
    free(tempi);
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void disit()
{
    if (cin == 0)
    {
        printf("No items to display!!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    printf("Item No\tItem Name\tItem HSN code\tItem Tax Rate\tItem cost\tItem Stock\n");
    for (int i = 0; i < cin; i++)
    {
        printf("%d\t%s\t%d\t%f\t%lf\t%d\n", i, in[i]->name, in[i]->hsnc, in[i]->taxrate, in[i]->cost, in[i]->inven);
    }
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void addpa()
{
    if (cpn > 1000)
    {
        printf(" party list Full!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    char name[100];
    char gstin[14];
    char add[100];
    double outstanding;
    int creditlim;
    printf("Enter Party`s name:-");
    scanf("%s", name);
    printf("Enter Party`s GSTIN:-");
    scanf("%s", gstin);
    printf("Enter Party`s Address:-");
    scanf("%s", add);
    printf("Enter Party`s Outstanding amount(-ive if sundry Creditor):-");
    scanf("%lf", &outstanding);
    printf("Enter party`s limit:-");
    scanf("%d", &creditlim);
    tempp = (struct party *)malloc(sizeof(struct party));
    strcpy(tempp->name, name);
    strcpy(tempp->gstin, gstin);
    strcpy(tempp->add, add);
    tempp->outstanding = outstanding;
    tempp->creditlim = creditlim;
    pn[cpn++] = tempp;
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void delpa()
{
    int i, x, a;
    if (cpn == 0)
    {
        printf("Party list is empty\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    printf("Enter party number to be deleted:-");
    scanf("%d", &x);
    while (x > cpn - 1 || x < 0)
    {
        printf("Party does not Exist!!!!\nPlease Reenter:-");
        scanf("%d", &x);
    }
    if (pn[x]->outstanding != 0)
    {
        printf("The party you are about to delete has still outstanding amount!!!\nAre you sure you want to continue?[1/0]:-");
        scanf("%d", &a);
        if (!a)
            return;
    }
    tempp = pn[x];
    for (i = x; i < cpn; i++)
    {
        pn[i] = pn[i + 1];
    }
    in[cpn--] = NULL;
    printf("The party deleted is :-\nParty Number:-%d\nParty Name:-%s\nParty GSTIN:-%s\nParty address:-%s\nParty Outstanding:-Rs.%lf\nParty Credit Limit:-Rs.%d\n", x, tempp->name, tempp->gstin, tempp->add, tempp->outstanding, tempp->creditlim);
    free(tempp);
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void dispa()
{
    if (cpn == 0)
    {
        printf("No items to display!!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    printf("Party No\tParty Name\tParty GSTIN\tParty Address\tParty Outstanding\tParty Credit Limit\n");
    for (int i = 0; i < cpn; i++)
    {
        printf("%d\t%s\t%s\t%s\t%lf\t%d\n", i, pn[i]->name, pn[i]->gstin, pn[i]->add, pn[i]->outstanding, pn[i]->creditlim);
    }
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void addtrans()
{
    int day;
    int month;
    int year;
    int parn;
    struct item *itn[50];
    int qua[50];
    double bas[50], sp;
    double netb = 0;
    double nett = 0, neta;
    double cashpay;
    double cred;
    int cascre, i = 0, x = 0, n, ps;
    printf("Enter the date of transaction in dd mm yy:-");
    scanf("%d %d %d", &day, &month, &year);
    printf("Enter 0 for sale and 1 for purchase:-");
    scanf("%d", &ps);
    printf("Enter Party Number:-");
    scanf("%d", &parn);
    while (parn > cpn - 1 || parn < 0)
    {
        printf("Party does not exist!!Please Reenter:-");
        scanf("%d", &parn);
    }
    while (1)
    {
    a:
        printf("Enter the item number to add:-");
        scanf("%d", &n);
        while (n > cin - 1 || x < 0)
        {
            printf("Item does not exist!!Please Reenter:-");
            scanf("%d", &n);
        }
        printf("Enter selling price for item(exGST):-Rs.");
        scanf("%lf", &sp);
        if ((sp < in[n]->cost) && !ps)
        {
            printf("Selling Price is less than Cost!!!\nLoss will be incurred!!!\nAre you sure you want to continue?[1/0]:-");
            scanf("%d", &x);
            if (!x)
                goto a;
        }
        printf("Enter Quantity:-");
        scanf("%d", &qua[i]);
        while ((in[i]->inven < qua[i]) && !ps)
        {
            printf("Not enough Quantity in !!!!Please Reenter quantity:-");
            scanf("%d", &qua[i]);
        }
        itn[i] = in[n];
        bas[i] = sp * qua[i];
        netb += sp * qua[i];
        nett += sp * in[n]->taxrate * qua[i++] / 100;
        printf("Do you want to add more items?[1/0]:-");
        scanf("%d", &x);
        if (!x)
            break;
        if (i == 50)
        {
            printf("Maximum no items exceeded!!\n");
            break;
        }
    }
    neta = netb + nett;
    printf("Total amount billed=Rs.%lf\n", neta);
    printf("Enter amount paid in cash=Rs.");
    scanf("%lf", &cashpay);
    cred = neta - cashpay;
    if (cred == 0)
        cascre = 1;
    else
        cascre = 0;
    if (!ps && (pn[parn]->creditlim < (cred + pn[parn]->outstanding)))
    {
        printf("Party outstanding more than credit limit!!!! Do you wish to continue?[1/0]:-");
        scanf("%d", &x);
        if (!x)
            return;
    }
    temp = (struct Transaction *)malloc(sizeof(struct Transaction));
    temp->day = day;
    temp->month = month;
    temp->year = year;
    temp->parn = parn;
    for (int j = 0; j < i; j++)
    {
        temp->itn[j] = itn[j];
        temp->bas[j] = bas[j];
        temp->qua[j] = qua[j];
    }
    temp->i = i;
    temp->netb = netb;
    temp->neta = neta;
    temp->nett = nett;
    temp->cashpay = cashpay;
    temp->cred = cred;
    temp->cascre = cascre;
    temp->next = NULL;

    if (ps)
        addpur();
    else
        addsale();
    pn[parn]->outstanding += (ps * -1 * cred);
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void addpur()
{
    if (fp == NULL && lp == NULL)
        fp = lp = temp;
    else
    {
        lp->next = temp;
        lp = temp;
    }
    pbn++;
    pribill(temp);
}
void addsale()
{
    if (fs == NULL && ls == NULL)
        fs = ls = temp;
    else
    {
        ls->next = temp;
        ls = temp;
    }
    sbn++;
    pribill(temp);
}
void delpur()
{
    int x, i;
    if (fp == NULL && lp == NULL)
    {
        printf("No bills to delete!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    dispur();
    printf("Enter the Bill no to be deleted:-");
    scanf("%d", &x);
    if (x > pbn || x < 0)
    {
        printf("Bill does not exist!!!\n");
        return;
    }
    if (pbn == 1)
    {
        temp = fp;
        fp = lp = NULL;
    }
    else
    {
        temp1 = fp;
        for (i = 1; i < x; i++)
            temp1 = temp1->next;
        temp = temp1->next;
        temp1->next = temp->next;
    }
    pbn--;
    printf("The Bill deleted is :-\n");
    pribill(temp);
    free(temp);
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void delsale()
{
    int x, i;
    if (fs == NULL && ls == NULL)
    {
        printf("No bills to delete!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    dissale();
    printf("Enter the Bill no to be deleted:-");
    scanf("%d", &x);
    if (x > pbn || x < 0)
    {
        printf("Bill does not exist!!!\n");
        return;
    }
    if (sbn == 1)
    {
        temp = fs;
        fs = ls = NULL;
    }
    else
    {
        temp1 = fs;
        for (i = 1; i < x; i++)
            temp1 = temp1->next;
        temp = temp1->next;
        temp1->next = temp->next;
    }
    sbn--;
    printf("The Bill deleted is :-\n");
    pribill(temp);
    free(temp);
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void dispur()
{
    if (fp == NULL && lp == NULL)
    {
        printf("No bills to display!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    temp = fp;
    int i = 1;
    printf("No\tDate\tParty\tAmount\n");
    while (temp != NULL)
    {
        printf("%d\t%d-%d-%d\t%s\t%lf\n", i, temp->day, temp->month, temp->year, pn[temp->parn]->name, temp->neta);
        temp = temp->next;
        i++;
    }
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void dissale()
{
    if (fs == NULL && ls == NULL)
    {
        printf("No bills to display!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    temp = fs;
    int i = 1;
    printf("No\tDate\tParty\tAmount\n");
    while (temp != NULL)
    {
        printf("%d\t%d-%d-%d\t%s\t%lf\n", i, temp->day, temp->month, temp->year, pn[temp->parn]->name, temp->neta);
        temp = temp->next;
        i++;
    }
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void pribill(struct Transaction *a)
{
    printf("---------------------------------------------------------------------------\n");
    printf("Party Details:-\nName:-%s\nGSTIN:-%s\nAddress:-%s\n", pn[a->parn]->name, pn[a->parn]->gstin, pn[a->parn]->add);
    printf("---------------------------------------------------------------------------\n");
    printf("Item No\tItem Name\tItem HSN code\tItem Tax Rate\tItem cost\tQuantity\tBasic amount\n");
    for (int j = 0; j < a->i; j++)
    {
        printf("%d\t%s\t%d\t%f%%\tRs.%lf\t%d\tRs.%lf\n", j, a->itn[j]->name, a->itn[j]->hsnc, a->itn[j]->taxrate, a->itn[j]->cost, a->qua[j], a->bas[j]);
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Total Basic amount=Rs.%lf\nTotal tax=Rs.%lf\nTotal amount=Rs.%lf\n", a->netb, a->nett, a->neta);
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
}
void modit()
{
    int x, c;

    if (cin == 0)
    {
        printf("No Items to modify!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    printf("Enter item number to be modified:-");
    scanf("%d", &x);
    while (x > cin - 1 || x < 0)
    {
        printf("Item does not Exist!!!!\nPlease Reenter:-");
        scanf("%d", &x);
    }
    tempi = (struct item *)malloc(sizeof(struct item));
    printf("Item name is %s\n Do you want to modify it?[1/0]:-", in[x]->name);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new name:-");
        scanf("%s", tempi->name);
    }
    else
    {
        strcpy(tempi->name, in[x]->name);
    }
    printf("Item hsn code is %d\n Do you want to modify it?[1/0]:-", in[x]->hsnc);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new hsn:-");
        scanf("%d", &tempi->hsnc);
    }
    else
    {
        tempi->hsnc = in[x]->hsnc;
    }
    printf("Item taxrate is %f\n Do you want to modify it?[1/0]:-", in[x]->taxrate);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new taxrate:-");
        scanf("%f", &tempi->taxrate);
    }
    else
    {
        tempi->taxrate = in[x]->taxrate;
    }
    printf("Item cost is %lf\n Do you want to modify it?[1/0]:-", in[x]->cost);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new cost:-");
        scanf("%lf", &tempi->cost);
    }
    else
    {
        tempi->cost = in[x]->cost;
    }
    printf("Item inventory is %d\n Do you want to modify it?[1/0]:-", in[x]->inven);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new inventory:-");
        scanf("%d", &tempi->inven);
    }
    else
    {
        tempi->inven = in[x]->inven;
    }
    free(in[x]);
    in[x] = tempi;
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void modpa()
{
    int x, c;
    if (cpn == 0)
    {
        printf("Party list is empty\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    printf("Enter party number to be modified:-");
    scanf("%d", &x);
    while (x > cpn - 1 || x < 0)
    {
        printf("Party does not Exist!!!!\nPlease Reenter:-");
        scanf("%d", &x);
    }

    tempp = (struct party *)malloc(sizeof(struct party));
    printf("Party name is %s\n Do you want to modify it?[1/0]:-", pn[x]->name);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new name:-");
        scanf("%s", tempp->name);
    }
    else
    {
        strcpy(tempp->name, pn[x]->name);
    }
    printf("Party GSTIN is %s\n Do you want to modify it?[1/0]:-", pn[x]->gstin);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new GSTIN:-");
        scanf("%s", tempp->gstin);
    }
    else
    {
        strcpy(tempp->gstin, pn[x]->gstin);
    }
    printf("Party Address is %s\n Do you want to modify it?[1/0]:-", pn[x]->add);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new address:-");
        scanf("%s", tempp->add);
    }
    else
    {
        strcpy(tempp->add, pn[x]->add);
    }
    printf("Party Outstanding is Rs.%lf\n Do you want to modify it?[1/0]:-", pn[x]->outstanding);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new Outstanding amount:-Rs.");
        scanf("%lf", &tempp->outstanding);
    }
    else
    {
        tempp->outstanding = pn[x]->outstanding;
    }
    printf("Party Credit Limit is Rs.%d\n Do you want to modify it?[1/0]:-", pn[x]->creditlim);
    scanf("%d", &c);
    if (c)
    {
        printf("Enter new Credit-Limit:-Rs.");
        scanf("%d", &tempp->creditlim);
    }
    else
    {
        tempp->creditlim = pn[x]->creditlim;
    }
    free(pn[x]);
    pn[x] = tempp;
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void priprof()
{
    double pi, tp = 0;
    int i = 0;
    temp = fs;
    if (fs == NULL && ls == NULL)
    {
        printf("No sales Record Exists!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    printf("---------------------------------------------------------------------------\n");
    printf("No\tparty\tamount\tprofit\n");
    while (temp != NULL)
    {
        pi = 0;
        for (int j = 0; j < temp->i; j++)
        {
            pi += (temp->bas[j]) - (temp->itn[j]->cost) * (temp->qua[j]);
        }
        tp += pi;
        printf("%d\t%s\tRs.%lf\tRs.%lf\n", i, pn[temp->parn]->name, temp->neta, pi);
        temp = temp->next;
        i++;
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Total Profit Made=Rs%lf\n", tp);
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void gst()
{
    double gstp = 0, gsts = 0, gst = 0;
    int i = 0;
    temp = fp;
    printf("-----------Purchase Records----------\n");
    if (fp == NULL && lp == NULL)
    {
        printf("No Purchase Record Exists!!!\n");
    }
    else
    {
        printf("---------------------------------------------------------------------------\n");
        printf("No\tparty\tamount\ttax\n");
        while (temp != NULL)
        {
            printf("%d\t%s\tRs.%lf\tRs.%lf\n", i, pn[temp->parn]->name, temp->neta, temp->nett);
            gstp += temp->nett;
            temp = temp->next;
        }
        printf("---------------------------------------------------------------------------\n");
    }
    temp = fs;
    printf("-----------Sale Records----------\n");
    if (fs == NULL && ls == NULL)
    {
        printf("No Sale Record Exists!!!\n");
    }
    else
    {
        printf("---------------------------------------------------------------------------\n");
        printf("No\tparty\tamount\ttax\n");
        while (temp != NULL)
        {
            printf("%d\t%s\tRs.%lf\tRs.%lf\n", i, pn[temp->parn]->name, temp->neta, temp->nett);
            gsts += temp->nett;
            temp = temp->next;
        }
        printf("---------------------------------------------------------------------------\n");
    }
    gst = gsts - gstp;
    printf("Total Input GST=Rs%lf\n", gstp);
    printf("Total Output GST=Rs%lf\n", gsts);
    printf("Net GST Payable=Rs%lf\n", gstp);
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void cash()
{
    double cashp = 0, cashs = 0, cash = 0;
    int i = 0;
    temp = fp;
    printf("-----------Purchase Records----------\n");
    if (fp == NULL && lp == NULL)
    {
        printf("No Purchase Record Exists!!!\n");
    }
    else
    {
        printf("---------------------------------------------------------------------------\n");
        printf("No\tparty\tamount\tCash\n");
        while (temp != NULL)
        {
            printf("%d\t%s\tRs.%lf\tRs.%lf\n", i, pn[temp->parn]->name, temp->neta, temp->cashpay);
            cashp += temp->cashpay;
            temp = temp->next;
        }
        printf("---------------------------------------------------------------------------\n");
    }
    temp = fs;
    printf("-----------Sale Records----------\n");
    if (fs == NULL && ls == NULL)
    {
        printf("No Sale Record Exists!!!\n");
    }
    else
    {
        printf("---------------------------------------------------------------------------\n");
        printf("No\tparty\tamount\ttax\n");
        while (temp != NULL)
        {
            printf("%d\t%s\tRs.%lf\tRs.%lf\n", i, pn[temp->parn]->name, temp->neta, temp->cashpay);
            cashs += temp->cashpay;
            temp = temp->next;
        }
        printf("---------------------------------------------------------------------------\n");
    }
    cash = cashs - cashp;
    printf("Total Cash Inflow=Rs.%lf\n", cashs);
    printf("Total Cash Outflow=Rs.%lf\n", cashp);
    printf("Net Cash in Register=Rs.%lf\n", cash);
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void addpay()
{
    int day;
    int month;
    int year;
    int parn;
    double neta;
    printf("Enter the date of payment in dd mm yy:-");
    scanf("%d %d %d", &day, &month, &year);
    printf("Enter Party Number:-");
    scanf("%d", &parn);
    while (parn > cpn)
    {
        printf("Party does not exist!!Please Reenter:-");
        scanf("%d", &parn);
    }
    printf("Enter amount paid (-ve if recieved):-");
    scanf("%lf", &neta);
    pn[parn]->outstanding += neta;
    tem = (struct payment *)malloc(sizeof(struct payment));
    tem->day = day;
    tem->month = month;
    tem->year = year;
    tem->parn = parn;
    tem->neta = neta;
    if (f == NULL && l == NULL)
        f = l = tem;
    else
    {
        l->next = tem;
        l = tem;
    }
    prn++;
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void delpay()
{
    int x, i;
    if (f == NULL && l == NULL)
    {
        printf("No Payments to delete!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    dispay();
    printf("Enter the Payment no to be deleted:-");
    scanf("%d", &x);
    if (x > prn)
    {
        printf("Payment does not exist!!!\n");
        return;
    }
    if (prn == 1)
    {
        tem = f;
        f = l = NULL;
    }
    else
    {
        tem1 = f;
        for (i = 1; i < x; i++)
            tem1 = tem1->next;
        tem = tem1->next;
        tem1->next = tem->next;
    }
    prn--;
    printf("The Payment deleted is :-\n");
    pripay(tem);
    free(tem);
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void dispay()
{
    if (f == NULL && l == NULL)
    {
        printf("No Payments to display!!!\n");
        printf("Press any key to continue\n");
        scanf("%d", &z);
        return;
    }
    tem = f;
    int i = 1;
    printf("No\tDate\tParty\tAmount\n");
    while (tem != NULL)
    {
        printf("%d\t%d-%d-%d\t%s\t%lf\n", i, tem->day, tem->month, tem->year, pn[tem->parn]->name, tem->neta);
        tem = tem->next;
        i++;
    }
    printf("Press any key to continue\n");
    scanf("%d", &z);
}
void pripay(struct payment *a)
{
    printf("---------------------------------------------------------------------------\n");
    printf("Party Details:-\nName:-%s\nGSTIN:-%s\nAddress:-%s\n", pn[a->parn]->name, pn[a->parn]->gstin, pn[a->parn]->add);
    printf("---------------------------------------------------------------------------\n");
    printf("Total amount paid=Rs.%lf\n", a->neta);
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
}
void main()
{
    int m, n, o;
    while (1)
    {
    h:
        system("clear");
        printf("---------------------------------------------------------------------------\n");
        printf("-----------------------------Billing Software------------------------------\n");
        printf("---------------------------------------------------------------------------\n");
        printf("----------------------------------Menu-------------------------------------\n");
        printf("---------------------------------------------------------------------------\n");
        printf("1.Administration\n2.Add bills\n3.Add Payments\n4.Reports\n5.About\n6.Exit\n");
        printf("---------------------------------------------------------------------------\n");
        printf("Enter your choice:-");
        scanf("%d", &m);
    k:
        system("clear");
        switch (m)
        {
        case 1:
        b:
            printf("---------------------------------------------------------------------------\n");
            printf("-----------------------------Administration--------------------------------\n");
            printf("---------------------------------------------------------------------------\n");
            printf("1.Item\n2.Party\n3.Bills\n4.Payments\n5.Back\n6.Exit\n");
            printf("---------------------------------------------------------------------------\n");
            printf("Enter your choice:-");
            scanf("%d", &n);
        i:

            system("clear");
            switch (n)
            {
            case 1:
                printf("---------------------------------------------------------------------------\n");
                printf("------------------------------------Item-----------------------------------\n");
                printf("---------------------------------------------------------------------------\n");
                printf("1.Add Item\n2.Modify Item\n3.Delete Item\n4.Back\n5.Exit\n");
                printf("---------------------------------------------------------------------------\n");
                printf("Enter your choice:-");
                scanf("%d", &o);
            c:
                system("clear");
                switch (o)
                {
                case 1:
                    addit();
                    break;
                case 2:
                    modit();
                    break;
                case 3:
                    delit();
                    break;
                case 4:
                    goto b;
                    break;
                case 5:
                    exit(0);
                default:
                    while (o > 5 || o <= 0)
                    {
                        printf("Wrong Choice !!!!Please Renter:-");
                        scanf("%d", &o);
                    }
                    goto c;
                }
                break;
            case 2:
                printf("---------------------------------------------------------------------------\n");
                printf("------------------------------------Party----------------------------------\n");
                printf("---------------------------------------------------------------------------\n");
                printf("1.Add Party\n2.Modify Party\n3.Delete Party\n4.Back\n5.Exit\n");
                printf("---------------------------------------------------------------------------\n");
                printf("Enter your choice:-");
                scanf("%d", &o);
            d:
                system("clear");
                switch (o)
                {
                case 1:
                    addpa();
                    break;
                case 2:
                    modpa();
                    break;
                case 3:
                    delpa();
                    break;
                case 4:
                    goto b;
                    break;
                case 5:
                    exit(0);
                default:
                    while (o > 5 || o <= 0)
                    {
                        printf("Wrong Choice !!!!Please Renter:-");
                        scanf("%d", &o);
                    }
                    goto d;
                }
                break;
            case 3:
                printf("---------------------------------------------------------------------------\n");
                printf("------------------------------------Bills-----------------------------------\n");
                printf("---------------------------------------------------------------------------\n");
                printf("1.Add Bill\n2.Delete Sales \n3.Delete Purchase\n4.Back\n5.Exit\n");
                printf("---------------------------------------------------------------------------\n");
                printf("Enter your choice:-");
                scanf("%d", &o);
            e:
                system("clear");
                switch (o)
                {
                case 1:
                    addtrans();
                    break;
                case 2:
                    delsale();
                    break;
                case 3:
                    delpur();
                    break;
                case 4:
                    goto b;
                    break;
                case 5:
                    exit(0);
                default:
                    while (o > 5 || o <= 0)
                    {
                        printf("Wrong Choice !!!!Please Renter:-");
                        scanf("%d", &o);
                    }
                    goto e;
                }
                break;
            case 4:
                printf("---------------------------------------------------------------------------\n");
                printf("----------------------------------Payment----------------------------------\n");
                printf("---------------------------------------------------------------------------\n");
                printf("1.Add Payment\n2.Delete Payment\n3.Back\n4.Exit\n");
                printf("---------------------------------------------------------------------------\n");
                printf("Enter your choice:-");
                scanf("%d", &o);
            g:
                system("clear");
                switch (o)
                {
                case 1:
                    addpay();
                    break;
                case 2:
                    delpay();
                    break;
                case 3:
                    goto b;
                    break;
                case 4:
                    exit(0);
                default:
                    while (o > 4 || o <= 0)
                    {
                        printf("Wrong Choice !!!!Please Renter:-");
                        scanf("%d", &o);
                    }
                    goto g;
                }
                break;
            case 5:
                goto h;
                break;
            case 6:
                exit(0);
            default:
                while (n > 6 || n <= 0)
                {
                    printf("Wrong Choice !!!!Please Renter:-");
                    scanf("%d", &n);
                }
                goto i;
            }
            break;
        case 2:
            addtrans();
            break;
        case 3:
            addpay();
            break;
        case 4:
        j:
            printf("---------------------------------------------------------------------------\n");
            printf("----------------------------------Reports--------------------------------------\n");
            printf("---------------------------------------------------------------------------\n");
            printf("1.View Sales\n2.View Purchases\n3.View Items\n4.View Parties\n5.View Payments\n6.Profit/Loss\n7.Net Gst Payable\n8.Cash in Register\n9.Back\n10.Exit\n");
            printf("---------------------------------------------------------------------------\n");
            printf("Enter your choice:-");
            scanf("%d", &n);
            system("clear");
            switch (n)
            {
            case 1:
                dissale();
                break;
            case 2:
                dispur();
                break;
            case 3:
                disit();
                break;
            case 4:
                dispa();
                break;
            case 5:
                dispay();
                break;
            case 6:
                priprof();
                break;
            case 7:
                gst();
                break;
            case 8:
                cash();
                break;
            case 9:
                goto h;
            case 10:
                exit(0);
            default:
                while (n > 10 || n <= 0)
                {
                    printf("Wrong Choice !!!!Please Renter:-");
                    scanf("%d", &n);
                }
                goto j;
            }
            break;
        case 5:
            printf("---------------------------------------------------------------------------\n");
            printf("----------------------------------About------------------------------------\n");
            printf("---------------------------------------------------------------------------\n");
            printf("This project is created as part of DSA Mini Project to be submitted to Visvesvaraya Technological University as 3rd semester B.E. Project.\n");
            printf("Team Members:-\n1.Uttam Bindal\n2.Shreyansh Gupta\n3.Vishal Arora\n");
            printf("We hereby certify no part of this this project has been reproduced in any form and every part of the source code is wriiten by us.\n");
            printf("---------------------------------------------------------------------------\n");
            printf("Press any to go back\n");
            scanf("%d", &o);
            goto h;
            break;
        case 6:
            exit(0);
        default:
            while (m > 6 || m <= 0)
            {
                printf("Wrong Choice !!!!\nPlease Renter:-");
                scanf("%d", &m);
            }
            goto k;
        }
    }
}
