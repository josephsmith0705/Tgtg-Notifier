from tgtg import TgtgClient

email = input("Email address: ")
password = input("Password: ")

print("Connecting to",email,"with password:","Just kidding ;)\n")
client = TgtgClient(email=email, password=password)

items = client.get_items()

for x in items:
    displayName = x['display_name']
    price = str(x['item']['price']['minor_units'])
    decimals = x['item']['price']['decimals']
    decimals = len(price) - decimals
    price = price[:decimals] + "." + price[decimals:] + " " + x['item']['price']['code']
    if x['item']['price']['code'] == "GBP":
        price = "£" + price
    elif x['item']['price']['code'] == "EUR":
        price = "€" + price
    elif x['item']['price']['code'] == "USD":
        price = "$" + price
    availablity = "available"
    if x['items_available'] == 0:
        availability = "sold out"
    print (displayName,"-",price,"-",availability)
    
