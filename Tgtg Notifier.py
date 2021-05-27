from tgtg import TgtgClient
import pgeocode
import pycountry

def fetchData():
    email = input("Email address: ")
    password = input("Password: ")
    postcode = input("Postcode: ")
    radius = input("How many miles radius should be scanned? ")

    geocode = pgeocode.Nominatim('gb')
    geoinfo = geocode.query_postal_code(postcode)
    latitude = geoinfo['latitude']
    longitude = geoinfo['longitude']

    print("Connecting to",email,"with password:","Just kidding ;)\n")
    client = TgtgClient(email=email, password=password)

    displayData(client.get_items(
        favorites_only=False,
        latitude = latitude,
        longitude = longitude,
        radius = 10))

def parsePrice(price, x):
    if x['item']['price']['code'] == "GBP":
        price = "£" + price
    elif x['item']['price']['code'] == "EUR":
        price = "€" + price
    elif x['item']['price']['code'] == "USD":
        price = "$" + price
    return price
    
def displayData(items):
    for x in items:
        displayName = x['display_name']
        price = str(x['item']['price']['minor_units'])
        decimals = len(str(x['item']['price']['minor_units'])) - x['item']['price']['decimals'] 
        price = price[:decimals] + "." + price[decimals:] + " " + x['item']['price']['code']
        price = parsePrice(price, x) 
        availablity = "available"
        if x['items_available'] == 0:
            availability = "sold out"
        if availability == "sold out":
            print (displayName,"-",price)

fetchData()


    
