from bs4 import BeautifulSoup
import requests

PRODUCT_URI = input("Enter product url: ")
price = 0


def get_product_price(url):
    response = requests.get(
        url,
        headers={
            "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36"
        },
    )
    soup = BeautifulSoup(response.text, "lxml")
    available = soup.find("div", {"id": "availability"})
    if available is not None:
        if "Currently unavailable." in available.text:
            print("Product is currently unavailable.")
            return False
    price_parent = soup.find(
        "span", {"class": "a-price a-text-price a-size-medium apexPriceToPay"}
    )
    if price_parent is not None:
        price = price_parent.text.split("₹")[1]
        print("Price: ₹", price)
    return True


get_product_price(PRODUCT_URI)
