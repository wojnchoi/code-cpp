#include<iostream>

using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE=price;
        numOfApples=num;
        myMoney=money;
    }
    int SaleApples(int money)
    {
        if(money < 0)
        {
            cout<<"gaesujak no no"<<endl;
        }
        int num=money/APPLE_PRICE;
        numOfApples -=num;
        myMoney+=money;
        return num;
    }
    void ShowSalesResult() const
    {
        cout<<"remain apple: "<<numOfApples<<endl;
        cout<<"profit: "<<myMoney<<endl;
    }
};

class FruitBuyer
{
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money)
    {
        myMoney=money;
        numOfApples=0;
    }
    void BuyApples(FruitSeller &seller,int money)
    {
        if(money < 0)
        {
            cout<<"gaesujak no no"<<endl;
        }
        numOfApples+=seller.SaleApples(money);
        myMoney-=money;
    }
    void ShowBuyResult() const
    {
        cout<<"current money: "<<myMoney<<endl;
        cout<<"apple number: "<<numOfApples<<endl<<endl;
    }
};

int main()
{
    FruitSeller seller;
    seller.InitMembers(1000,20,0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller,2000);

    cout<<"apple seller: "<<endl;
    seller.ShowSalesResult();

    cout<<"apple buyer: "<<endl;
    buyer.ShowBuyResult();
    return 0;
}