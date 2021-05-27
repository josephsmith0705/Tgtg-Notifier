from tgtg import TgtgClient
import pgeocode
import time
#import pycountry

email = input("Email address: ")
password = input("Password: ")
client = TgtgClient(email=email, password=password)

def fetchData():

    postcode = input("Postcode: ")
    geocode = pgeocode.Nominatim('gb') #Create an instance of pgeocode for Great Britain
    geoinfo = geocode.query_postal_code(postcode) #Query postcode in Great Britain to retrieve latitude and longitude data
    latitude = geoinfo['latitude']
    longitude = geoinfo['longitude']

    command = input("Use command 'help' to print available commands\n\n").lower()
    running = True
    while running == True:
        if command == "help":
            print("all - Fetch a list of all stores\navailable - Fetch a list of available stores\nfav - Fetch a list of your favourite stores\nsubscribe - Subscribe to a store\nquit - Exit the program\n")
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
        elif command == "subscribe":
            radius = input("How many miles radius should be scanned? ")
            subscribe(client.get_items( #Pass list created by client.get_items 
                favorites_only=False,
                latitude = latitude,
                longitude = longitude,
                radius = radius))
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

def subscribe(items):
    import time
    i = 0
    for x in items:
        print(str(i)+": "+x['display_name'])
        i=i+1
    userStore = int(input("Select a store number to subscribe to "))
    oldItem = items[userStore]
    updateFrequency = int(input("How frequently should the program update? (Seconds) "))
    subscribeLoop(oldItem, updateFrequency)
    
def subscribeLoop(oldItem, updateFrequency):
    subscribe = True
    starttime=time.time() 
    while subscribe == True:
        print("Updating...")
        item = client.get_item(item_id=oldItem['item']['item_id'])
        if oldItem['items_available'] != item['items_available']:
            print(item['display_name'],"now has",item['items_available'],"available")
        oldItem = item
        time.sleep(updateFrequency - ((time.time() - starttime) % updateFrequency))

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


    
