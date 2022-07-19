import sys

def company_stock(string):
    COMPANIES = {
        'Apple': 'AAPL',
        'Microsoft': 'MSFT',
        'Netflix': 'NFLX',
        'Tesla': 'TSLA',
        'Nokia': 'NOK'
        }
    STOCKS = {
        'AAPL': 287.73,
        'MSFT': 173.79,
        'NFLX': 416.90,
        'TSLA': 724.88,
        'NOK': 3.37
        }
    ticker_symbol = {val:key for key,val in COMPANIES.items()}
    ticker = string.upper()
    company_name = string.lower().capitalize()
    if ticker in ticker_symbol:
        print(ticker,'is a ticker symbol for ',ticker_symbol[ticker])
    elif company_name in COMPANIES:
        val  = COMPANIES[company_name]
        print(company_name, 'stock price is', STOCKS[val])
    else:
        print(string.lower().capitalize(), 'is an unknown company or an unknown ticker symbol')
    

def all_stocks(string):
    new_string = string.replace(',' , ' , ').split()
    count_comma = new_string.count(',')
    if count_comma * 2 + 1 == len(new_string):
        for each in new_string:
            if each != ',':
                company_stock(each.strip(','))


if __name__ == '__main__':
    if len(sys.argv) == 2:
        all_stocks(sys.argv[1])
