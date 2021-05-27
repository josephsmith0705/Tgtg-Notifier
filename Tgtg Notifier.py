from tgtg import TgtgClient
import pgeocode
#import pycountry

def fetchData():
    email = input("Email address: ")
    password = input("Password: ")
    postcode = input("Postcode: ")

    geocode = pgeocode.Nominatim('gb') #Create an instance of pgeocode for Great Britain
    geoinfo = geocode.query_postal_code(postcode) #Query postcode in Great Britain to retrieve latitude and longitude data
    latitude = geoinfo['latitude']
    longitude = geoinfo['longitude']

    print("Connecting to",email,"with password:","Just kidding ;)")
    client = TgtgClient(email=email, password=password)

    command = input("Use command 'help' to print available commands\n\n").lower()
    running = True
    while running == True:
        if command == "help":
            print("all - Fetch a list of all stores\navailable - Fetch a list of available stores\nfav - Fetch a list of your favourite stores\nquit - Exit the program\n")
            command = input()
        elif command == "all":
            radius = input("How many miles radius should be scanned? ")
            displayAllData(client.get_items( #Pass list created by client.get_items 
                favorites_only=False,
                latitude = latitude,
                longitude = longitude,
                radius = radius))
            command = input()
        elif command == "available":
            radius = input("How many miles radius should be scanned? ")
            displayAvailableData(client.get_items( #Pass list created by client.get_items 
                favorites_only=False,
                latitude = latitude,
                longitude = longitude,
                radius = radius))
            command = input()
        elif command == "fav":
            favCommand = input("all - Fetch a list of all favourite stores\navailable - Fetch a list of available favourite stores\n\n")
            if favCommand == "all":
                displayAllData(client.get_items())
            elif favCommand == "available":
                displayAvailableData(client.get_items())
            else:
                print("Unrecognised command")
            command = input()
        elif command == "quit":
            running = False
        else:
            print("Unrecognised command")
            command = input()

def parsePrice(price, x):
    if x['item']['price']['code'] == "GBP":
        price = "£" + price
    elif x['item']['price']['code'] == "EUR":
        price = "€" + price
    elif x['item']['price']['code'] == "USD":
        price = "$" + price
    return price
    
def displayAvailableData(items):
    data = []
    for x in items:
        if x['items_available'] != 0:
            displayName = x['display_name']
            price = str(x['item']['price']['minor_units'])
            decimals = len(str(x['item']['price']['minor_units'])) - x['item']['price']['decimals'] 
            price = price[:decimals] + "." + price[decimals:] + " " + x['item']['price']['code']
            price = parsePrice(price, x) 
            data.append(displayName+" - "+price)
    if len(data) == 0:
        print("No stores currently available\n")
    else:
        print("\nAvailable stores: \n",data,"\n")

def displayAllData(items):
    data = []
    for x in items:
        displayName = x['display_name']
        price = str(x['item']['price']['minor_units'])
        decimals = len(str(x['item']['price']['minor_units'])) - x['item']['price']['decimals'] 
        price = price[:decimals] + "." + price[decimals:] + " " + x['item']['price']['code']
        price = parsePrice(price, x)
        availability = "available"
        if x['items_available'] == 0:
            availability = "sold out"
        data.append(displayName+" - "+price+" - "+availability)
    if len(data) == 0:
        print("No stores found\n")
    else:
        print("\n",data,"\n")
fetchData()


    
